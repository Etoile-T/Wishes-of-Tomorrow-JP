# 会話79〜108: バトルフロンティア・カントー（FRLGマップ）・共通テキスト（data/text・data/scripts）

開始21,983/39,739。フロンティア7＋カントー12＋共通テキスト22バッチ、計27,990行をClaude Codeのサブエージェントが並列で下書きし、主セッションが検査・表記統一・適用。49,973/11,749。ストーリー範囲（data/maps・data/text・data/scripts）の未訳は意図的に英語のまま残した129件のみ:
- data/text/braille.inc 87行: .brailleは英字・記号しか点字に変換できず（tools/preprocのReadBraille）、かなを入れるとビルド不可。点字表の拡張は別判断。
- data/text/new_game_intro_frlg.inc の名前候補42件: IS_FRLGビルド専用（Emeraldでは未到達）で、名前欄はJPN_NAME系の専用制御を使う。{JPN}付きのかな名を入れると保存形式と食い違うおそれがあるため不採用。

主な判断・統一:
- フロンティアの挑戦名は参考訳に統一: バトルトレード / かちぬきチームバトル / バトルゲーム / バトルアドベンチャー（ラウンジ・テレビ・バトルテントの訳を置換）。
- カントーのジム看板「WINNING TRAINERS:」は「しょうりした トレーナー:」、「TRAINER TIPS」は既訳「おとくな けいじばん!!」に統一。カントーのダブルバトル話者名をマップとtrainers_frlgで統一（エバ・イブ・ニャ・レア）。TEALAはテアラ。
- カントー公式名（オーキドはかせ、ナナミ、マサキ=関西弁、ニシキ、サカキ、四天王、各ジムリーダー、ゴールドバッジ等）に準拠。FRLG原文に残っていた日本語行は全角空白/！を半角にしただけで文面は維持。
- 性別別の台詞（ぼうや/おじょうちゃん）は原文の分岐どおり。性別不明の話者に「ぼく」「ぜ」を付けない。「ぼうや」の決めつけは修正。
- 変数を英語と同じ行に残す制約のため語順を倒置した行、26マスに収めるため語を省いた行がある（各サブエージェント報告。例: タイムボード、EGGS{STR_VAR_1}、記録保持者）。
- 「タマゴ{STR_VAR_1}」系の文はsrc/strings.c・battle_message.cの未訳部品（are inelegible / gText_Are）に続くため、部品の翻訳時に接続を要確認。
- 弟子（apprentice）の台詞は3チャンクに分かれて訳したため、同一弟子の一人称がチャンク間で揺れている可能性がある（要見直し）。
- テレビ番組の秘密基地グッズ名は仮表記（decoration側が未訳）。インチ表記は原文どおり残した箇所と70センチ換算した箇所がある。
- 新しい暫定表記はglossaryに追加。

yomiyasu: 全バッチでlint→run→verify実行（mode=compose、資料=英語）。lint候補は表札/見出しの末尾コロン、♂♀、実在のゲート等で維持。meaning_riskの多いバッチ（マルチパートナー52、エントリーコール34/58、テレビ39、名声チェッカー58）は定型文の反復・変数・数値で、抜き取りで英語と照合。自動検査は意味保持の合格証明ではない。

check bad0・26マス超0（全41バッチ）、catalog validate成功、audit推定超過0、78テスト成功、ビルドexit0（ROM29,576,456B/EWRAM230,024/IWRAM28,600）。ロジック/フラグ/セーブ構造は不変（.string行のみ）。実ゲームの画面・進行・保存は未検証。

