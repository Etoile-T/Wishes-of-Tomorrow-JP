# セレビィのしま・地下闘技場

2026-10-26。CelebiIsland 114件、UndergroundArena 102件、計216件（カタログの行単位）。

## 訳と判断

- セレビィのしま: 3人の守り手の試練、橋の老人、セレビィのリライブ、ユクシー・エムリット・アグノムの教えと出現演出。
- 地下闘技場: 入場演出と実況、休憩・キズぐすりなしの3連戦、ボルテンとの決戦、地下バッジと空路の説明、いのちのたま、観客の会話。
- 原文・スクリプトを参照し、リライブには一緒に戦う必要があること、強化は残り防御低下とハイパーモードがなくなることを保持。メガシンカとの組合せはアグノムの推測・試したい気持ちとして訳し、実証済みの効果を足していない。
- 3人全員の承認、1度でも戦う、3連戦、200夜、3週間分、週2回の変更を照合。200 nightsは試合数と誤解させないよう「200ばん」とした。
- `noise` を熱気だけに置き換えないよう、入口は「どよめき」とした。`Do your worst` と敗北後の反復は「ぜんりょくで きな」／「ほんとに ぜんりょくだったね」で対応。ファイトクラブの冗談、賭けた観客の脅し、禁止なのに母も来ている子の台詞も保持。
- 地下の王者ボルテンは既訳トレーナー名に統一。「ちかとうぎじょう」「ちかバッジ」とともに暫定辞書へ追加。ポケモン名といのちのたまはlookupで既訳を照合。National Ribbonはナショナルリボン。
- 主人公の性別を決めつけない。実況のANNOUNCERは「じっきょう:」。会話の自然な句点、原文の比喩、言いよどみを保持。

## yomiyasu

script / essay指針で英語資料と読み比べた。lintはいずれも候補0件。語調・比喩・反復・不確実性を確認し、lintを消すための改変は行っていない。下書きと最終稿は同一。検査記録は品質の合格や人間の承認を意味しない。

`yomiyasu-check: executed via=verify run=20261026T001012Z-38a0fa5f attempt=1 final=sha256:4b952085210f mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped`

`yomiyasu-check: executed via=verify run=20261026T001013Z-82e3bdac attempt=1 final=sha256:b34bbabed998 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped`

## 検査範囲

script_batchでメッセージ全体を生成。dialogue_tools checkは両バッチbad 0、widthは26マス超0。原文の変数・改ページ・スクロール・終端とJPN/ENGスコープを検査。画面表示・実機・進行は未検証。最終ビルド・パッチ照合の結果と成果物はstatus.jsonとHANDOFF_CODEX.mdを参照。
