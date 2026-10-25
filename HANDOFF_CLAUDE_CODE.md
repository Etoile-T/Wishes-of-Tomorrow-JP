# Claude Code 引き継ぎ — Wishes of Tomorrow 日本語化

更新: 2026-10-26（日本時間）。**Codexへ引き継ぎ済み。現在の手順と状態は `HANDOFF_CODEX.md` を優先すること。** この文書は経緯の詳細として残す。最初にAGENTS.mdとこの文書を読むこと。
**調査だけで終えず、既存の翻訳を維持して実装・検証を続ける。完全日本語化は未完了。**

## 直近のユーザー指示

- ゲーム内容・独自機能・保存形式を維持して、ストーリーから独自UIまで完全日本語化する。
- GitHubで管理。originへのcommit/pushは許可済み。
- yomiyasuを導入して訳文を見直す。導入済みなので再インストール不要。
- 訳をExcelまたはテーブルで確認できるようにする。既存一覧を更新する。
- 一度「ポケモン名・図鑑/技/特性の説明・道具まで終わったら一旦停止」を希望した後、対象を**全UI**へ拡大した。名前だけで停止した過去の判断は無効。
- ソース検査とビルドを優先し、長いmGBA確認は延期。別ディスプレイのウィンドウを勝手に移動しない。
- クエストにっし後のグラフィック報告は、ユーザーが「エミュレータのバグでした。気にしないでください。日本語の翻訳を続けてください」と確認済み。**調査を再開したり、この件で翻訳を止めたりしない。** エミュレータ側原因というユーザー確認と、全ゲーム検証完了は別。
- コンテキスト/トークンが切れる前に引き継ぎを残し、Claude Codeへ移行する。こちらからClaude Codeを起動する指示ではない。
- 所要時間の質問には、粗い工数としてUI残り20〜50時間、全体は数百時間規模と回答済み。未使用・重複を含むので確約や実測ではない。
- Claude Code移行後のトークン見積もり（2026-10-26回答）: UI残りは1バッチ30〜50万トークン×15〜25バッチで約400〜1,000万、セッション予算約1,500万で足りる見込み。全体（会話・ストーリー含む）は5千万〜1億5千万トークン級で1セッションでは不足し、複数セッションで引き継ぎながら進める。粗い見積もり。

## リポジトリと版

- 作業場所: `/Users/owner/Desktop/Wish/Wishes-Game`
- origin: `https://github.com/Etoile-T/Wishes-of-Tomorrow-JP.git`、作業ブランチmain。
- upstream: `https://github.com/jmaloney95/Wishes-Game.git`、ゲーム本体のmaster。
- 英語ソース: `efb1c880d0b486c1948763051b6c1bb8990a7353`。最初のソース取込コミットは`23be896714`。英語原文を読むときは`git show 23be896714:PATH`。
- 最新の翻訳実装: `50f0c034587667dc2464bf96591d86d6993d4a68`（ホテルZ・タワー・アッシュランド・第2幕）。その前は`d3d32afd2c`（Route 2〜シントウキョウ、オリジナルポケモン）。その前は`a47854cfd2`（トレーナー名・マップ名）。その前は`72fb736ed7`（戦闘メッセージ、自動改行、道具の複数形）。この文書・最新のstatus/manifest/Excelはその後のコミットに保存されるので、開始時に`git log -5 --oneline`と`git status --short`を確認する。
- 参考フォーク: `/Users/owner/Desktop/Wish/reference-jp`、`b07a7ec5f798ebc4cf3641613bbd8ddbb9b6f5ef`。無条件にファイルを上書きしない。
- ゲームREADMEはExpansion 1.15.3をベースと記載。独自のquests、field name box、NPC portraits、Shadow、DLC等がある。

### 公式1.2.6との違い

公式BPSを渡されたため照合したが、日本語版はそのバイナリへ直接パッチして作ったものではない。

