import fs from 'node:fs/promises';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {execFileSync} from 'node:child_process';
import {Workbook, SpreadsheetFile} from '@oai/artifact-tool';

const root=process.argv[2]??fileURLToPath(new URL('../..',import.meta.url));
const output=process.argv[3]??path.resolve(root,'../outputs/translation-review-20261026');
await fs.mkdir(output,{recursive:true});
const catalog=JSON.parse(await fs.readFile(`${root}/localization/catalog.json`,'utf8'));
const glossary=JSON.parse(await fs.readFile(`${root}/localization/glossary.json`,'utf8'));
const commit=execFileSync('git',['rev-parse','HEAD'],{cwd:root,encoding:'utf8'}).trim();
const translated=catalog.filter(r=>r.status==='translated');
if(new Set(translated.map(r=>r.id)).size!==translated.length) throw Error('Translation ID mismatch');
const sourceCache=new Map();
function definition(row){
  if(row.target) return row.target;
  if(!sourceCache.has(row.file)) sourceCache.set(row.file,execFileSync('git',['show',`23be896714:${row.file}`],{cwd:root,encoding:'utf8'}));
  return [...sourceCache.get(row.file).slice(0,row.start).matchAll(/^([A-Za-z0-9_]+):+/gm)].at(-1)?.[1]??'';
}
function category(row){
  if(row.file.includes('/pokemon/species_info/')) return row.target?.includes('.description') ? '図鑑説明' : row.target?.includes('.categoryName') ? '図鑑分類' : 'ポケモン名';
  if(row.file==='src/data/moves_info.h') return row.target?.includes('.description') ? '技説明' : '技名';
  if(row.file==='src/data/abilities.h') return row.target?.includes('.description') ? '特性説明' : '特性名';
  if(row.file==='src/data/items.h') return /\.(name|pluralName)\[/.test(row.target??'') ? '道具名' : '道具説明';
  if(row.file==='src/data/types_info.h') return 'タイプ';
  if(row.file==='src/option_menu.c') return '設定';
  if(row.file==='src/wot_randomizer_menu.c') return 'ランダマイザー設定';
  if(row.file==='src/pokemon_storage_system.c') return 'ボックス';
  if(row.file==='src/naming_screen.c') return '名前入力案内';
  if(row.file==='src/party_menu.c'||row.file==='src/data/party_menu.h') return '手持ち';
  if(row.file==='src/pokemon_summary_screen.c') return 'ステータス';
  if(row.file.includes('pokedex')) return '図鑑UI';
  if(row.file==='src/item_menu.c'||row.file==='src/item_use.c') return 'バッグ・道具使用';
  if(row.file==='data/text/save.inc') return 'セーブ';
  if(row.file==='src/data/speaker_names.h') return '話者名';
  if(row.file==='src/battle_message.c') return '戦闘メッセージ';
  if(row.file.startsWith('data/maps/')) return `会話・看板（${row.file.split('/')[2]}）`;
  if(row.file.startsWith('data/scripts/')||row.file.startsWith('data/text/')&&row.file!=='data/text/save.inc') return '共通会話';
  if(row.file==='src/main_menu.c'||row.file==='src/main_menu_bw.c') return '開始メニュー';
  if(row.file==='src/start_menu.c'||row.target?.startsWith('gText_Menu')) return 'スタートメニュー';
  if(row.file==='src/data/script_menu.h') return 'スクリプト選択肢';
  if(row.file==='src/quest_toast.c') return 'クエスト通知';
  if(row.file==='src/quests.c') return 'クエスト画面';
  if(row.target?.startsWith('gText_QuestLoc_')) return '地名';
  if(row.target?.includes('Quest')) return 'クエストの目的・状態';
  return '共通UI';
}
function readable(text){
  return text.replace(/\{(?:JPN|ENG)\}/g,'').replace(/\{(?:COLOR|SHADOW|BACKGROUND|TEXT_COLORS) [^}]*\}/g,'').replace(/\$$/,'')
    .replace(/\\n/g,'\n').replace(/\\p/g,'\n［改ページ］\n').replace(/\\l/g,'\n［スクロール］\n');
}
const rows=translated.map((r,i)=>[i+1,category(r),readable(r.source),readable(r.translation),'',r.id,definition(r),`${r.file}:${r.line}`,r.translation,r.source]);
const wb=Workbook.create();
const sheet=wb.worksheets.add('翻訳一覧');
const terms=wb.worksheets.add('用語辞書');
const navy='#243A53', ink='#1C2D40', muted='#5F6F7D';
function base(s,end){
  s.showGridLines=false;
  s.getRange(end).format.font={name:'Arial',size:11,color:ink};
  s.getRange(end).format.verticalAlignment='top';
  s.getRange('A2').format.font={name:'Arial',size:16,bold:true,color:navy};
  s.getRange('A2:J2').format.rowHeight=32;
  s.tabColor=navy;
}
base(sheet,`A1:J${rows.length+7}`);
sheet.getRange('A2').values=[['Wishes of Tomorrow　日本語訳一覧']];
sheet.getRange('A3').values=[[`翻訳適用済み ${translated.length.toLocaleString('en-US')}件　2026年10月26日時点`]];
sheet.getRange('A4').values=[['原文・訳文の出典: localization/catalog.json　コミット '+commit.slice(0,10)+' + 作業ツリーの訳文']];
sheet.getRange('A5').values=[['［改ページ］・［スクロール］を明示しています。確認メモは自由に記入できます。']];
sheet.getRange('A6').values=[['表示確認・通しプレイは未完了です。メモの記入だけではゲームに反映されません。']];
sheet.getRange('A3:J6').format.font.color=muted;
sheet.getRange('A7:J7').values=[['No.','区分','英語原文','日本語訳','確認メモ','ID','定義名','原文の出典','日本語訳（制御コード付き）','英語原文（制御コード付き）']];
sheet.getRange(`A8:J${rows.length+7}`).values=rows;
const table=sheet.tables.add(`A7:J${rows.length+7}`,true,'Translations');
table.style='TableStyleMedium2'; table.showFilterButton=true;
sheet.getRange('A7:J7').format={fill:navy,font:{name:'Arial',size:11,bold:true,color:'#FFFFFF'},horizontalAlignment:'center',verticalAlignment:'center',rowHeight:30};
const widths=[6,24,57,57,32,23,46,60,60,60];
widths.forEach((w,i)=>sheet.getRangeByIndexes(0,i,rows.length+7,1).format.columnWidth=w);
sheet.getRange(`C8:E${rows.length+7}`).format.wrapText=true;
sheet.getRange(`I8:J${rows.length+7}`).format.wrapText=true;
sheet.getRange(`E8:E${rows.length+7}`).format.fill='#FFF4CE';
sheet.getRange(`F8:J${rows.length+7}`).format.font.color=muted;
sheet.getRange(`A8:A${rows.length+7}`).setNumberFormat('0');
sheet.getRange(`A8:A${rows.length+7}`).format.horizontalAlignment='right';
// Approximate wrapped height from explicit game line breaks and bilingual text.
for(let i=0;i<rows.length;i++){
  const r=rows[i];
  const english=r[2].split('\n').reduce((n,x)=>n+Math.max(1,Math.ceil(x.length/53)),0);
  const japanese=r[3].split('\n').reduce((n,x)=>n+Math.max(1,Math.ceil(x.length/27)),0);
  sheet.getRange(`A${i+8}:J${i+8}`).format.rowHeight=Math.max(32,Math.max(english,japanese)*16+12);
}
sheet.freezePanes.freezeRows(7);

