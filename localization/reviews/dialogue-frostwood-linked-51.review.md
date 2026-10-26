# 会話バッチ51

開始時HEAD d402c37619・クリーン、status/stats61722/11228/50494一致。ユーザーのストーリー全訳目標を維持し再開。

元のマップ名を流用したWishes独自イベント6マップ48メッセージ199行。SeafloorCavern_Entranceの赤いギャラドス、OldaleTown_House2のジムリーダーの家族とホットココア、OldaleTown_Martのドラコとスキー客、OldaleTown_PokemonCenter_1Fのならず者とセンネン案内、Route112_CableCarStationのゴンドラ、RustboroCity_GymのRedFatalityの初ジム・列車解放・電話を含む。旧ラベルRoxanneをツツジへ訳さない。実際の英語はRedFatalityなので固定のLatin表記を保つ。
フロストウッドタウン／ドラコ／エンバーバッジ／センネンせん／しんかんせんは既訳辞書、ハイパーボール／ルリリ／ウインディ／キズぐすりは既訳名称と照合。Halo 3・MLG・Instagram・DM・スイスアルプス等は原文の固有名や用語を保持。スキーのtwigsは「2ほんのぼっきれ」で比喩、switch540/powderも原文どおり保持。YiffはNPCの不透明な掛け声として「イフ」と音写し、動物の鳴き声等に勝手に差し替えない（暫定用語として辞書に記録）。GTFO/MUKの乱暴な口調とベトベトンへの例えは丸めず残す。
Don't get comfortableは「自分はくつろがない」ではなく相手への牽制「いいきになるなよ」へ修正。genuine articleは「まちがいなくほんものだ」へ明確化。yomiyasuのtrailing_colon警告1件は公認トレーナー一覧の見出しで、次行にPLAYERが続くので維持。敬体は駅員、常体は他NPCの発話なので統一しない。

yomiyasu script lint/run/verify実施。原文と英日を読んで確認。指示語は同一メッセージの前後を指すため保持。meaning_risk=0は翻訳の正確性の保証とは扱わない。

yomiyasu-check: executed via=verify run=20261026T110325Z-248a8e77 attempt=2 final=sha256:4870f8975d70 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

script_batch→check bad0/width26マス超0→update_catalog dry-run/apply。校正後のバッジ文1件も小さなIDバッチで再適用し、元バッチと一致。catalog validate・audit推定超過0・59テスト成功。7スクリプトの.string以外は開始時と完全一致。名前・数字・変数・改ページ・スクロール・終端の行位置を保持。ゲームロジック・イベント・セーブ構造は不変。実画面・進行・電話・報酬は未検証。
