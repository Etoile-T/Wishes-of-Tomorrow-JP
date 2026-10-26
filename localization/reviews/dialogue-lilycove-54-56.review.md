# 会話54〜56

開始時HEAD331aa609ea・クリーン。status/stats61,722 / 11,984 / 49,738一致。百貨店3Fの独自10行、百貨店1F/5F/屋上・港・わすれオヤジ・ポケモンセンター・民家1/2/4の128行、宿1F/2Fの90行、計228行を追加し12,212件。対象12スクリプトはカタログpending0。全ストーリーの完了や実プレイ上の到達性を意味しない。

PAWは既訳マンキーのて、補正の重複とマイナス12〜プラス12の範囲を維持。include/config/pokemon.hのPAW_MOD_CAP=12とparty_menu.cのPawApplyStatで正負の制限を確認した。原文は「Each WISH comes with a BOON」と恩恵を述べる一方、実装では別の能力が低下する。翻訳側でBOONを「のろい」に勝手に変更せず「おんけい」と訳し、その後のリスクを問う台詞も残した。原作者の意図は未確認。独自用語3件を暫定登録し110語。原文wtfの苛立ちを「くそっ」で残した。bananasは狂乱の慣用表現として「とんでもなく おかしく なっちゃった」と訳した。

わすれオヤジの変数2つの確認文は、各変数10マスの見積もりで27マスだった。「か」だけ省いて26マスにし、Hm!の感嘆符を保持。店員の敬体と住民の常体は人物が異なるので統一せず、指示語は同一メッセージのセール・チケット・技・渡す道具・惑星を指すため維持。ワイヤレスの「思う」、海溝の伝聞、屋上閉鎖の推測、宿泊客の会社についての推測、エニシダのコンテスト戦略の意見などの確度を保持。パートナーと道具の否定対比は原文の主張として残す。マリルリ、カクレオン、エニシダ、タイドリップごうは既訳の用語を使用。

宿はテレビニュースに反応する分岐、アクア団アジト前後、ゲームフリーク、図鑑完成報酬、各スタッフ、うきわガール/ふたごちゃんを好む人物、エニシダの居眠りとバトルへの好みを原文どおり訳した。元の会話をWishes独自の設定へ勝手に統一していない。

yomiyasuをscript指定でrun（lint/diff/materials）→指摘確認→verify。54は俗語を原文へ合わせて校正、55は上記の幅調整、56は原文と照合して初稿を維持。指示語・敬体混在の候補は前述の理由で保持。句点はプロジェクト指定として維持。lint0、meaning_risk0は翻訳の意味・読みやすさの保証とは扱わない。

yomiyasu-check: executed via=verify run=20261026T200445Z-59008117 attempt=1 final=sha256:5e25e26c0c60 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

yomiyasu-check: executed via=verify run=20261026T200446Z-7b66bbce attempt=2 final=sha256:470f8c25b354 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

yomiyasu-check: executed via=verify run=20261026T200446Z-71cf478d attempt=1 final=sha256:9a4fbb2166e7 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

script_batch→check bad0/width26マス超0→update_catalog dry-run/apply→catalog validate、audit推定超過0、75テスト成功。12スクリプトの.string以外の行は開始時と完全一致。改ページ・スクロール・終端・変数を元行に保持。ゲームロジック・イベントフラグ・セーブ構造は変更していない。実画面・店/船/AM/PAW/技忘れ/図鑑報酬/進行/保存再読み込みは未検証。

成果物: ../outputs/gba/wishes-jp-12212-b632ef42.gba（SHA256 db0bb183feb169ff3ae6793b184a9a5b02ea0f8456a42ebbe952aac92cbf4c66）。新規OBJ_DIR build/emerald-jp-dlg12212-cleanでビルド成功。ROM29,852,136B/EWRAM230,024B/IWRAM28,600B。BPS再適用後のSHA/CRCとバイト列が一致。Excel14シート・62,429行11列の原文/訳文/ID/状態/メモ、110用語、目次62,429/12,919/49,510を保存後照合し一致。検査ログ ../artifacts/logs/excel-types-12212-verify.log。旧保存メモ0件も維持。Excel実アプリとゲーム実画面は未確認。