const statuses={provisional:'暫定',series_terminology:'シリーズ用語'};
const termRows=glossary.terms.map(t=>[t.source,t.translation,statuses[t.status]??t.status,'']);
base(terms,`A1:D${termRows.length+7}`);
terms.getRange('A2').values=[['用語辞書']];
terms.getRange('A3').values=[['独自名称は暫定表記です。公式名称の網羅辞書ではありません。']];
terms.getRange('A4').values=[['出典: localization/glossary.json　コミット '+commit.slice(0,10)+' + 作業ツリーの訳文']];
terms.getRange('A5').values=[['確認メモには、表記の提案や気になる点を記入できます。']];
terms.getRange('A3:D5').format.font.color=muted;
terms.getRange('A7:D7').values=[['英語','日本語','表記の状態','確認メモ']];
terms.getRange(`A8:D${termRows.length+7}`).values=termRows;
const tt=terms.tables.add(`A7:D${termRows.length+7}`,true,'Glossary'); tt.style='TableStyleMedium2'; tt.showFilterButton=true;
terms.getRange('A7:D7').format={fill:navy,font:{name:'Arial',size:11,bold:true,color:'#FFFFFF'},horizontalAlignment:'center',verticalAlignment:'center',rowHeight:30};
[35,34,22,45].forEach((w,i)=>terms.getRangeByIndexes(0,i,termRows.length+7,1).format.columnWidth=w);
terms.getRange(`A8:D${termRows.length+7}`).format.rowHeight=30;
terms.getRange(`D8:D${termRows.length+7}`).format.fill='#FFF4CE';
terms.freezePanes.freezeRows(7);

wb.recalculate();
if(sheet.getRange(`F8:F${rows.length+7}`).values.flat().length!==translated.length) throw Error('Written row mismatch');
console.log((await wb.inspect({kind:'table',range:'翻訳一覧!A7:D10',include:'values',tableMaxRows:4,tableMaxCols:4,maxChars:2000})).ndjson);
console.log((await wb.inspect({kind:'match',searchTerm:'#REF!|#DIV/0!|#VALUE!|#NAME\\?|#N/A|#NUM!|#NULL!|#SPILL!|#CALC!',options:{useRegex:true,maxResults:20},summary:'error scan',maxChars:1000})).ndjson);
const storyStart=rows.findIndex(r=>r[1]==='ムネン村の会話・看板')+8;
const uiStart=rows.findIndex(r=>r[1]==='ランダマイザー設定')+8;
const nameStart=rows.findIndex(r=>r[1]==='特性名')+8;
for(const [name,range,file] of [['翻訳一覧','A1:E14','translations'],['用語辞書','A1:D16','glossary'],['翻訳一覧',`A${storyStart}:E${storyStart+3}`,'story'],['翻訳一覧',`A${nameStart}:E${nameStart+7}`,'names'],['翻訳一覧',`A${uiStart}:E${uiStart+6}`,'ui']]){
  const png=await wb.render({sheetName:name,range,scale:1.5,format:'png'});
  await fs.writeFile(`${output}/${file}-preview.png`,new Uint8Array(await png.arrayBuffer()));
}
const xlsx=await SpreadsheetFile.exportXlsx(wb);
await xlsx.save(`${output}/Wishes_日本語訳一覧.xlsx`);
await fs.writeFile(`${output}/review-data.json`,JSON.stringify({commit,rows,terms:termRows},null,2));
console.log(`Exported ${rows.length} translations and ${termRows.length} glossary entries.`);
