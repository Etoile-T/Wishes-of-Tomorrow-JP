# 手持ち一覧のLvが「ゃ」になる問題

2026-10-29。GitHub main 4579067b65から取得した独立チェックアウトで修正。旧Desktop/Wishは見つからず、作業場所はDocuments/Codex/Wish/Wishes-Game。ユーザーの既存ROM・セーブは変更していない。

原因: charmap.txtのLVと「ゃ」はともに0x34。src/strings.cのgText_LevelSymbol/gText_Lvに{JPN}{LV}{ENG}が入り、手持ち一覧DisplayPartyPokemonLevel・ステータス・育て屋で日本語の「ゃ」を描いていた。両文字列を{ENG}{LV}{ENG}へ修正。かなフォント/描画エンジン/文字幅/ゲームロジック/セーブ構造は変更しない。カタログ2IDと既存バッチdialogue-c-strings-118も同期。新規の日本語訳文は作成していないため、yomiyasuによる新規翻訳レビューの対象はない。

実preprocの出力: 修正前FC 15 34 FC 16 FFは「ゃ」と完全一致。修正後FC 16 34 FC 16 FFで英語LVを指定。新規OBJ_DIR=build/emerald-jp-lv143-clean、FILE_NAME=pokeemerald-jp-lv143でビルド成功。ROM使用29,453,444B、EWRAM230,024B、IWRAM28,600B。

ビルドROM内のシンボルgText_Lv(0x08ca1274)とgText_LevelSymbol(0x08ca5ccc)でFC 16 34 FC 16 FFを直接照合。両モード指定だけを旧値15へ戻した検証用コピーのSHA256は310c35cbc1e3e9563b81ab6420843a342e7c8d83437c387c65be1e9218e712bfで旧61,722件版と一致。修正版との差は2バイトのみ。

catalog validate成功、61,722件すべてtranslatedのまま。83テスト成功・skip0（初回はpreproc未生成で点字1件skip、生成後に全83件を再実行して成功）。audit推定超過0。新GBA SHA256 eb014715c59ba437b39c22a15795fb1ce77c2302b069ea2bbf697c502a5319f0 / CRC32 abd9b150。

ゲーム画面・手持ち操作・ステータス・育て屋・セーブの実プレイ確認は未実施。前版のExcelは表示上の訳文は同じだが、制御付き生訳2件に旧JPN指定が残るため未同期。カタログとバッチが正しい値。新しいExcelを検証したとは報告しない。