- ローカル公式BPS: `../artifacts/wishes-of-tomorrow-1.2.6.bps`。
- SHA256: `05bf04c8ad2ad4e2da6a353a6d0ed234c44930a6ba1231ec9d0f2738dfb1ff54`。公式タグ内BPSとバイト一致。
- 公式パッチの適用前: Emerald(U) 16MiB、CRC32 `1f1c08fb`。適用後: 32MiB、CRC32 `f1eeea17`。
- タグ`upstream-v1.2.6`は開発ワークスペース`52ffb1cf827ab0fe905f5b2caa57d5116e276d23`を指す。ゲーム本体はそのsubmodule `pokeemerald-expansion`の`e6f5b24e0af95d079cc3380a1bb895963c4bc05b`。ワークスペースとゲームmasterを直接diffして「全ソース追加」と誤判定しない。
- 日本語化の基準は上記efb1c880…で、1.2.6のソースとは別版。勝手に1.2.6へ戻さない。

## 現在の進捗

カタログは**61,722候補、翻訳適用9,687件、pending52,035件（カタログ外: トレーナー名・マップ名）**。会話数・有効な画面数・完成率ではない。未使用、重複、制御のみ等も含む。

主な適用済み:

- 初期の149件: ムネン村の一部会話、クエスト見出し/目的/通知等。
- 種族名1,321、技名923、特性名316。フォーム・条件付き定義を含む。未対応名称あり。
- 特性説明321、道具名1,125（単複を含む）、道具説明805。参考訳の全件意味レビューは未完了。
- タイプ/バッグ分類等53文字列、タイプアイコン19枚。
- UIバッチ01/02で680件、今回ui-party-status-04で84件。主な開始/設定/バッグ/ボックス/手持ち/セーブ/ランダマイザー、図鑑UIの一部。
- 今回84件: 手持ちの選択・技習得/忘却・持ち物/メール・回復/状態異常・交換制限・きのみタグ。`src/strings.c`76件、`src/berry_tag_screen.c`8件。
- Claude Code移行後のui-script-menu-06で228件: `src/data/script_menu.h`の全選択肢（クイズ・自販機・景品・施設ルール・ナナシマ等）。数字/階数/BPの19件は原文のまま確認済み。
- jpn-punctuation-fix-05で既訳6件の金額・桁区切りを修正（下記「日本語モードの記号」）。
- ui-strings-common-07で228件: strings.cのうち外部参照のある共通UI（フィールド/選択肢/スタートメニュー/道具/手持ち/ステータスメモ/技思い出し/育て屋/タマゴ/殿堂入り/PC・もようがえ/ひみつきち/地図/保存失敗/時計/交換）、性格名25件。JOKAIM＝「ジョカイム」（暫定）。
- 会話（ユーザー指示「セリフ系を翻訳していきましょう」2026-10-26）: dialogue-common-08（センター/入手/PC/秘伝技/虫よけ/技思い出し/クエスト日誌/WotHM）260行、speaker-names-09、dialogue-munen-area-10、dialogue-players-house-11（ミシロの家を流用した自宅1F/2F全文＋研究所の独自2件）、dialogue-munen-tunnel-12（ムネントンネル・ノースウィンド）、dialogue-pompeii-13（ポンペイ＝NewMap・店・宿）、dialogue-pompeii-torii-14（リョウコの家・めんづくり・鳥居）、dialogue-national-park-15（しぜんこうえん＝Route_2_2・クルミのもり・センネンの看板）。
- 戦闘メッセージ（ユーザー依頼「GO! まるまるみたいな」）: battle-messages-16〜19で`src/battle_message.c`の844件。記号・空文字列・未使用の断片だけpending。トレーナーの肩書き・名前（`src/data/trainers.party`、カタログ対象外）と勝敗時の台詞は未訳で、英語が混ざる。
- トレーナー名・マップ名（ユーザー依頼「トレーナー名やマップ名を変えていこう」）: カタログ対象外のファイルを直接編集し、対訳表を`localization/trainer-names.json`・`localization/map-names.json`に保存。トレーナー名は`trainers.party`の`Name:`行（`trainerName[13]`、12バイト以内）、マップ名は`region_map_sections.json`の`name`（16バイト以内）。肩書きはカタログのtrainer-classes-20（`name[14]`、13バイト以内）。Excelはこの2つのJSONからも行を作る。`trainers_frlg.party`・`battle_partners.party`は未訳。
- 道具の複数形: `src/item.c` `CopyItemNameHandlePlural`は名前が`{JPN}`で始まれば英語の「s」を付けない（ユーザー報告「きずぐすりs」）。
- UI候補一覧: `localization/UI_PROGRESS.md`、`ui-inventory.json`。59ファイル・未翻訳言語候補3,185件。ただしトレーナー名・未使用施設文言等も含む。画像文字や裸C文字列を網羅した数ではない。

