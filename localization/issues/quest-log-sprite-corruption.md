# クエストにっし使用後のスプライト崩れ

2026-10-26。状態: **未解決・再現条件の切り分け中**。

ユーザー画像ではプレイヤーに似たキャラクターが上下に表示され、上側の周囲に黒い画素が見える。ユーザーはQuest Logを使用した後に発生したと回答。上側が本来どのオブジェクトか、使用ROMのハッシュ、開始方法はゲーム内の「つづきから」と確認済み。ステートからの再開ではない。連れ歩き個体と断定しない。

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

## 診断用ビルドの準備

追加確認: ユーザーはゲーム内の「つづきから」で開始したと回答。ステート由来と決めつけない。

MakefileにWOT_SPRITE_DIAGNOSTICS（既定0）を追加し、1のときは出力名とオブジェクトディレクトリに-sprite-diagを付けて通常版と分離する。event_object_movement.cにはフィールド復帰開始/終了、各オブジェクトのgraphicsId/localId、画像ソース、圧縮有無、シートタグと割当、描画タイル、パレットを記録する条件付きDebugPrintfだけを追加した。キャラクターを隠す、削除する、種族を変える、セーブを書き換える処理はない。

```sh
make -j8 WOT_SPRITE_DIAGNOSTICS=1 TOOLCHAIN=/opt/devkitpro/devkitARM
python3 tools/localization/export_play_rom.py pokeemerald-sprite-diag.gba ../artifacts/quest-log-diagnostics
```

診断ROM SHA256: ce6414c508b8622de68583db5fce7f465e3a6b7c8861bc7e740405198b72795d

ローカル: artifacts/quest-log-diagnostics/wishes-jp-ce6414c508b8622d.gba

ビルド成功。ROM使用量29,898,760B、EWRAM230,024B、IWRAM28,600B。通常設定もFILE_NAME=pokeemerald-normal-checkの別名でビルド成功。通常版は従来版と32MiB中2バイトだけ異なり、差はsrc/event_object_movement.c:11543→11564という割当診断用のソース行番号文字列。その他はバイト一致。通常版の実行コード変更は検出しなかった。自動テスト28件・カタログ検証成功。

同梱headlessツールはstatus/quitを受け付けたがPC=0、Cycle=0のまま。reset/frame後も同じであり、実行テストの成功とは扱わない。

mGBAの状態確認を試みたが、自動承認レビューが過去の「mGBA停止・ソース優先」指示に反するとして拒否した。GUI操作は行っていない。次に必要なのは、この不具合に限った短いGUI再現とmGBAログの採取。ユーザーの明示承認を得るまで実行しない。診断用ROMは修正版ではなく、症状解決は未確認。

## 公式BPSの追加照合

ユーザー指定ファイル: artifacts/wishes-of-tomorrow-1.2.6.bps。

SHA256 05bf04c8ad2ad4e2da6a353a6d0ed234c44930a6ba1231ec9d0f2738dfb1ff54。公式v1.2.6タグ内docs/patches/wishes-of-tomorrow-1.2.6.bpsとバイト一致。BPS自体のCRCも正しい。入力16MiB・CRC32 1f1c08fb、出力32MiB・CRC32 f1eeea17。

タグは開発ワークスペースのコミット52ffb1cf827ab0fe905f5b2caa57d5116e276d23を指す。ゲームソースはそのsubmodule pokeemerald-expansionのe6f5b24e0af95d079cc3380a1bb895963c4bc05b。日本語化の基準efb1c880d0b486c1948763051b6c1bb8990a7353とは別版である。単純にワークスペースとゲームmasterをdiffすると全ソース追加と誤判定するため、submoduleの版を照合した。

こちらがソースから作った英語ROMは32MiB・CRC32 62ba561e、日本語ROMは32MiB・CRC32 50855cbd。両方とも公式1.2.6 BPSの入力条件に合わない。独自Python実装とRomPatcher.jsの両方でSource ROM checksum mismatch相当として拒否されることを確認。ユーザーが実際に検査を無視して適用したかは未確認で、画像不具合の原因を誤適用と断定してはいない。

日本語化BPS（7085491fb0606d2602d309b9e863e33abe2feabe9865940cd9d66f70bc1d673b）は、こちらの英語基準ROMを入力に、日本語UI版f3e400a6…へ変換するもの。公式1.2.6出力や市販Emeraldを入力にしない。

独立検証: RomPatcher.js 4f17297cd1dc0835a0b0747497fa15f5f63f1623でも、こちらの日本語化BPSを正しい英語基準ROMへ適用し、出力のSHA256と全バイトが直接ビルドした日本語ROMと一致した。ZIP内BPSも単体BPSと一致。これは変換の正しさであり、ゲーム内表示が正常という証明ではない。

[公式リリースノート](https://github.com/jmaloney95/Wishes-Game/blob/52ffb1cf827ab0fe905f5b2caa57d5116e276d23/release_notes_v1.2.6.md)、[独立パッチ実装](https://github.com/marcrobledo/RomPatcher.js/tree/4f17297cd1dc0835a0b0747497fa15f5f63f1623)を照合した。

取り違え防止: patch-manifest-ui5693.jsonとapply_verified_patch.pyを追加。入力ROM・BPS・出力ROMすべてをSHA256で検証し、不一致なら出力しない。CRC無視オプションはない。自動テスト31件成功。ローカルの版名付きパッチはartifacts/patches/ui-5693-50855cbd/。直接遊ぶROMは上記artifacts/play/のファイルで、追加BPSは不要。グラフィック問題は引き続き未解決として保持する。
