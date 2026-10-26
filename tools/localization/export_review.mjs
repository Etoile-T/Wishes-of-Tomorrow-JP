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
const allEntries=process.argv.includes('--all');
const selected=allEntries?catalog:translated;
const byType=process.argv.includes('--by-type');
if(byType&&!allEntries) throw Error('--by-type requires --all to retain translation status');
const notesPath=process.argv.find(a=>a.startsWith('--notes='))?.slice(8);
const savedNotes=notesPath?JSON.parse(await fs.readFile(notesPath,'utf8')):{rows:{},terms:{}};
if(new Set(selected.map(r=>r.id)).size!==selected.length) throw Error('Translation ID mismatch');
const sourceCache=new Map();
const fieldSourceCache=new Map();
function speciesField(row){
  const declared=(row.target??'').match(/(?:^|\.)(speciesName|categoryName|description|name|pluralName)(?:\.|\[|$)/)?.[1];
  if(declared) return declared;
  if(!fieldSourceCache.has(row.file)){
    let source='';
    try{source=execFileSync('git',['show',`23be896714:${row.file}`],{cwd:root,encoding:'utf8',stdio:['ignore','pipe','pipe']});}catch{}
    fieldSourceCache.set(row.file,source);
  }
  const prefix=fieldSourceCache.get(row.file).slice(Math.max(0,row.start-180),row.start);
  return prefix.match(/\.(speciesName|categoryName|description|name|pluralName)\s*=\s*(?:_|COMPOUND_STRING)\(\s*$/)?.[1]
    ??(/\b\w*Description\w*\s*\[\s*\]\s*=\s*(?:_|COMPOUND_STRING)\(\s*$/.test(prefix)?'description':'');
}
function definition(row){
  if(row.target) return row.target;
  if(!sourceCache.has(row.file)) {
    let source='';
    try{source=execFileSync('git',['show',`23be896714:${row.file}`],{cwd:root,encoding:'utf8',stdio:['ignore','pipe','pipe']});}
    catch{console.log('Definition unavailable in pinned snapshot: '+row.file);}
    sourceCache.set(row.file,[...source.matchAll(/^([A-Za-z0-9_]+):+/gm)].map(m=>({offset:m.index,label:m[1]})));
  }
  const labels=sourceCache.get(row.file);
  let lo=0,hi=labels.length;
  while(lo<hi){const mid=(lo+hi)>>1;if(labels[mid].offset<row.start)lo=mid+1;else hi=mid;}
  return labels[lo-1]?.label??'';
}
function category(row){
  if(row.file.includes('/pokemon/species_info/')){
    const field=speciesField(row);
    return field==='description'?'図鑑説明':field==='categoryName'?'図鑑分類':field==='speciesName'?'ポケモン名':'ポケモンデータ・要分類';
  }
  if(row.file==='src/data/moves_info.h') return speciesField(row)==='description' ? '技説明' : '技名';
  if(row.file==='src/data/abilities.h') return speciesField(row)==='description' ? '特性説明' : '特性名';
  if(row.file==='src/data/items.h') return ['name','pluralName'].includes(speciesField(row)) ? '道具名' : '道具説明';
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
  return text.replace(/\{(?:JPN|ENG|JPN_NAME_(?:[1-9]|10))\}/g,'').replace(/\{(?:COLOR|SHADOW|BACKGROUND|TEXT_COLORS) [^}]*\}/g,'').replace(/\$$/,'')
    .replace(/\\n/g,'\n').replace(/\\p/g,'\n［改ページ］\n').replace(/\\l/g,'\n［スクロール］\n');
}
const statusLabel=s=>({translated:'翻訳適用済み',pending:'未翻訳',draft:'訳稿',needs_review:'要確認'}[s]??s);
const rows=selected.map((r,i)=>[i+1,category(r),readable(r.source),readable(r.translation??''),'',r.id,definition(r),`${r.file}:${r.line}`,r.translation??'',r.source,...(allEntries?[statusLabel(r.status)]:[])]);
// Trainer and map names live outside the catalog (trainers.party / region_map_sections.json).
for(const [file,label] of [['trainer-names.json','トレーナー名'],['map-names.json','マップ名']]){
  const table=JSON.parse(await fs.readFile(`${root}/localization/${file}`,'utf8'));
  for(const [en,ja] of Object.entries(table.names)) rows.push([rows.length+1,label,en,ja,'',`${label}:${en}`,'',table.file,`{JPN}${ja}{ENG}`,en,...(allEntries?['翻訳適用済み']:[])]);
}
for(const row of rows) row[4]=savedNotes.rows?.[row[5]]??'';
const wb=Workbook.create();
const overview=byType?wb.worksheets.add('目次・件数'):null;
function group(row){
  const label=row[1], file=row[7].split(':')[0];
  if(label.startsWith('図鑑')) return '図鑑';
  if(label.startsWith('ポケモン')||label==='タイプ') return 'ポケモン';
  if(label.startsWith('技')) return '技';
  if(label.startsWith('特性')) return '特性';
  if(label.startsWith('道具')||label==='バッグ・道具使用') return '道具';
  if(label==='戦闘メッセージ'||file.startsWith('src/battle_')) return '戦闘';
  if(['ボックス','名前入力案内','手持ち','ステータス'].includes(label)) return 'ポケモンUI';
  if(['設定','ランダマイザー設定','開始メニュー','スタートメニュー','スクリプト選択肢'].includes(label)) return 'メニュー・設定UI';
  if(label.includes('クエスト')) return 'クエスト';
  if(label.startsWith('会話・看板')||label==='共通会話') return '会話・看板';
  if(['話者名','地名','トレーナー名','マップ名'].includes(label)) return '人名・地名';
  return 'その他UI・要分類';
}
const grouped=new Map();
for(const name of (byType?['ポケモン','図鑑','技','特性','道具','戦闘','ポケモンUI','メニュー・設定UI','クエスト','会話・看板','人名・地名','その他UI・要分類']:['翻訳一覧'])) grouped.set(name,[]);
for(const row of rows) grouped.get(byType?group(row):'翻訳一覧').push(row);
const sheets=[...grouped].filter(([,items])=>items.length).map(([name,items])=>({name,rows:items,sheet:wb.worksheets.add(name)}));
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
const lastCol=allEntries?'K':'J';
function fillSheet(sheet,rows,name,index){
base(sheet,`A1:${lastCol}${rows.length+7}`);
sheet.getRange('A2').values=[['Wishes of Tomorrow　'+(byType?name:(allEntries?'全テキスト翻訳一覧':'日本語訳一覧'))]];
sheet.getRange('A3').values=[[byType?`このシート ${rows.length.toLocaleString('en-US')}件　翻訳適用済み ${rows.filter(r=>r[10]==='翻訳適用済み').length.toLocaleString('en-US')}　未翻訳 ${rows.filter(r=>r[10]==='未翻訳').length.toLocaleString('en-US')}`:allEntries?`カタログ ${catalog.length.toLocaleString('en-US')}候補　適用済み ${translated.length.toLocaleString('en-US')}　未翻訳 ${(catalog.length-translated.length).toLocaleString('en-US')}　別途名称 ${rows.length-selected.length}件`:`翻訳適用済み ${translated.length.toLocaleString('en-US')}件　2026年10月26日時点`]];
sheet.getRange('A4').values=[['原文・訳文の出典: localization/catalog.json　コミット '+commit.slice(0,10)+' + 作業ツリーの訳文']];
sheet.getRange('A5').values=[[allEntries?'K列の翻訳状態で絞り込めます。未使用・重複・制御のみの候補を含み、画像内文字等は未網羅です。':'［改ページ］・［スクロール］を明示しています。確認メモは自由に記入できます。']];
sheet.getRange('A6').values=[['表示確認・通しプレイは未完了です。メモの記入だけではゲームに反映されません。']];
sheet.getRange('A3:J6').format.font.color=muted;
sheet.getRange(`A7:${lastCol}7`).values=[['No.','区分','英語原文','日本語訳','確認メモ','ID','定義名','原文の出典','日本語訳（制御コード付き）','英語原文（制御コード付き）',...(allEntries?['翻訳状態']:[])]];
sheet.getRange(`A8:${lastCol}${rows.length+7}`).values=rows;
const table=sheet.tables.add(`A7:${lastCol}${rows.length+7}`,true,'Translations'+index);
table.style='TableStyleMedium2'; table.showFilterButton=true;
sheet.getRange(`A7:${lastCol}7`).format={fill:navy,font:{name:'Arial',size:11,bold:true,color:'#FFFFFF'},horizontalAlignment:'center',verticalAlignment:'center',rowHeight:30};
const widths=[6,24,57,57,32,23,46,60,60,60,...(allEntries?[18]:[])];
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

}
for(const [i,item] of sheets.entries()) fillSheet(item.sheet,item.rows,item.name,i);

const statuses={provisional:'暫定',series_terminology:'シリーズ用語'};
const termRows=glossary.terms.map(t=>[t.source,t.translation,statuses[t.status]??t.status,savedNotes.terms?.[t.source+'\u0000'+t.translation]??'']);
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

if(overview){
  base(overview,`A1:F${sheets.length+9}`);
  overview.getRange('A2').values=[['Wishes of Tomorrow　種類別 翻訳一覧']];
  overview.getRange('A3').values=[[`全${rows.length.toLocaleString('en-US')}件（カタログ${catalog.length.toLocaleString('en-US')}件＋別管理名称${rows.length-selected.length}件）`]];
  overview.getRange('A4').values=[['各シートの翻訳状態で未翻訳を絞り込めます。黄色の確認メモ欄は自由に記入できます。']];
  overview.getRange('A5').values=[['IDと制御コード付き原文・訳文を維持。メモの記入だけではROMに反映されません。']];
  overview.getRange('A6').values=[['ファイル・定義に基づく分類です。共通文字列や未分類候補は「その他UI・要分類」に含みます。']];
  overview.getRange('A7:F7').values=[['シート','全件','翻訳適用済み','未翻訳','その他の状態','案内']];
  for(const [i,item] of sheets.entries()){
    const r=i+8,end=item.rows.length+7,ref=`'${item.name}'!`;
    overview.getRange(`A${r}`).values=[[item.name]];
    overview.getRange(`B${r}:E${r}`).formulas=[[`=COUNTA(${ref}F8:F${end})`,`=COUNTIF(${ref}K8:K${end},"翻訳適用済み")`,`=COUNTIF(${ref}K8:K${end},"未翻訳")`,`=B${r}-C${r}-D${r}`]];
    overview.getRange(`F${r}`).values=[[item.name==='会話・看板'?'区分列にマップ名を保持。未使用マップを含みます。':item.name==='図鑑'?'分類・説明・図鑑UIを区分列で絞り込めます。':'英語原文・日本語訳・状態・確認メモ・IDを収録。']];
  }
  const total=sheets.length+8;
  overview.getRange(`A${total}`).values=[['合計']];
  overview.getRange(`B${total}:E${total}`).formulas=[['B','C','D','E'].map(c=>`=SUM(${c}8:${c}${total-1})`)];
  overview.getRange(`A${total}:F${total}`).format.fill='#E5EDF5';
  overview.getRange(`A${total}:F${total}`).format.font.bold=true;
  overview.getRange('A7:F7').format={fill:navy,font:{name:'Arial',size:11,bold:true,color:'#FFFFFF'},rowHeight:30};
  [26,14,16,14,18,70].forEach((w,i)=>overview.getRangeByIndexes(0,i,total,1).format.columnWidth=w);
  overview.getRange(`A8:F${total}`).format.rowHeight=32;
  overview.getRange(`B8:E${total}`).setNumberFormat('#,##0');
  overview.freezePanes.freezeRows(7);
}
wb.recalculate();
for(const item of sheets) if(item.sheet.getRange(`F8:F${item.rows.length+7}`).values.flat().length!==item.rows.length) throw Error('Written row mismatch: '+item.name);
console.log((await wb.inspect({kind:'table',range:byType?`目次・件数!A7:F${sheets.length+8}`:'翻訳一覧!A7:D10',include:'values,formulas',tableMaxRows:20,tableMaxCols:6,maxChars:2500})).ndjson);
console.log((await wb.inspect({kind:'match',searchTerm:'#REF!|#DIV/0!|#VALUE!|#NAME\\?|#N/A|#NUM!|#NULL!|#SPILL!|#CALC!',options:{useRegex:true,maxResults:20},summary:'error scan',maxChars:1000})).ndjson);
const previews=byType?[['目次・件数',`A1:F${sheets.length+8}`,'index'],...sheets.map((item,i)=>[item.name,`A1:E${Math.min(item.rows.length+7,10)}`,'type-'+i]),['用語辞書','A1:D12','glossary']]:[['翻訳一覧','A1:E14','translations'],['用語辞書','A1:D16','glossary']];
for(const [name,range,file] of previews){
  const png=await wb.render({sheetName:name,range,scale:1.5,format:'png'});
  await fs.writeFile(`${output}/${file}-preview.png`,new Uint8Array(await png.arrayBuffer()));
}
const filename=byType?'Wishes_種類別翻訳一覧':allEntries?'Wishes_全テキスト翻訳一覧':'Wishes_日本語訳一覧';
const xlsx=await SpreadsheetFile.exportXlsx(wb);
await xlsx.save(`${output}/${filename}.xlsx`);
await fs.writeFile(`${output}/review-data.json`,JSON.stringify({commit,rows,terms:termRows,sheets:sheets.map(item=>({name:item.name,ids:item.rows.map(row=>row[5])}))},null,2));
console.log(`Exported ${rows.length} entries in ${sheets.length} data sheets and ${termRows.length} glossary entries.`);