## 次に進める作業

0. **会話を優先中。** 第1〜3幕、アッシュランド、ホテルZ、タワーは完了。残りの独自マップ: RebelHideout 177、TradewindTown 180（＋Lab/Gym/House/Apartment）、CelebiIsland 114、UndergroundArena 102、DistortionWorld系 131、PrototypeIsland/Lab 68、DragonKeeper 34、MewtwoPostGame 29。独自マップ未訳は約2,300行。ムネンから到達判定するとホウエン全域まで広がる（Route_2→ロープウェイ駅等）ため、元のホウエンの台詞は後回し。研究所等の流用マップは独自メッセージだけ先に訳す。

1. `src/strings.c`の残り（約500件）。参照元別に、easy_chat 70、frontier_util 46、mystery_gift_menu 44、図鑑 33+、frontier_pass 31、berry_crush 25、union_room_chat 20、trainer_card 18等。外部参照のない約80件は未使用の可能性が高く後回し。script_menu.hは完了。
2. 図鑑UIの未訳・動的な文の連結・狭い能力/タマゴグループ欄を調整。英語の語順を単語単位置換して完成扱いしない。
3. 戦闘メッセージ、施設、通信・コンテスト等UIを用途別に対応。
4. 図鑑本文、技説明、残りの名称、ストーリー・クリア後を進める。参考フォークの図鑑本文は版が違う例が多く、英語の意味を読んで訳す。
5. 道具/特性説明の意味レビューを全件完了させる。改行・数値・文字検査が通っただけでは意味を保証できない。
6. 漢字と名前入力、画像文字、全画面幅、最初から最後までの通しプレイは別途必要。

## 会話の翻訳手順（script_batch.py）

`.string`行は1行ずつカタログに入るが、ROMでは台詞（`$`まで）が1続きになる。

```sh
# ID<TAB>日本語 の行を書く（{JPN}/{ENG}は書かない。変数はそのまま）
python3 tools/localization/script_batch.py DRAFT.txt localization/batches/NAME.json
python3 tools/localization/update_catalog.py localization/batches/NAME.json --apply
```

- 台詞の先頭に`{JPN}`、`{PLAYER}`/`{STR_VAR_n}`/`{REGION}`等FD系差し込みを`{ENG}…{JPN}`で自動で囲む。`#if`/`#else`の直後の行にも`{JPN}`を付ける。
- 台詞の一部だけの翻訳は拒否する（残りの英語がJPNモードで表示されるため）。
- 各行の`\p`・`\l`・`$`と変数の位置は原文の行どおりにする。`\n`だけは位置と数を変えられるが、2行の枠を超えないこと。`\l`は足せないので、長い文は短くする。
- 標準の会話枠は27タイル＝日本語27マス。変数を長めに見積もって26マス以内を目安にする。
- 話者は既訳に合わせて「名前: 本文」。電話の『』は使わない。JPN区間の引用符は「」。
- JPNモードでは英字（RedFatality等）も日本語フォントの8px幅になる。幅の見積もりは1文字1マスで数える。
- プレイヤーの性別を決めつけない（"kid"を「ぼうず」にしない）。性別の分からないNPCに「ぼく」「〜ぜ」を付けない。原文が"he/she"で示す人物は従う（リョウコ＝男性の弟子、よげんしゃ＝女性）。
- 固有名詞は`glossary.json`を先に確認し、新しいものは暫定（provisional）で追加する。地図の地名（`src/data/region_map/region_map_sections.json`）はカタログの対象外で未訳。

## 翻訳の適用方法 — 必読

**既存catalog.jsonを再抽出して上書きしない。** IDキーのバッチを作る。

