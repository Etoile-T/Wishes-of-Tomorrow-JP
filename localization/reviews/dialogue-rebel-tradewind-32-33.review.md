# レジスタンスのアジト・トレードウィンド周辺

2026-10-26。177＋232＝409件（カタログの行単位）。

## 対象と判断

- RebelHideout: ネッサの正体、助手のダークそうち・ジラーチの説明、リライブ・ハイパーモード・そらをとぶ・5匹のスナッチ依頼、クリア後のレジスタンスとの会話とジェット、ホテルZ裏口のDLC案内。
- TradewindTown / Lab / Gym / House / Apartment_2: 夜市と奇妙な商人、メガストーン交換、ツジふじんの試練・メガシンカ・バッジ、ゴーストの描写とトレーナー台詞、リダ・カナリィとの出会い、地下研究所、未亡人と空き部屋。
- 主人公の性別は指定しない。話者プレートがある台詞には名前を重複追加していない。ネッサは既存の人物設定と原文の軽口に合わせ、助手は簡潔な研究者口調、ゲンは老人の口調、エドワーズは軍人口調を維持。
- `at her shoulder` はゾロアークが肩に乗ると断定せず「その わきで」にした。`resist the process` は加工に耐えるのでなく抵抗する意味で訳した。
- ダメージ増加20％、防御低下20％、リライブ後の攻撃増加と副作用なし、5匹、3年、12年、140年、109番目、1000円の数値を原文と照合。
- Shadow Logはメニューの短い「にっし」と対応させ「ダークにっし」とした。群島の海図、ランタンバッジ／ジム、ハイパーモード、あの世との境界も暫定用語として辞書に追加。
- ツジの敗北時 `The bond broke my way this time` は、敗北なのに自身に有利な表現になっている。勝手に原文の勝敗を訂正せず「きずなが わたしに みかたした」として原文の違和感を残した。作者意図は未確認。
- 夜市の不気味な比喩・霊の取引・109番目のランタンなど、意図的に説明されない部分を補足していない。翻訳しやすさのために台詞を削っていない。

## yomiyasu

script / essayの指針で英語資料と読み比べ、lint → run → verify。ゲーム内句点はプロジェクトの指定で維持。

RebelHideout: 見直し候補0件。最終稿でダークログをダークにっしに変更し、再検査。

`yomiyasu-check: executed via=verify run=20261025T234449Z-7205b8b8 attempt=2 final=sha256:1a05cf23ff42 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped`

Tradewind: 見直し候補1件（ゴースが「あなたではなく みなもの あなた」に笑う否定対比）。原文の `instead of at you` を保つため維持。

`yomiyasu-check: executed via=verify run=20261025T234501Z-d92376ef attempt=1 final=sha256:930b17a2c0ae mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped`

検査の候補数は品質の点数ではない。意味保持・画面表示の合格や人間の承認を示すものではない。

## 検査範囲

script_batchで全文単位のバッチを生成し、dialogue_tools checkは両バッチbad 0、widthは26マス超0。変数の言語切替を含めた値で検査した。変数展開後の実表示・実機・イベント進行は未検証。ビルド等の最終結果はstatus.jsonとHANDOFF_CODEX.mdに記録する。
