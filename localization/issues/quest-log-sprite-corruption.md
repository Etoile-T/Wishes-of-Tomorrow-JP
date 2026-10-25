# クエストにっし使用後のスプライト崩れ

2026-10-26。状態: **未解決・再現条件の切り分け中**。

ユーザー画像ではプレイヤーに似たキャラクターが上下に表示され、上側の周囲に黒い画素が見える。ユーザーはQuest Logを使用した後に発生したと回答。上側が本来どのオブジェクトか、使用ROMのハッシュ、通常レポートかステートから開始したかは未確認。連れ歩き個体と断定しない。

## 確認したソース

ItemUseOutOfBattle_QuestLog → SetUpItemUseOnFieldCallback → ItemUseOnFieldCB_QuestLog → EventScript_QuestLog。日誌アイテムはdata/scripts/quests.incの会話を表示する。スタートメニューから開くquests.cの専用UIとは経路が違う。

src/sprite.c、event_object_movement.c、decompress.c、overworld.c、follower_npc.cの5ファイルは英語ソーススナップショット23be896714と差分なし。フィールドのキャラクター画像・パレットも日本語化で置換していない。これだけで翻訳由来のメモリ破損等を排除したことにはならない。

圧縮シートの読み込み失敗時に無効なタイル開始値を使いうる経路、不可視設定を後続の可視性更新で戻す経路が既存コードにある。ただし今回それが発生した証拠はなく、推測でスプライトを隠す変更やゲーム機能の削除はしていない。

## ROM上書きについて

作業中、ビルド後にartifacts/wishes-jp-wip.gbaへ繰り返しコピーしていた。ユーザーがこのファイルを読み込み中だったかは未確認。mGBA 0.10.5は通常サイズのROMをファイルからmapする実装で、POSIX側はMAP_PRIVATEを使う。

- [GBA ROM読込](https://github.com/mgba-emu/mgba/blob/0.10.5/src/gba/gba.c#L371)
- [POSIXファイルマップ](https://github.com/mgba-emu/mgba/blob/0.10.5/src/util/vfs/vfs-fd.c#L125)

ただし、この環境のPythonによる32MiBファイルのPRIVATEマッピングをshutil.copyfileで上書きする簡易テストでは、マッピングは元の内容を維持した。**今回の画像の原因がROM上書きだとは確認できていない。** mGBA上での再現テストでもない。

今後の混同・上書きを避けるためexport_play_rom.pyを追加。完成した一時inodeを新規ハッシュ名へlinkで公開し、既存名の置換を拒否する。読み込み済みマッピングとセーブを維持するテスト、壊れたヘッダーを拒否するテストが成功。全自動テスト28件成功。ゲーム本体のコード変更はしていないため、この対応を画面不具合の修正とは扱わない。

## 現在の確認用ROM

ソース: UI翻訳コミットdf53e420d1のビルド。

SHA256: f3e400a69b9cf96fc919f554656374b2ac10d20eb60a96a52ef9693a3e901432

ローカル: artifacts/play/wishes-jp-f3e400a69b9cf96f.gba

バイト列は前回ビルド済みROMと同じ。新たなゲーム修正ROMではない。セーブファイルは移動・複製・上書きしていない。

次の切り分けは、版固定ROMを開き直して通常のゲーム内レポートを読み込み、Quest Logを使う前後で比較すること。別ビルドのステートからの再開は比較対象にしない。再発するなら同版のセーブ・発生位置を基にOBJタイル割当とパレットを調べ、英語版の同条件と比較する。画像不具合が解決するまで翻訳の追加は止める。