```sh
python3 tools/localization/update_catalog.py localization/batches/NEW_BATCH.json
python3 tools/localization/update_catalog.py localization/batches/NEW_BATCH.json --apply
python3 tools/localization/catalog.py validate
python3 -m unittest discover -s tools/localization -p 'test_*.py' -v
python3 tools/localization/ui_inventory.py
python3 tools/localization/export_table.py
```

バッチ例: `[{"id":"既存ID","translation":"{JPN}やくぶん{ENG}","provenance":{"batch":"NEW_BATCH","method":"..."}}]`。

- `start/end/raw/source`は英語スナップショットの位置。変更しない。
- update_catalogは適用済み文字列の長さ差を加算し、実際のソースを照合してからまとめて書き込む。再適用は冪等。不一致なら停止して原因を調べる。
- Cコード編集で後続の原文位置が変わった場合は`code_offset`を別記する。現在naming_screen.cの後続5文字列に+98がある。startやIDを再生成せず、翻訳長差とは別に加算する。バッチでcode_offsetを書き換えるのは禁止。
- `seed_*.py`、`ui_common.py`、`ui_messages.py`、参考データの提案ツールは当時のバッチ生成用。**何も考えず再実行すると適用済みバッチを空/別内容で上書きしうる。** 通常再ビルドには不要。
- 制御変数、PAUSE、効果音、\p/\lを保護。\nとJPN/ENGのレイアウト調整は許容されるが、順序と意味は手で確認。
- `ui_common.scoped()`は変数前ENG/後JPN、色指定を先頭に保持、EOS `$`前に言語復帰。名前が変数から展開されると末尾ENGで終わるので、後続日本語を再度JPNにする。
- `{PKMN}`/`{POKEBLOCK}`ロゴ、PP等ラテン略号はENGで囲む。JPNのままだと同じバイトがかなを指す場合がある。

### 日本語モードの記号（2026-10-26確認）

日本語フォント画像で確認済み。JPN区間ではラテンの`¥`(B7)=「円」、`,`(B8)=「.」、`“ ” ‘ ’ '`(B1–B4)=『』「」として描画される。英字A–Z/a–z・数字・`:`・`!?`は同じ字形。`.`(AD)は「。」、`-`(AE)は「ー」と同じバイト。

- 金額は`{ENG}{STR_VAR_n}{JPN}円`または`200円`。charmapに`'円' = B7`、`「」『』` = B3/B4/B1/B2を追加済み。JPN区間の引用符は「」を使う。
- JPN区間で桁区切りの`,`は使わない（`1500まい`）。必要ならENGへ戻す。
- `catalog.validate`が上記7文字をJPN区間で拒否する。

## フォント・UIの実装と限界

- 戦闘文の自動改行`BreakStringAutomatic`（`src/line_break.c`）は、単語の幅を`GetStringWidth`の差分で測る（JPN/ENGと制御コードに対応）。日本語の戦闘文は空白で文節を区切ること（区切りのない長い文は改行できない）。手動の`\n`がある文は自動改行されない。

- 既存日本語かなフォントを再利用。既定言語を日本語へ変更せず、訳文にJPN/ENGを明示。
- charmapの「ヴ」F1は日本語モードだけ追加グリフへ分岐。英語のÄを壊さない。「・」は既存AFへ別名定義。
- `src/data/text/japanese_extra_glyphs.h`と`src/text.c`。フォント全体の移植はしていない。
- 漢字は未実装。参考側にも汎用漢字は見つからず、サブセット＋拡張符号の設計のみ。コピー・比較・長さ・変数・セーブ用固定長まで監査が必要。
- 種族名は制御を含め10バイト以内（ニックネーム互換）、技/特性名16バイト以内を確認して取り込んだ。文字数だけで判断しない。
- 道具説明の現行折返しは13セル×3行。汎用自動改行/禁則/変数展開後の自動配置は未実装。
- TypeInfo.nameはROM用だけ言語切替4バイトを追加。セーブの構造は変更していない。
- 設定画面の選択色は先頭COLOR/SHADOWのバイト2/5を書き換えるため、この前にJPNを足さない。一時dstは32バイトへ拡張済み。
- 名前入力タイトルはSTR_VAR_1で種族名を展開し、15バイト追記による言語コード切断を避けた。キーボードはまだ英字。
- タイプアイコンは参考フォークとサイズ/パレット一致を確認して19枚のみ移植。戦闘用小アイコンやコンテスト画像等は別途確認。

