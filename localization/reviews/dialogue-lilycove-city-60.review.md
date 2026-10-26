# 会話60 — ミナモの街本体

開始時HEADf453861b4b・クリーン、status/stats61,722 / 12,795 / 48,927一致。LilycoveCity/scripts.incの239行を追加し13,034件。LilycoveCity*の全スクリプトにカタログpendingは残らないが、未抽出文字列/到達性/実画面の網羅を意味しない。

参考同形候補74行を全文英語と照合し編集、残り165行は新訳。reference.tsvを保存し、参考74行はJP b07a7ec5f798ebc4cf3641613bbd8ddbb9b6f5ef/英語Expansion b669d9ccf9c148070b99eba11cd65f6071be0741をprovenanceへ記録。ハルカ/ユウキの買い物・対戦前後・帰郷・バッジ/リーグ/フロンティアの分岐、アクア団とホエルコの封鎖前後、盗難ポケモン、画商、老夫婦、看板、きのみブレンダー、そらのはしらと新婚旅行の会話を保持。

「Cove Lily Motel」は参考JPの同ラベルで「みんしゅく モナミ」を確認し採用（初稿のミナモホテルは破棄）。Sky Pillar=そらのはしらも参照し、シリーズ用語2件を追加して117語。ハルカ/ユウキ、ミシロ、アクア団等を原文の固有名どおり訳し、原文に残る古い地名・人物をWishesの別設定に勝手に統一していない。ハルカの心配する相手を示す文を自然な語順へ直し、PLAYER/KUNは元行を維持。KUNの幅を疑ってsrc/strings.cを確認したが、展開文字列は現実装では空なので幅推定ツールを変更していない。

原文I know I'll get the chanceの断言が、参考では「できそう」と弱まっていたので、チャンスが来るという発言へ戻した。If the world becomes ours, it will be happierの仮定を残し、比較級の「もっと」を保持。追い払われたアクア団の事実に参考が足した「らしい」は削除した。コンテストに来るポケモンはfrom all over the countryなので「ぜんこくから」を保持。画商は絵を描く人ではなく買って売る人で、初稿の「かいたり」は「かったり」に修正。老夫婦の60年前と海の生命の比喩、工事中の船の運航予定、そらのはしらの伝聞などの確度・数量を保持。

yomiyasu script run（lint/diff/materials）→全候補確認→verify。lint0、meaning_risk=2は両方を原文と照合して保持した。1件は上記I know/I'llの確度、もう1件はworld becomes oursという仮定内のwillの表現を参考の「はず」から戻したもの。警告をゼロにするために英語の確度を弱めない。新語チャンスはchance、モナミは参照日本語が根拠。人物/看板の敬体混在は維持し、指示語は同じ話題や相手を受ける。句点はプロジェクト指定で保持。意味リスクの数は正確性の合否ではなく、今回2件が未解決という意味でもない。

yomiyasu-check: executed via=verify run=20261026T203539Z-6e01f812 attempt=1 final=sha256:39a4373d852f mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=2 replay=skipped

script_batch→check bad0/width26マス超0→update_catalog dry-run/apply→catalog validate、audit推定超過0、78テスト成功。対象ファイルの.string以外の全行は開始時と完全一致。変数/改ページ/スクロール/終端は元行に保持。ゲームロジック・イベントフラグ・セーブ構造は変更していない。実画面・ライバル戦・封鎖/解放・船・施設・進行・保存再読み込みは未検証。