各verify行:
- frontier-multipartner-79: yomiyasu-check: executed via=verify run=20261027T024139Z-53e305e5 attempt=1 final=sha256:e1ac50747ffa mode=compose doc_type=script checks=lint,diff,materials meaning_risk=52 replay=skipped
- frontier-tower-pyramid-80: yomiyasu-check: executed via=verify run=20261027T024141Z-cfe4e333 attempt=1 final=sha256:70e274ed2f29 mode=compose doc_type=script checks=lint,materials meaning_risk=5 replay=skipped
- frontier-pyramid-pike-81: yomiyasu-check: executed via=verify run=20261027T024141Z-442c4d8c attempt=1 final=sha256:3e81766e9910 mode=compose doc_type=script checks=lint,materials meaning_risk=18 replay=skipped
- frontier-palace-arena-82: yomiyasu-check: executed via=verify run=20261027T024142Z-a0efd550 attempt=1 final=sha256:107ec34748da mode=compose doc_type=script checks=lint,materials meaning_risk=7 replay=skipped
- frontier-dome-factory-83: yomiyasu-check: executed via=verify run=20261027T024143Z-d1d91987 attempt=1 final=sha256:a69640ee03f5 mode=compose doc_type=script checks=lint,materials meaning_risk=6 replay=skipped
- frontier-lounges-84: yomiyasu-check: executed via=verify run=20261027T024143Z-37b7ceeb attempt=2 final=sha256:06295d4f5328 mode=compose doc_type=script checks=lint,materials meaning_risk=4 replay=skipped
- frontier-outside-85: yomiyasu-check: executed via=verify run=20261027T024144Z-da4e1cee attempt=1 final=sha256:1ceed624977c mode=compose doc_type=script checks=lint,materials meaning_risk=6 replay=skipped
- kanto-86: yomiyasu-check: executed via=verify run=20261027T024145Z-a45b042e attempt=1 final=sha256:a2277e6c6883 mode=compose doc_type=script checks=lint,materials meaning_risk=12 replay=skipped
- kanto-87: yomiyasu-check: executed via=verify run=20261027T024146Z-144a526b attempt=1 final=sha256:b0f8cbd9d023 mode=compose doc_type=script checks=lint,materials meaning_risk=7 replay=skipped
- kanto-88: yomiyasu-check: executed via=verify run=20261027T024146Z-66d43f18 attempt=1 final=sha256:737a97183ea9 mode=compose doc_type=script checks=lint,materials meaning_risk=9 replay=skipped
- kanto-89: yomiyasu-check: executed via=verify run=20261027T024147Z-16d16f65 attempt=1 final=sha256:eaa487ff3984 mode=compose doc_type=script checks=lint,materials meaning_risk=3 replay=skipped
- kanto-90: yomiyasu-check: executed via=verify run=20261027T024148Z-e2145c8c attempt=1 final=sha256:277f20923dc4 mode=compose doc_type=script checks=lint,materials meaning_risk=7 replay=skipped
- kanto-91: yomiyasu-check: executed via=verify run=20261027T024148Z-1991c04e attempt=1 final=sha256:1af755d9ad4f mode=compose doc_type=script checks=lint,materials meaning_risk=6 replay=skipped
- kanto-92: yomiyasu-check: executed via=verify run=20261027T024149Z-c394fdb1 attempt=1 final=sha256:cdcf0bf3c43d mode=compose doc_type=script checks=lint,materials meaning_risk=3 replay=skipped
- kanto-93: yomiyasu-check: executed via=verify run=20261027T024150Z-63b44bed attempt=3 final=sha256:eff3cfa52384 mode=compose doc_type=script checks=lint,materials meaning_risk=2 replay=skipped
- kanto-94: yomiyasu-check: executed via=verify run=20261027T024150Z-0fcf83db attempt=1 final=sha256:6bfae2ff7126 mode=compose doc_type=script checks=lint,materials meaning_risk=10 replay=skipped
- kanto-95: yomiyasu-check: executed via=verify run=20261027T024151Z-a9effced attempt=1 final=sha256:8013d77a72fa mode=compose doc_type=script checks=lint,materials meaning_risk=7 replay=skipped
- kanto-96: yomiyasu-check: executed via=verify run=20261027T024152Z-7ab3139f attempt=3 final=sha256:3908fd64ca9c mode=compose doc_type=script checks=lint,materials meaning_risk=7 replay=skipped
- kanto-97: yomiyasu-check: executed via=verify run=20261027T024152Z-7c8aecd6 attempt=2 final=sha256:f4966534a2ad mode=compose doc_type=script checks=lint,materials meaning_risk=6 replay=skipped
- text-trainers-98-a: yomiyasu-check: executed via=verify run=20261027T025349Z-efe4e459 attempt=1 final=sha256:6ce1c9fbd3b2 mode=compose doc_type=script checks=lint,materials meaning_risk=6 replay=skipped
- text-trainers-98-b: yomiyasu-check: executed via=verify run=20261027T025349Z-e54498ab attempt=1 final=sha256:d94d78347018 mode=compose doc_type=script checks=lint,materials meaning_risk=0 replay=skipped
- text-trainers-98-c: yomiyasu-check: executed via=verify run=20261027T025350Z-af6b7d3e attempt=1 final=sha256:d47017c163d5 mode=compose doc_type=script checks=lint,materials meaning_risk=5 replay=skipped
- text-trainers-98-d: yomiyasu-check: executed via=verify run=20261027T025351Z-b61efbcf attempt=1 final=sha256:f918e3054d06 mode=compose doc_type=script checks=lint,materials meaning_risk=0 replay=skipped
- text-matchcall-99-a: yomiyasu-check: executed via=verify run=20261027T025352Z-85a4d7b6 attempt=1 final=sha256:503a660b425a mode=compose doc_type=script checks=lint,diff,materials meaning_risk=34 replay=skipped
- text-matchcall-99-b: yomiyasu-check: executed via=verify run=20261027T025353Z-5affeeef attempt=1 final=sha256:3634fcea0d67 mode=compose doc_type=script checks=lint,diff,materials meaning_risk=58 replay=skipped
- text-matchcall-99-c: yomiyasu-check: executed via=verify run=20261027T025355Z-b5629fc2 attempt=1 final=sha256:883212ba759b mode=compose doc_type=script checks=lint,materials meaning_risk=2 replay=skipped
- text-tv-100-a: yomiyasu-check: executed via=verify run=20261027T025355Z-8704f968 attempt=1 final=sha256:097cbe8f1545 mode=compose doc_type=script checks=lint,materials meaning_risk=1 replay=skipped
- text-tv-100-b: yomiyasu-check: executed via=verify run=20261027T025356Z-4680a592 attempt=1 final=sha256:87f6f25e138f mode=compose doc_type=script checks=lint,diff,materials meaning_risk=39 replay=skipped
- text-tv-100-c: yomiyasu-check: executed via=verify run=20261027T025358Z-c3b721fe attempt=1 final=sha256:2fafb3ee0c39 mode=compose doc_type=script checks=lint,materials meaning_risk=3 replay=skipped
- text-apprentice-101-a: yomiyasu-check: executed via=verify run=20261027T025358Z-908cfc0c attempt=1 final=sha256:283130d27dad mode=compose doc_type=script checks=lint,materials meaning_risk=3 replay=skipped
- text-apprentice-101-b: yomiyasu-check: executed via=verify run=20261027T025359Z-7d50500a attempt=1 final=sha256:705bb3a03d7f mode=compose doc_type=script checks=lint,materials meaning_risk=1 replay=skipped
- text-apprentice-101-c: yomiyasu-check: executed via=verify run=20261027T025400Z-2d5f5130 attempt=1 final=sha256:a90459bc0f7f mode=compose doc_type=script checks=lint,materials meaning_risk=2 replay=skipped
- text-famechecker-102: yomiyasu-check: executed via=verify run=20261027T025401Z-257587c0 attempt=1 final=sha256:c42d52203c53 mode=compose doc_type=script checks=lint,diff,materials meaning_risk=58 replay=skipped
- text-trainersfrlg-cable-103: yomiyasu-check: executed via=verify run=20261027T025402Z-79abdf41 attempt=1 final=sha256:4db415b517ed mode=compose doc_type=script checks=lint,materials meaning_risk=7 replay=skipped
- text-mauvilleman-tent-104: yomiyasu-check: executed via=verify run=20261027T025403Z-6c2288ef attempt=1 final=sha256:42216c2a1027 mode=compose doc_type=script checks=lint,materials meaning_risk=3 replay=skipped
- text-cablefrlg-contest-debug-105: yomiyasu-check: executed via=verify run=20261027T025404Z-4ce5cc3c attempt=1 final=sha256:00e628cb6b0e mode=compose doc_type=script checks=lint,materials meaning_risk=14 replay=skipped
- text-misc1-106-a: yomiyasu-check: executed via=verify run=20261027T025405Z-c2c8ebd7 attempt=1 final=sha256:87465f1b2630 mode=compose doc_type=script checks=lint,materials meaning_risk=4 replay=skipped
- text-misc1-106-b: yomiyasu-check: executed via=verify run=20261027T025405Z-518a0510 attempt=1 final=sha256:ffe417d8d480 mode=compose doc_type=script checks=lint,materials meaning_risk=0 replay=skipped
- text-misc2-107-a: yomiyasu-check: executed via=verify run=20261027T025406Z-a19b478a attempt=1 final=sha256:45ac5382730e mode=compose doc_type=script checks=lint,materials meaning_risk=6 replay=skipped
- text-misc2-107-b: yomiyasu-check: executed via=verify run=20261027T025407Z-99079765 attempt=1 final=sha256:7f3bdcd72902 mode=compose doc_type=script checks=lint,materials meaning_risk=0 replay=skipped
- text-misc3-108: yomiyasu-check: executed via=verify run=20261027T025407Z-4cbfa50b attempt=1 final=sha256:4d99a781cbdd mode=compose doc_type=script checks=lint,materials meaning_risk=3 replay=skipped
