# yomiyasuの導入と使い方

ユーザーの指定により、[nanaism/yomiyasu](https://github.com/nanaism/yomiyasu)の
2.4.0を`.agents/skills/yomiyasu`へ導入した。次のターンからもプロジェクトのスキルとして利用できる。
コミット`552c12c472ddfb79e2ee7a15219847782686a945`に固定し、ファイルのSHA256を
`yomiyasu.lock.json`に記録した。MITライセンスとUnicodeの利用条件も同梱している。

これはAIが生成した日本語を見直すためのスキルである。ゲームのフォント、漢字表示、
自動翻訳、レイアウト検証は別に実装・確認する必要がある。

## このゲームでの扱い

台詞にはscript、伝承の語りにはscriptまたはessayの指針を使い、口調・反復・比喩・
言い切りの強さを保つ。文末の句点はゲームの表記として残す。UIとクエスト目的は別に読む。
検出候補を消すことを目的に、固有名詞や登場人物の語りを書き換えない。

1. カタログから英語原文と日本語の下書きを用意する。制御コードを含むバッチは別に保管する。
2. 推敲用に可視テキストを抜き出す。ID・台詞順・話者の対応を残す。
3. スキルを読み、下書きをlintしたうえで、英語原文と意味・口調を照合する。
4. 最終稿を別ファイルに保存し、runで検査する。候補の扱いを記録する。
5. verifyで最終稿のハッシュを照合する。検査が通ったことを翻訳品質の保証とは扱わない。
6. ゲーム用バッチと最終稿が一致するか確認し、update_catalog.pyで適用する。
7. 制御コード・字形・文字幅・ビルドを検査し、別途ゲームで表示と進行を確認する。

```sh
python3 .agents/skills/yomiyasu/scripts/yomiyasu_lint.py DRAFT --doc-type script
python3 .agents/skills/yomiyasu/scripts/yomiyasu_check.py run \
  --source DRAFT --final FINAL --material ENGLISH --doc-type script --state-dir /tmp/wishes-yomiyasu
python3 .agents/skills/yomiyasu/scripts/yomiyasu_check.py verify \
  --final FINAL --state-dir /tmp/wishes-yomiyasu

python3 tools/localization/update_catalog.py localization/batches/munen-village-02.json
python3 tools/localization/update_catalog.py localization/batches/munen-village-02.json --apply
```

`DRAFT`、`FINAL`、`ENGLISH`は実際のファイル名に置き換える。
run/verifyはスキルに同梱されたCLIから実行する。状態ディレクトリには全文が保存されるため、
ローカルの作業フォルダを使う。今回の記録は作業フォルダのartifacts/yomiyasu-stateとlogsに保存した。
Gitには最終稿・英語資料・バッチ・レビュー判断・ハッシュを残す。
スキルを更新するときは、取得先・差分・ライセンスを確認し、lockも更新する。

## 今回の結果

[ムネン村21件のレビュー](reviews/munen-village-02.review.md)を実施した。
下書きを読み直し、lintの句点候補1件は既存ゲーム表記として維持した。下書きから最終稿への変更は0件。
runとverifyの記録は残しているが、これだけで意味や読みやすさの合格を示すものではない。
カタログへの追加21件を適用し、合計149件になった。制御コードと静的幅検査、ビルドは成功した。
漢字、日本語名前入力、全編翻訳、実プレイによる検証は引き続き未完了である。