## yomiyasu

- 導入場所 `.agents/skills/yomiyasu/SKILL.md`。v2.4.0、コミット`552c12c472ddfb79e2ee7a15219847782686a945`、MIT/Unicode noticesあり。
- AGENTS.mdと`localization/yomiyasu.md`を読む。用途は文章推敲。フォントや翻訳APIではない。
- 台詞はscript、UI案内はmanual。自然な句点・キャラの口調・繰返し・比喩を検出候補を消すために削らない。
- 英語資料、日本語下書き、最終稿を`localization/reviews/`へ保存。CLIのlint→run→verifyを使い、候補の採用/維持理由と正確な実行行をreview.mdへ記録する。
- 状態ディレクトリは`../artifacts/yomiyasu-state`。Gitへキャッシュ全文は加えない。CLIの記録時刻はUTCで、ユーザー向け日付はJST。
- 直近レビュー: `localization/reviews/dialogue-story-26-31.review.md`、`dialogue-story-21-25.review.md`（会話）、`trainer-and-map-names-20.review.md`（名前）、`battle-messages-16-19.review.md`（戦闘）、`dialogue-story-13-15.review.md`、`dialogue-story-09-12.review.md`（会話）、`dialogue-common-08.review.md`。会話はyomiyasuの`--doc-type script`。

## ビルドと検証

macOS、devkitARM `/opt/devkitpro/devkitARM`、GCC16.1.0、clang/libpng等でビルド済み。

```sh
# 読み込み中の可能性があるROMを上書きしないよう、必ず新しいFILE_NAMEを使う。
make -j8 FILE_NAME=pokeemerald-jp-NEXT_ID TOOLCHAIN=/opt/devkitpro/devkitARM
python3 tools/localization/export_play_rom.py pokeemerald-jp-NEXT_ID.gba ../artifacts/play
```

- 最新ビルド: `pokeemerald-jp-dlg9687.gba`。ROM使用29,874,216B、EWRAM230,024B、IWRAM28,600B。物理ROM32MiB。
- 自動テスト40件成功。文字コード/制御、差分再挿入、BPS、UI固定バッファ、code_offset、版固定出力、誤パッチ拒否等。ゲーム全イベントの回帰テストではない。
- 直近のソース2ファイルは非文字列トークンが変更前と一致。
- リンカRWX警告は英語基準版にもある。成功と警告を両方記録。
- 実画面の全面確認、戦闘/イベント/セーブ互換の通し検証は未実施。ビルド成功から正常プレイを断言しない。
- 同梱mgba-rom-test-macは初期に-11を返し、その後status/quitのみ動くがPC/Cycle=0のまま。frame命令を送った回数で実行成功と数えない。GUIは過去に起動確認しただけ。

## 最新の成果物 — 古い同名WIPに注意

親ディレクトリ`/Users/owner/Desktop/Wish/artifacts`はGit管理外。**ROMをGitHubへpushしない。**

