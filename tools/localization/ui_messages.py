#!/usr/bin/env python3
"""Exact UI/save/party/dex messages, reviewed against their English source."""
import json,re
import catalog
from ui_common import scoped

VOCABULARY = r'''
Would you like to save the game?$	ここまでのぼうけんを\nレポートにかきこみますか？$
There is already a saved file.\n	すでにレポートがかかれています。\n
Is it okay to overwrite it?$	うえからかきかえてもいいですか？$
SAVING…\n	レポートをかいています…\n
DON'T TURN OFF THE POWER.$	でんげんをきらないでください。$
{PLAYER} saved the game.$	{PLAYER}は\nレポートにしっかりかきのこした！$
WARNING!\p	ちゅうい！\p
There is a different game file that\n	すでにべつのぼうけんのレポートが\n
is already saved.\p	かきこまれています。\p
If you save now, the other file's\n	いまレポートをかくと まえのぼうけんの\n
adventure, including items and\l	きろくは どうぐやポケモンもふくめて\l
POKéMON, will be entirely lost.\p	すべてきえてしまいます。\p
Are you sure you want to save now\n	それでも まえのレポートをけして\n
and overwrite the other save file?$	うえからかきかえてもいいですか？$
Save error.\p	レポートのかきこみにしっぱいしました。\p
Please exchange the\n	バックアップメモリを\n
backup memory.$	こうかんしてください。$
Save completed.	レポートをかきおわりました。
Save failed…	レポートをかけませんでした…
Clear all save data areas?	すべてのきろくをけしますか？
Data will be saved.\nPlease wait.	レポートをかきます。\nしばらくおまちください。
Save completed.\nPlease press the A Button.	レポートをかきおわりました。\n{ENG}A{JPN}ボタンをおしてください。
There is already a saved file.\nIs it okay to overwrite it?	すでにレポートがかかれています。\nうえからかきかえてもいいですか？
{DYNAMIC 0} saved the game.	{DYNAMIC 0}はレポートをかいた。
The clock has been reset.\nData will be saved. Please wait.	とけいをあわせました。\nレポートをかくのでおまちください。
There is no save file, so the time\ncan't be set.	レポートがないため\nじこくをあわせられません。
The edited text will not be saved.	へんしゅうしたぶんしょうはほぞんされません。
The registered text has been changed.\nIs it okay to save the game?	とうろくしたぶんしょうがかわりました。\nレポートにかきこみますか？
Check completed.\nAttempting to save again.\nPlease wait.	かくにんがおわりました。\nもういちどレポートをかきます。\nしばらくおまちください。
The backup memory is damaged, or\nthe internal battery has run dry.\nYou can still play, but not save.	メモリのこしょうか でんちぎれです。\nあそぶことはできますが\nレポートはかけません。
Would you like to change {STR_VAR_1}'s\nability to {STR_VAR_2}?	{STR_VAR_1}のとくせいを\n{STR_VAR_2}にかえますか？
{STR_VAR_1}'s ability became\n{STR_VAR_2}!{PAUSE_UNTIL_PRESS}	{STR_VAR_1}のとくせいが\n{STR_VAR_2}になった！{PAUSE_UNTIL_PRESS}
{STR_VAR_1}'s base points\nwere all reset to zero!{PAUSE_UNTIL_PRESS}	{STR_VAR_1}のきそポイントが\nすべて0になった！{PAUSE_UNTIL_PRESS}
Cannot send that mon to the box,\nbecause it knows a HM move.{PAUSE_UNTIL_PRESS}	ひでんわざをおぼえているので\nボックスにおくれません。{PAUSE_UNTIL_PRESS}
Cannot send a mon that doesn't\nbelong to you to the box.{PAUSE_UNTIL_PRESS}	じぶんのポケモンでないので\nボックスにおくれません。{PAUSE_UNTIL_PRESS}
It might affect {STR_VAR_1}'s stats.\nAre you sure you want to use it?	{STR_VAR_1}ののうりょくが\nかわるかもしれません。つかいますか？
{STR_VAR_1}'s stats may have changed due\nto the effects of the {STR_VAR_2}!{PAUSE_UNTIL_PRESS}	{STR_VAR_2}のこうかで\n{STR_VAR_1}ののうりょくがかわったかも！{PAUSE_UNTIL_PRESS}
{STR_VAR_1}'s Dynamax Level\nincreased by 1!{PAUSE_UNTIL_PRESS}	{STR_VAR_1}のダイマックスレベルが\n1あがった！{PAUSE_UNTIL_PRESS}
You make a wish upon the\nwithered paw…\p{STR_VAR_1}'s {STR_VAR_2} rose!\pBut its {STR_VAR_3} fell…{PAUSE_UNTIL_PRESS}	ひからびたてに\nねがいをかける…\p{STR_VAR_1}の{STR_VAR_2}があがった！\pだが{STR_VAR_3}がさがった…{PAUSE_UNTIL_PRESS}
{A_BUTTON}TOGGLE   {DPAD_UPDOWN}MOVES	{A_BUTTON}きりかえ {DPAD_UPDOWN}わざ
{A_BUTTON}Toggle   {DPAD_UPDOWN}Moves	{A_BUTTON}きりかえ {DPAD_UPDOWN}わざ
LVL	レベル
CATCH{0x5B}: 	ほかく{ENG}{0x5B}{JPN}
LEGENDARY	でんせつ
VERY HARD	げきむず
DIFFICULT	むずかしい
MEDIUM	ふつう
RELAXED	ややかんたん
EASY	かんたん
EXP YIELD: 	けいけんち: 
HATCH STEPS:	ふかのほすう:
GROW: 	せいちょう
FRIENDSHIP:	なつきど:
MED. FAST	ややはやい
ERRATIC	ふきそく
FLUCTUATING	へんどう
MED. SLOW	ややおそい
FAST	はやい
SLOW	おそい
EGG G1:	タマゴグループ:
MONSTER	かいじゅう
WATER {CIRCLE_1}	すいちゅう{CIRCLE_1}
BUG	むし
FLYING	ひこう
FIELD	りくじょう
FAIRY	ようせい
GRASS	しょくぶつ
HUMANE	ひとがた
WATER {CIRCLE_3}	すいちゅう{CIRCLE_3}
MINERAL	こうぶつ
AMORPHOUS	ふていけい
WATER {CIRCLE_2}	すいちゅう{CIRCLE_2}
DITTO	メタモン
DRAGON	ドラゴン
SEEN	みつけた
OWN	つかまえた
{DPAD_UPDOWN}EVOs  {A_BUTTON}CHECK	{DPAD_UPDOWN}しんか {A_BUTTON}みる
{DPAD_UPDOWN}Evos  {A_BUTTON}Check	{DPAD_UPDOWN}しんか {A_BUTTON}みる
{DPAD_UPDOWN}EVOs  {A_BUTTON}CHECK  {START_BUTTON}FORMs	{DPAD_UPDOWN}しんか {A_BUTTON}みる {START_BUTTON}すがた
{DPAD_UPDOWN}Evos  {A_BUTTON}Check  {START_BUTTON}Forms	{DPAD_UPDOWN}しんか {A_BUTTON}みる {START_BUTTON}すがた
{STR_VAR_1} evolves from {STR_VAR_2}	{STR_VAR_2}から{STR_VAR_1}にしんか
{STR_VAR_1} Mega Evolves with {STR_VAR_2}	{STR_VAR_1}は{STR_VAR_2}でメガシンカ
{LV}{UP_ARROW} to {STR_VAR_2}, Silcoon persona	{STR_VAR_2}で{LV}{UP_ARROW} カラサリスがた
{LV}{UP_ARROW} to {STR_VAR_2}, Cascoon persona	{STR_VAR_2}で{LV}{UP_ARROW} マユルドがた
{LV}{UP_ARROW}, knows {STR_VAR_2}	{STR_VAR_2}をおぼえて{LV}{UP_ARROW}
{LV}{UP_ARROW} to {STR_VAR_2} while raining	あめのとき{STR_VAR_2}で{LV}{UP_ARROW}
Traded for {STR_VAR_2}	{STR_VAR_2}とこうかん
Land {STR_VAR_2} critical hits in\nsingle battle	1かいのせんとうで\nきゅうしょに{STR_VAR_2}かいあてる
Takes at least {STR_VAR_2} HP in damage	{STR_VAR_2}いじょうのダメージ
ScrllOfDrknss is used	あくのかけじくをつかう
ScrollOfWatrs is used	みずのかけじくをつかう
{STR_VAR_1} has no evolution.	{STR_VAR_1}はしんかしません。
{A_BUTTON}FORM MODE  {START_BUTTON}EVOs	{A_BUTTON}すがた {START_BUTTON}しんか
{START_BUTTON}Evos	{START_BUTTON}しんか
{DPAD_NONE}FORMs {A_BUTTON}CHECK {START_BUTTON}EVOs	{DPAD_NONE}すがた {A_BUTTON}みる {START_BUTTON}しんか
{STR_VAR_1} has no alternate forms.	{STR_VAR_1}にべつのすがたはありません。
Unknown	ふめい
Trading	つうしんこうかん
{STR_VAR_2} is used	{STR_VAR_2}をつかう
End battle	せんとうしゅうりょう
Male	オス
Female	メス
{UP_ARROW_2}friendship	{UP_ARROW_2}なつきど
Atk > Def	こうげき>ぼうぎょ
Atk = Def	こうげき=ぼうぎょ
Atk < Def	こうげき<ぼうぎょ
Morning	あさ
Day	ひる
Evening	ゆうがた
Night	よる
NOT Morning	あさいがい
NOT Day	ひるいがい
NOT Evening	ゆうがたいがい
Kanto	カントー
Johto	ジョウト
Hoenn	ホウエン
Sinnoh	シンオウ
Unova	イッシュ
Kalos	カロス
Alola	アローラ
Galar	ガラル
Hisui	ヒスイ
Paldea	パルデア
'''
FILES = {'data/text/save.inc','src/strings.c','src/party_menu.c','src/pokedex_plus_hgss.c'}

def main():
    words = dict(line.split('\t',1) for line in VOCABULARY.splitlines() if line)
    rows = json.loads((catalog.ROOT/'localization/catalog.json').read_text())
    batch = [dict(id=r['id'],translation=scoped(words[r['source']]),provenance=dict(batch='ui-messages-02',method='English source and UI context reviewed')) for r in rows if r['status']=='pending' and r['file'] in FILES and r['source'] in words]
    (catalog.ROOT/'localization/batches/ui-messages-02.json').write_text(json.dumps(batch,ensure_ascii=False,indent=2)+'\n')
    lookup = {r['id']:r for r in rows}
    for suffix in ('draft','final','en'):
        text = '\n'.join(b['id']+' '+(lookup[b['id']]['source'] if suffix=='en' else re.sub(r'\{(?:JPN|ENG)\}','',b['translation'])) for b in batch)+'\n'
        (catalog.ROOT/f'localization/reviews/ui-messages-02.{suffix}.txt').write_text(text)
    print('Proposed',len(batch))
if __name__=='__main__':main()
