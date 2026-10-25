# ChatGPT翻訳用CSV

- all-texts.csv: 現在のカタログ全件。既存訳も含む。
- pending-texts.csv: 未翻訳全件。
- translated-reference.csv: 既存訳の参考資料。全面的な意味・画面検証の完了を意味しない。
- glossary.csv: 初期用語集。公式名称の網羅辞書ではない。
- batches/pending-NNN.csv: 未翻訳を元の順序で最大500件ずつ分割。重複も保持。
- CHATGPT_PROMPT.ja.md: ChatGPTに貼る翻訳依頼文。
- manifest.json: 件数、カタログと各ファイルのSHA256。

## 使い方

ChatGPTへプロンプトと小分けCSVを1つ、glossary.csvを添付する。
既存訳を参照したいときはtranslated-reference.csvも添付する。
返却ファイルは別のreturnedフォルダに保存し、元CSVを上書きしない。
500件でも長文が多ければ、ChatGPTへ依頼する前にさらに小分けする。
元ファイル順に分割しており、イベントやファイルの途中で切れる場合がある。
必要なら前後バッチも文脈資料として添付し、翻訳対象ファイルを明示する。

translationは訳稿であり、CSVをそのままソースへ書き込まない。
返却後、IDとsourceの照合、制御コード保護、言語切り替えの付与、
未定義字形・バッファ長・画面幅検査、yomiyasuレビューを経て、
ID指定バッチをupdate_catalog.pyのdry runで検査してから反映する。
現状このエクスポーターに返却CSVの自動インポート機能はない。
漢字フォントは未実装のため、プロンプトはかな中心の訳稿を要求している。

## 範囲と注意

「全件」は既存catalog.jsonの抽出候補全件を意味する。
未使用文言、重複、空文字、制御だけの行を含む。
画像内文字、通常の裸C文字列、JSON/.partyの構造別監査などは未完了であり、
ゲーム内に存在する全テキストの網羅を保証するものではない。
UTF-8 BOM付き標準CSV。引用符、カンマ、実改行はCSV規則で保持している。
ゲームのリテラルなバックスラッシュ制御はそのまま保持している。
Excelで開くだけの場合も、コードやIDの自動変換を避けるため全列を文字列として読み込む。

## 再出力

リポジトリのルートで実行する。返却訳を保護するため既存出力先には書き込まない。

```sh
python3 tools/localization/export_chatgpt_csv.py ../outputs/chatgpt-translation-NEW --batch-size 500
```

CSVを全件再読込し、全セルがカタログの値と一致することを検査してからZIPを生成する。