- 最新情報: `../artifacts/LATEST-JP.json`
- 最新プレイROM: `../artifacts/play/wishes-jp-d7794c852b669b70.gba`
- **ユーザー向け出力**: `../outputs/gba/wishes-jp-9687-03f7d392.gba`（同内容のコピー、読み取り専用）。ユーザーは同フォルダで版ごとの`.sav`を使っている（7326・8170版のsavあり）。セーブを勝手にコピー・移動しない。ユーザーの希望で、作業後のGBAは`outputs/gba/`へ版名付きで追加し、README.txtの「最新」を更新する。既存ファイルは上書きしない。
- SHA256: `d7794c852b669b701cf2f9a9b05af937708a3e821a7bbdce03980cc2aac8aeab`、CRC32 `03f7d392`。
- 最新BPSフォルダ: `../artifacts/patches/ui-9687-03f7d392/`。`manifest.json`に全ハッシュ。
- 配布用（ROMなし）: `../artifacts/wishes-jp-ui9687-03f7d392-patch.zip`。
- 追跡用manifest: `localization/patch-manifest-ui9687.json`。
- UI6005以降はPython版`apply_verified_patch.py`で復元ROMとビルドROMの全バイト一致を確認。RomPatcher.jsでの独立検証はUI5777まで。
- BPSの`patch_crc32`が毎回`2144df1c`なのは、末尾に自身のCRCを含むファイル全体のCRC32が定数になるため。異常ではない。
- 英語基準ROM: `../artifacts/wishes-en-baseline.gba`、SHA256 `93fb28460bb7348e327c97e217ecd50091fc01200e8d9cc41b871469c36c9db7`、CRC32 `62ba561e`。
- BPSはこの32MiB英語Wishesから日本語版へ変換する。**市販Emerald、公式1.2.6適用後ROM、日本語版への重ね適用には使わない。** 日本語ROMをそのまま開く場合BPS追加は不要。
- `apply_verified_patch.py SOURCE PATCH MANIFEST OUTPUT_DIR`は入力・BPS・出力のSHA256とBPS CRCを照合し、誤った組み合わせを拒否。出力は上書きしないハッシュ名。
- UI5777では独立実装RomPatcher.js（親artifacts/rompatcher-validation、コミット4f17297…）でも適用し、直接ビルドROMと全バイト一致を確認済み。
- `wishes-jp-wip.gba`/`.bps`、従来のsource-and-patch.zipは古い5,693件版。最新として渡さない。日付だけで判断せずmanifestで確認。
- セーブ/ステートを勝手に上書き・移動しない。export_play_rom.pyは一時inodeを新規ハッシュ名へlinkし、既存ROMの上書きを防ぐ。

### 診断用ROMは使わない

`WOT_SPRITE_DIAGNOSTICS=1`のMake設定で別名/-sprite-diagビルドディレクトリを作れるが、通常は既定0のまま。field-returnのDebugPrintfを追加するだけ。

過去の診断版`../artifacts/quest-log-diagnostics/wishes-jp-ce6414c508b8622d.gba`は翻訳も古い。ユーザーが原因を確認済みなので不要。未実施だった診断GUIの許可を改めて求めない。

## Excel・表・辞書

- Excel: `../outputs/translation-review-20261026/Wishes_日本語訳一覧.xlsx`、Git内コピー`localization/exports/translated-texts.xlsx`。
- GitHub表: `localization/translated-texts.md`。
- Excelは翻訳一覧/用語辞書の2タブ、フィルタと7行固定、メモ欄あり。IDと制御付き原文/訳文を保持。用語辞書タブは初期23語で、全公式名称辞書ではない。
- `tools/localization/export_review.mjs`がartifact-tool用の再生成コード。依存はCodexキャッシュの@oai/artifact-tool。作業ディレクトリへnode_modulesリンクを置き、スクリプトをコピーして`node export_review.mjs REPO_PATH OUTPUT_DIR`で実行できる。
- 現在使っている実行場所: `../artifacts/translation-review-build/build_review.mjs`（Git内export_review.mjsと分類を同期済み。openpyxlは未導入）。カタログから動的に全適用済み行を作る。ユーザーメモは自動継承しないので、編集済みExcelがあればIDで退避してから更新する。
- openpyxl等で安易に上書きせず、既存の形式を維持する。プレビュー/保存XLSXのID・原文・訳文とフィルタ/固定行を検証する。
- 辞書: `glossary.json`、`terminology-names.json`、`terminology-items-custom.json`、参考名称/道具の取り込みレポート。独自名称は暫定表記を含む。

## 移行直後の最小確認

1. `git status --short`、`git log -5 --oneline`。
2. status.jsonの値とcatalog.py statsを照合。
3. `catalog.py validate`と40件のテスト。通常は既に成功しているので無意味に繰り返さない。
4. `UI_PROGRESS.md`から次の用途別バッチを選び、原文・呼出側・幅/固定長を確認して翻訳を続ける。
5. 意味レビュー・検査・新しい名前でビルドし、hash名ROM/BPS/Excel/表/status/この引き継ぎを更新してcommit/push。

完了していない作業は完了と報告しない。外部翻訳APIはこれまで使っていない。ローカルソースと参考フォーク、手動翻訳・辞書・検証ツールで進めている。
