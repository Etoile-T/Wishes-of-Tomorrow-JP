# ストーリー序盤（話者名・ムネン周辺・自宅・ムネントンネル）

2026-10-26。話者名29件（3件は原文維持）、台詞373行。

- speaker-names-09: 会話の上に出る名前ボックス（`src/data/speaker_names.h`）。最大12タイル（`OW_NAME_BOX_DEFAULT_WIDTH`）、日本語は12文字以内。幅は`GetStringWidth`で計算される。`{PLAYER}`と、オンライン上のハンドル名と見られるRedFatality・Yifferは原文のまま。戦闘の名前プレート（`trainers.party`の名前）は未訳なので、表示がそろわない時期がある。
- dialogue-munen-area-10: メルティングマイル、ムネンこ、フロストウッドタウン、フロストウッドの家。
- dialogue-players-house-11: 自宅1F/2F（ミシロの家を流用。元の台詞も出る可能性があるため全文）と、研究所のWishes独自の2メッセージ。研究所のほかの元エメラルドの台詞は未訳。
- dialogue-munen-tunnel-12: ムネントンネル、ノースウィンドどうくつ。

## 判断

- 話者の書き方は既訳のムネン村に合わせて「名前: 本文」とした。電話の『』は使わない（適用済みの博士の電話も修正した）。
- 口調を保った。釣り人の罵り言葉（"Holy fuck"）は「マジかよ」「クソ」「やってらんねえ」、手下は乱暴な口調、マコーミックたいちょうは軍人の口調、老人は「〜じゃ」。
- リョウコの手紙は段落ごとに「」で囲んだ。性別が分からないため一人称は「わたし」にした。
- 新しい固有名詞（ドラコ、エンバーバッジ、メルティングマイル等）はglossaryに暫定（provisional）で登録した。地図上の地名データ（`region_map_sections.json`）は未訳。
- `{REGION}`などFD系の差し込みも`{ENG}…{JPN}`で囲むよう`script_batch.py`を拡張し、テストを追加した。
- `\l`は保護対象なので、原文にない位置には足していない。長い行は内容を保ったまま短くした。

## 検査

lint候補0件。

yomiyasu-check: executed via=verify run=20261025T221304Z-a5730fd3 attempt=1 final=sha256:da1568d2c45c mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

カタログ検証成功、自動テスト38件成功、ビルド成功（ROM 29,891,912B、EWRAM 230,024B、IWRAM 28,600B）。幅は1行27マスに対して変数を長めに見積もって検査した。ゲーム画面での表示は未検証。
