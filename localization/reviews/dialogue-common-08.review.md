# 共通会話（センター・入手・PC・秘伝技・クエスト）

2026-10-26。会話テキスト（`.string`）の最初のバッチで260行。ポケモンセンター、道具・コイン入手、PC・転送、ショップ、なみのり等の秘伝技、虫よけの効果切れ、技思い出し、連れ歩き、DexNav、Wishes独自の秘伝技メニュー、スナッチ進行、クエスト日誌「ちちおやの さいごの ねがい」。読み手はプレイヤー、種類はscript（台詞）。

## 方法

新しい`tools/localization/script_batch.py`で行ごとの日本語からバッチを作った（テスト5件）。連続する`.string`行は1つのメッセージとしてROMに入るので、`{JPN}`は台詞の先頭に1回置き、変数は`{ENG}{VAR}{JPN}`で囲む。台詞の一部だけを訳すと、残りの英語がJPNモードで表示されるため禁止した。`#if`/`#else`の直後の行にも`{JPN}`を付ける。各行の`\p`・`\l`・`$`と変数の位置は原文の行どおり（`\n`の位置だけは調整可）。

## 判断

- 公式の言い回しに寄せた（「ようこそ！ ポケモンセンターへ」「おまちどうさまでした！」等）。LanetteはマユミとしてFRLG分岐のBillはマサキとした（`#if IS_FRLG`の分岐を保持）。
- 技名・道具名は既訳（いあいぎり、かいりき、ロッククライム、アズサユミ、フェンタニル、スナッチマシン）。地名Ashlandsは地図データが未訳のため「アッシュランド」を暫定で辞書に登録した。
- クエスト日誌は原文の陰りのある語り（"The world, briefly, asks nothing of you."など）を保った。
- `gText_FollowerDefault`（"ERROR 404: Script not found."）は開発用の表示なので英語のまま残した。
- 幅は27マス（216px）に対して変数を長めに見積もって検査し、長くなりうる2行に改行を入れた。

## 検査

lint候補0件。

yomiyasu-check: executed via=verify run=20261025T220623Z-5fdfbb2c attempt=1 final=sha256:360702a97b16 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

カタログ検証成功、自動テスト37件成功。ビルドは次のストーリーバッチとまとめて行う。ゲーム画面での表示は未検証。
