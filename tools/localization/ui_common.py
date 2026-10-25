#!/usr/bin/env python3
"""Reviewed UI vocabulary, applied only to an explicit file allowlist.

No fuzzy matching or substring replacement. Original catalog IDs and controls
are retained. Variable substitutions enter English mode and restore Japanese,
so both untranslated values and explicitly tagged Japanese names can coexist.
"""
import collections
import json
import re
from pathlib import Path

import catalog

FILES = {
    'src/main_menu_bw.c', 'src/main_menu.c', 'src/option_menu.c',
    'src/start_menu.c', 'src/item_menu.c', 'src/party_menu.c',
    'src/data/party_menu.h', 'src/pokemon_summary_screen.c',
    'src/pokemon_storage_system.c', 'src/strings.c',
    'src/wot_randomizer_menu.c', 'src/naming_screen.c', 'src/item_use.c',
    'src/save_failed_screen.c',
}

# English<TAB>Japanese. Literal backslash-n is the game line separator.
VOCABULARY = r'''
CONTINUE	つづきから
NEW GAME	はじめから
OPTION	せってい
Team:	てもち:
Badges: 	バッジ: 
Time: 	じかん: 
Pokédex: 	ずかん: 
The save file has been erased\ndue to corruption or damage.	レポートがこわれていたため\nきろくはけされました。
The save file is corrupted.\nThe previous save will be loaded.	レポートがこわれています。\nまえのレポートをよみこみます。
The 1M sub-circuit board is\nnot installed.	{ENG}1M{JPN}サブきばんが\nささっていません。
SLOW	おそい
MID	ふつう
FAST	はやい
ON	あり
OFF	なし
2x	2ばい
3x	3ばい
TOGGLE	きりかえ
HOLD B	{ENG}B{JPN}おす
SHIFT	いれかえ
SET	かちぬき
MONO	モノラル
STEREO	ステレオ
TYPE	タイプ
NORMAL	ふつう
TEXT SPEED	もじのはやさ
BATTLE SCENE	せんとうアニメ
BATTLE STYLE	しあいのルール
SOUND	おと
BUTTON MODE	ボタンモード
FRAME	ウインドウ
PORTRAITS	かおグラフィック
AUTO SPRINT	ダッシュそうさ
FAST FORWARD	はやおくり
CANCEL	やめる
DEBUG	デバッグ
HMS	ひでんわざ
LOG	にっし
AM	ごぜん
PM	ごご
Sunday	にちようび
Monday	げつようび
Tuesday	かようび
Wednesday	すいようび
Thursday	もくようび
Friday	きんようび
Saturday	どようび
The {STR_VAR_1} can't be held\nhere.	ここでは\n{STR_VAR_1}をもたせられない。
Deposit how many\n{STR_VAR_1}?	{STR_VAR_1}を\nいくつあずけますか？
Deposited {STR_VAR_2}\n{STR_VAR_1}.	{STR_VAR_1}を\n{STR_VAR_2}こあずけた。
There's no room to\nstore items.	どうぐをあずける\nあきがありません。
Important items\ncan't be stored in\nthe PC!	たいせつなどうぐは\nパソコンに\nあずけられません！
There's nothing to sort!	ならべかえるものがない！
CHECK	しらべる
WALK	おりる
DESELECT	とうろくかいじょ
CHECK TAG	タグをみる
SHOW	みせる
Name	なまえ
Type	しゅるい
Amount	かず
Index	ばんごう
Sort items how?	どうならべかえますか？
Items sorted by {STR_VAR_1}!	{STR_VAR_1}じゅんにした！
name	なまえ
type	しゅるい
amount	かず
index	ばんごう
TRADE	こうかん
SUMMARY	つよさをみる
SWITCH	いれかえ
ITEM	どうぐ
TAKE	とりあげる
MOVE	いどう
MAIL	メール
READ	よむ
SEND OUT	せんとうへ
ENTER	さんかする
NO ENTRY	さんかしない
STORE	あずける
LEVEL MOVES	レベルわざ
EGG MOVES	タマゴわざ
TM MOVES	マシンわざ
TUTOR MOVES	おしえわざ
LEARN MOVES	わざをおぼえる
Light bulb	でんきゅう
Microwave oven	でんしレンジ
Washing machine	せんたくき
Refrigerator	れいぞうこ
Electric fan	せんぷうき
Lawn mower	しばかりき
Change form	すがたをかえる
Change Ability	とくせいへんこう
Attack	こうげき
Defense	ぼうぎょ
Sp. Atk	とくこう
Sp. Def	とくぼう
Speed	すばやさ
You have no POKéMON.	ポケモンがいません。
{START_BUTTON} RELEARN	{START_BUTTON} おもいだす
{START_BUTTON} RELEARN LEVEL	{START_BUTTON} レベルわざ
{START_BUTTON} RELEARN EGG	{START_BUTTON} タマゴわざ
{START_BUTTON} RELEARN TM	{START_BUTTON} マシンわざ
{START_BUTTON} RELEARN TUTOR	{START_BUTTON} おしえわざ
STATS	のうりょく
RENAME	なまえへんこう
There is just one POKéMON with you.	てもちが1ぴきしかいません。
Your party is full!	てもちがいっぱいです！
BOX	ボックス
WITHDRAW POKéMON	ポケモンをつれていく
Move POKéMON stored in BOXES to\nyour party.	ボックスのポケモンを\nてもちにつれていきます。
DEPOSIT POKéMON	ポケモンをあずける
Store POKéMON in your party in BOXES.	てもちのポケモンをあずけます。
MOVE POKéMON	ポケモンをせいり
Organize the POKéMON in BOXES and\nin your party.	ボックスとてもちの\nポケモンをせいりします。
MOVE ITEMS	どうぐをせいり
Move items held by any POKéMON\nin a BOX or your party.	ボックスやてもちのポケモンの\nどうぐをいどうします。
SEE YA!	やめる
Return to the previous menu.	まえのメニューにもどります。
{DYNAMIC 0} is selected.	{DYNAMIC 0}をえらんでいます。
Exit from the BOX?	ボックスをおわりますか？
What do you want to do?	どうしますか？
Please pick a theme.	テーマをえらんでください。
Pick the wallpaper.	かべがみをえらんでください。
Jump to which BOX?	どのボックスにいどうしますか？
Deposit in which BOX?	どのボックスにあずけますか？
{DYNAMIC 0} was deposited.	{DYNAMIC 0}をあずけました。
The BOX is full.	ボックスがいっぱいです。
Release this POKéMON?	このポケモンをにがしますか？
{DYNAMIC 0} was released.	{DYNAMIC 0}をにがしました。
Bye-bye, {DYNAMIC 0}!	バイバイ！ {DYNAMIC 0}！
Mark your POKéMON.	マーキングしてください。
That's your last POKéMON!	さいごの1ぴきです！
You're holding a POKéMON!	ポケモンをつかんでいます！
Which one will you take?	どれをつれていきますか？
You can't release an EGG.	タマゴはにがせません。
Continue BOX operations?	ボックスのそうさをつづけますか？
{DYNAMIC 0} came back!	{DYNAMIC 0}がもどってきた！
Was it worried about you?	あなたのことがしんぱいなのかな？
Please remove the MAIL.	メールをはずしてください。
GIVE to a POKéMON?	ポケモンにもたせますか？
Placed item in the BAG.	どうぐをバッグにいれました。
The BAG is full.	バッグがいっぱいです。
Put this item in the BAG?	どうぐをバッグにいれますか？
{DYNAMIC 0} is now held.	{DYNAMIC 0}をもちました。
Changed to {DYNAMIC 0}.	{DYNAMIC 0}にかえました。
MAIL can't be stored!	メールはあずけられません！
GIVE	もたせる
WITHDRAW	ひきだす
PLACE	ここにおく
RELEASE	にがす
MARK	マーキング
JUMP	ボックスいどう
WALLPAPER	かべがみ
NAME	なまえ
BAG	バッグ
INFO	じょうほう
SCENERY 1	ふうけい1
SCENERY 2	ふうけい2
SCENERY 3	ふうけい3
ETCETERA	そのほか
FRIENDS	ともだち
FOREST	もり
CITY	まち
DESERT	さばく
SAVANNA	サバンナ
CRAG	いわやま
VOLCANO	かざん
SNOW	ゆき
CAVE	どうくつ
BEACH	すなはま
SEAFLOOR	かいてい
RIVER	かわ
SKY	そら
POLKA-DOT	みずたま
POKéCENTER	ポケモンセンター
MACHINE	きかい
SIMPLE	シンプル
SELECT	えらぶ
EGG	タマゴ
POKéMON	ポケモン
PLAYER	しゅじんこう
POKéDEX	ポケモンずかん
TIME	プレイじかん
BADGES	バッジ
CONTROLS	そうさほうほう
BOY	おとこのこ
GIRL	おんなのこ
POKéDEX registration completed.	ポケモンずかんにとうろくした。
HT	たかさ
WT	おもさ
Searching…\nPlease wait.	けんさくちゅう…\nしばらくおまちください。
Search completed.	けんさくがおわりました。
No matching POKéMON were found.	あてはまるポケモンはいません。
Switch POKéDEX listings.	ずかんのならびをかえます。
Return to the POKéDEX.	ポケモンずかんにもどります。
Select the POKéDEX mode.	ずかんのしゅるいをえらびます。
Select the POKéDEX listing mode.	ならびかたをえらびます。
HOENN DEX	ホウエンずかん
NATIONAL DEX	ぜんこくずかん
NUMERICAL MODE	ばんごうじゅん
A TO Z MODE	なまえじゅん
HEAVIEST MODE	おもいじゅん
LIGHTEST MODE	かるいじゅん
TALLEST MODE	たかいじゅん
SMALLEST MODE	ひくいじゅん
DON'T SPECIFY.	していしない
NONE	なし
Welcome to the HALL OF FAME!	でんどういり おめでとう！
SAVING…\nDON'T TURN OFF THE POWER.	レポートをかいています…\nでんげんをきらないでください。
The HALL OF FAME data is corrupted.	でんどういりのきろくがこわれています。
HALL OF FAME No. {STR_VAR_1}	でんどういり {STR_VAR_1}かいめ
LEAGUE CHAMPION!\nCONGRATULATIONS!	リーグチャンピオン！\nおめでとう！
FLY to where?	どこにとびますか？
USE	つかう
TOSS	すてる
REGISTER	とうろく
CONFIRM	けってい
Go back to the\nprevious menu.	まえのメニューに\nもどります。
What would you like to do?	どうしますか？
CLOSE BAG	バッグをとじる
{STR_VAR_1}\nis selected.	{STR_VAR_1}を\nえらんでいます。
You can't write\nMAIL here.	ここではメールを\nかけません。
There is no\nPOKéMON.	ポケモンが\nいません。
Move the\n{STR_VAR_1}\nwhere?	{STR_VAR_1}を\nどこに\nいどうしますか？
The {STR_VAR_1} can't be held.	{STR_VAR_1}はもたせられない。
Toss out how many\n{STR_VAR_1}?	{STR_VAR_1}を\nいくつすてますか？
Threw away {STR_VAR_2}\n{STR_VAR_1}.	{STR_VAR_1}を\n{STR_VAR_2}こすてた。
Is it okay to\nthrow away {STR_VAR_2}\n{STR_VAR_1}?	{STR_VAR_1}を\n{STR_VAR_2}こすてても\nよろしいですか？
the field	フィールド
the battle	せんとう
the POKéMON LIST	てもち
the shop	おみせ
the PC	パソコン
Return to\n{STR_VAR_1}.	{STR_VAR_1}に\nもどります。
BUY	かう
SELL	うる
QUIT	やめる
I'm sorry, but that item is sold out.{PAUSE_UNTIL_PRESS}	もうしわけありません。\nうりきれです。{PAUSE_UNTIL_PRESS}
SOLD OUT	うりきれ
IN BAG: {STR_VAR_1}	しょじすう: {STR_VAR_1}
Quit shopping.	かいものをやめます。
{STR_VAR_1}? Certainly.\nHow many would you like?	{STR_VAR_1}ですね。\nいくつおかいになりますか？
{STR_VAR_1}? And you wanted {STR_VAR_2}?\nThat will be ¥{STR_VAR_3}.	{STR_VAR_1}を{STR_VAR_2}こで\n¥{STR_VAR_3}になります。
{STR_VAR_1}, is it?\nThat'll be ¥{STR_VAR_2}. Do you want it?	{STR_VAR_1}は\n¥{STR_VAR_2}ですが よろしいですか？
You wanted {STR_VAR_1}?\nThat'll be ¥{STR_VAR_2}. Will that be okay?	{STR_VAR_1}ですね。\n¥{STR_VAR_2}ですが よろしいですか？
Here you go!\nThank you very much.	はい どうぞ！\nありがとうございました。
Thank you!\nI'll send it to your home PC.	ありがとうございます！\nじたくのパソコンにおくります。
Thanks!\nI'll send it to your PC at home.	ありがとうございます！\nじたくのパソコンにおくります。
You don't have enough money.{PAUSE_UNTIL_PRESS}	おかねがたりません。{PAUSE_UNTIL_PRESS}
You have no more room for this\nitem.{PAUSE_UNTIL_PRESS}	そのどうぐは これいじょう\nもちきれません。{PAUSE_UNTIL_PRESS}
The space for {STR_VAR_1} is full.{PAUSE_UNTIL_PRESS}	{STR_VAR_1}をいれる\nあきがありません。{PAUSE_UNTIL_PRESS}
Is there anything else I can help\nyou with?	ほかに ごようはありますか？
Can I help you with anything else?	ほかに ごようはありますか？
I'll throw in a PREMIER BALL, too.{PAUSE_UNTIL_PRESS}	プレミアボールを\nおまけしておきます。{PAUSE_UNTIL_PRESS}
I'll throw in {STR_VAR_1} PREMIER BALLS, too.{PAUSE_UNTIL_PRESS}	プレミアボールを{STR_VAR_1}こ\nおまけしておきます。{PAUSE_UNTIL_PRESS}
{STR_VAR_2}? Oh, no.\nI can't buy that.{PAUSE_UNTIL_PRESS}	{STR_VAR_2}は\nかいとれません。{PAUSE_UNTIL_PRESS}
{STR_VAR_2}?\nHow many would you like to sell?	{STR_VAR_2}を\nいくつおうりになりますか？
I can pay ¥{STR_VAR_1}.\nWould that be okay?	¥{STR_VAR_1}になりますが\nよろしいですか？
Turned over the {STR_VAR_2}\nand received ¥{STR_VAR_1}.	{STR_VAR_2}をわたして\n¥{STR_VAR_1}をうけとった。
SP. ATK	とくこう
SP. DEF	とくぼう
ATTACK	こうげき
DEFENSE	ぼうぎょ
SPEED	すばやさ
It won't have any effect.{PAUSE_UNTIL_PRESS}	つかってもこうかがないよ。{PAUSE_UNTIL_PRESS}
This can't be used on\nthat POKéMON.{PAUSE_UNTIL_PRESS}	そのポケモンには\nつかえません。{PAUSE_UNTIL_PRESS}
An EGG can't battle!{PAUSE_UNTIL_PRESS}	タマゴはたたかえません！{PAUSE_UNTIL_PRESS}
Throw away this\n{STR_VAR_1}?	この{STR_VAR_1}を\nすてますか？
The {STR_VAR_1}\nwas thrown away.{PAUSE_UNTIL_PRESS}	{STR_VAR_1}を\nすてました。{PAUSE_UNTIL_PRESS}
Teach which POKéMON?	どのポケモンにおしえますか？
Choose a POKéMON.	ポケモンをえらんでください。
Move to where?	どこにいどうしますか？
Use on which POKéMON?	どのポケモンにつかいますか？
Give to which POKéMON?	どのポケモンにもたせますか？
There's nothing to CUT.	いあいぎりできるものがない。
You can't SURF here.	ここではなみのりできません。
You're already SURFING.	もうなみのりしています。
Can't use that here.	ここではつかえません。
Restore which move?	どのわざをかいふくしますか？
Boost PP of which move?	どのわざの{ENG}PP{JPN}をふやしますか？
Do what with an item?	どうぐをどうしますか？
No POKéMON for battle!	たたかえるポケモンがいません！
Not enough HP…	たいりょくがたりない…
No identical hold items.	おなじどうぐはもたせられません。
Do what with the MAIL?	メールをどうしますか？
Choose POKéMON or CANCEL.	ポケモンをえらぶか やめてください。
Choose POKéMON and confirm.	ポケモンをえらんで けってい。
Send which POKéMON to the PC?	どのポケモンをあずけますか？
Move item to where?	どうぐをどこにいどうしますか？
This is in use already.	すでにつかっています。
No use.	つかえません。
ABLE	できる
NOT ABLE	できない
ABLE!	できる！
NOT ABLE!	できない！
LEARNED	おぼえている
HAVE	もっている
DON'T HAVE	もっていない
FIRST	1ばんめ
SECOND	2ばんめ
THIRD	3ばんめ
FOURTH	4ばんめ
Cancel participation?	さんかをやめますか？
Cancel the battle?	せんとうをやめますか？
Cancel the challenge?	ちょうせんをやめますか？
POWER	いりょく
ACCURACY	めいちゅう
APPEAL	アピール
JAM	じゃま
STATUS	じょうたい
EXP. POINTS	けいけんち
NEXT LV.	つぎのレベル
RIBBONS: {STR_VAR_1}	リボン: {STR_VAR_1}
EVENTS	できごと
POKéMON INFO	ポケモンじょうほう
POKéMON SKILLS	ポケモンのうりょく
BATTLE MOVES	たたかうわざ
CONTEST MOVES	コンテストわざ
It looks like this EGG will\ntake a long time to hatch.	うまれるまでには\nまだまだかかりそう。
What will hatch from this?\nIt will take some time.	なにがうまれるのかな？\nまだじかんがかかりそう。
It moves occasionally.\nIt should hatch soon.	ときどきうごいている。\nもうすぐうまれそう。
It's making sounds.\nIt's about to hatch!	なかからこえがきこえる。\nもうすぐうまれる！
HM moves can't be\nforgotten now.	ひでんわざは\nいまはわすれられません。
DECORATE	もようがえ
PUT AWAY	かたづける
DESK	つくえ
CHAIR	いす
PLANT	しょくぶつ
ORNAMENT	おきもの
MAT	マット
POSTER	ポスター
DOLL	ぬいぐるみ
CUSHION	クッション
GOLD	きん
SILVER	ぎん
Place it here?	ここにおきますか？
It can't be placed here.	ここにはおけません。
Cancel decorating?	もようがえをやめますか？
'''


def scoped(text):
    # Keep the option menu's color commands at byte positions 0..5. Its
    # selection highlighter rewrites byte 2 and byte 5 before rendering.
    terminal = '$' if text.endswith('$') else ''
    if terminal:
        text = text[:-1]
    leading = re.match(r'^(?:\{(?:COLOR|SHADOW) [^}]+\})*', text)[0]
    text = text[len(leading):]
    text = re.sub(r'\{(?:STR_VAR_[123]|PLAYER|DYNAMIC \d+)\}',
                  lambda m: '{ENG}' + m[0] + '{JPN}', text)
    return leading + '{JPN}' + text + '{ENG}' + terminal


def main():
    vocabulary = dict(line.split('\t', 1) for line in (VOCABULARY + EXTRA).splitlines() if line)
    rows = json.loads((catalog.ROOT / 'localization/catalog.json').read_text())
    batch = []
    counts = collections.Counter()
    for row in rows:
        if row['file'] not in FILES or row['status'] != 'pending':
            continue
        source = row['source']
        prefix = re.match(r'^(?:\{(?:COLOR|SHADOW) [^}]+\})*', source)[0]
        word = source[len(prefix):]
        if word not in vocabulary:
            continue
        # SHIFT means a selected Pokemon changes position in these menus.
        translated = vocabulary[word]
        if row['file'] != 'src/option_menu.c' and word == 'SHIFT':
            translated = 'いれかえ'
        if row['file'] == 'src/strings.c' and word == 'NORMAL':
            translated = 'ノーマル'
        if word == 'DESELECT':
            translated = 'とうろくけす' if row['file'] == 'src/item_menu.c' else 'せんたくかいじょ'
        batch.append(dict(id=row['id'], translation=scoped(prefix + translated),
                          provenance=dict(batch='ui-common-01', method='Exact English UI vocabulary, reviewed in source context')))
        counts[row['file']] += 1
    output = catalog.ROOT / 'localization/batches/ui-common-01.json'
    output.write_text(json.dumps(batch, ensure_ascii=False, indent=2) + '\n')
    by_id = {r['id']: r for r in rows}
    for suffix in ('draft', 'final', 'en'):
        text = '\n'.join(x['id'] + ' ' + (by_id[x['id']]['source'] if suffix == 'en' else
            re.sub(r'\{(?:JPN|ENG)\}', '', x['translation'])) for x in batch) + '\n'
        (catalog.ROOT / f'localization/reviews/ui-common-01.{suffix}.txt').write_text(text)
    print(json.dumps(dict(count=len(batch), files=counts), ensure_ascii=False))


EXTRA = r'''
YES	はい
NO	いいえ
EXIT	とじる
DAD	パパ
MOM	ママ
INFORMATION	じょうほう
DECORATION	もようがえ
PACK UP	ひっこし
REGISTRY	ともだちリスト
LOG OFF	せつだん
HALL OF FAME	でんどういり
SOMEONE'S PC	だれかのパソコン
LANETTE'S PC	マユミのパソコン
BILL'S PC	マサキのパソコン
{PLAYER}'s PC	{PLAYER}のパソコン
RED SHARD	あかいかけら
YELLOW SHARD	きいろいかけら
BLUE SHARD	あおいかけら
GREEN SHARD	みどりのかけら
BATTLE FRONTIER	バトルフロンティア
COOL	かっこよさ
BEAUTY	うつくしさ
CUTE	かわいさ
SMART	かしこさ
TOUGH	たくましさ
COOLNESS CONTEST	かっこよさコンテスト
BEAUTY CONTEST	うつくしさコンテスト
CUTENESS CONTEST	かわいさコンテスト
SMARTNESS CONTEST	かしこさコンテスト
TOUGHNESS CONTEST	たくましさコンテスト
SUPER	スーパー
HYPER	ハイパー
MASTER	マスター
SINGLE	シングル
DOUBLE	ダブル
MULTI	マルチ
MULTI-LINK	つうしんマルチ
OPPONENT	たいせんあいて
TOURNEY TREE	トーナメントひょう
READY TO START	じゅんびかんりょう
GO ON	つづける
RECORD	きろく
REST	やすむ
RETIRE	リタイア
IN PARTY	てもちにいる
Keep the Research	けんきゅうをのこす
Destroy the Research	けんきゅうをすてる
Read	よむ
Destroy	こわす
Distortion World	やぶれたせかい
RANDOMIZER	ランダマイザー
RANDOM	ランダム
START THE GAME	ぼうけんをはじめる
STARTER PKMN	さいしょの3びき
WILD PKMN	やせいのポケモン
TRAINER PKMN	トレーナーのてもち
START	はじめる
Play the game randomized.\nSettings below!	ランダムなせかいであそびます。\nくわしくは したのせっていで！
The three sealed starters become\nsomething else entirely.	ふういんされたさいしょの3びきが\nまったくべつのポケモンになります。
Every wild Pokemon is swapped.\nLevels never change.	やせいのポケモンをいれかえます。\nレベルはかわりません。
Every Trainer's team is swapped.\nShadows keep their identity.	トレーナーのてもちをいれかえます。\nシャドーポケモンはかわりません。
Begin the adventure with these\nsettings. They are permanent.	このせっていでぼうけんをはじめます。\nあとからへんこうはできません。
RIVAL's NAME?	ライバルのなまえは？
YOUR NAME?	あなたのなまえは？
BOX NAME?	ボックスのなまえは？
{STR_VAR_1}'s nickname?	{STR_VAR_1}のニックネームは？
Tell him the words.	かれにことばをつたえよう。
Enter code:	コードをにゅうりょく:
{DPAD_NONE}MOVE  {A_BUTTON}OK  {B_BUTTON}BACK	{DPAD_NONE}いどう {A_BUTTON}けってい {B_BUTTON}もどる
You can't dismount your BIKE here.{PAUSE_UNTIL_PRESS}	ここではじてんしゃから\nおりられません。{PAUSE_UNTIL_PRESS}
Huh?\nThe ITEMFINDER's responding!\pThere's an item buried around here!{PAUSE_UNTIL_PRESS}	おや？\nダウジングマシンがはんのうした！\pこのちかくにどうぐがうまっている！{PAUSE_UNTIL_PRESS}
Oh!\nThe ITEMFINDER's shaking wildly!{PAUSE_UNTIL_PRESS}	おお！\nダウジングマシンがはげしくゆれる！{PAUSE_UNTIL_PRESS}
… … … …Nope!\nThere's no response.{PAUSE_UNTIL_PRESS}	… … … …だめだ！\nはんのうがない。{PAUSE_UNTIL_PRESS}
Your COINS:\n{STR_VAR_1}{PAUSE_UNTIL_PRESS}	もっているコイン:\n{STR_VAR_1}まい{PAUSE_UNTIL_PRESS}
POWDER QTY: {STR_VAR_1}{PAUSE_UNTIL_PRESS}	きのみのこな: {STR_VAR_1}{PAUSE_UNTIL_PRESS}
Booted up a TM.	わざマシンをきどうした。
Booted up an HM.	ひでんマシンをきどうした。
It contained\n{STR_VAR_1}.\pTeach {STR_VAR_1}\nto a POKéMON?	なかには{STR_VAR_1}が\nきろくされていた。\pポケモンに{STR_VAR_1}を\nおぼえさせますか？
{PLAYER} used the\n{STR_VAR_2}.\pWild POKéMON will be lured.{PAUSE_UNTIL_PRESS}	{PLAYER}は\n{STR_VAR_2}をつかった。\pやせいのポケモンがよってくる。{PAUSE_UNTIL_PRESS}
{PLAYER} used the\n{STR_VAR_2}.\pWild POKéMON will be repelled.{PAUSE_UNTIL_PRESS}	{PLAYER}は\n{STR_VAR_2}をつかった。\pやせいのポケモンがよってこなくなる。{PAUSE_UNTIL_PRESS}
Played the POKé FLUTE.\pNow, that's a catchy tune!{PAUSE_UNTIL_PRESS}	ポケモンのふえをふいた。\pこころにのこるメロディだ！{PAUSE_UNTIL_PRESS}
Played the POKé FLUTE.	ポケモンのふえをふいた。
The POKé FLUTE awakened sleeping\nPOKéMON.{PAUSE_UNTIL_PRESS}	ポケモンのふえのねいろで\nねむっていたポケモンがめをさました。{PAUSE_UNTIL_PRESS}
Cannot throw a ball!\nThere are two Pokémon out there!\p	ボールをなげられない！\nあいてのポケモンが2ひきいる！\p
Cannot throw a ball!\nThere's no Pokémon in sight!\p	ボールをなげられない！\nポケモンがみあたらない！\p
POKé BALLS cannot be used\nright now!\p	いまはモンスターボールを\nつかえません！\p
The decoration item was thrown away.	グッズをすてました。
Stop putting away decorations?	かたづけをやめますか？
There is no decoration item here.	ここにはグッズがありません。
Return this decoration to the PC?	このグッズをパソコンにもどしますか？
The decoration was returned to the PC.	グッズをパソコンにもどしました。
There are no decorations in use.{PAUSE_UNTIL_PRESS}	つかっているグッズはありません。{PAUSE_UNTIL_PRESS}
There are no items.{PAUSE_UNTIL_PRESS}	どうぐがありません。{PAUSE_UNTIL_PRESS}
There's no MAIL here.{PAUSE_UNTIL_PRESS}	メールがありません。{PAUSE_UNTIL_PRESS}
The message will be lost.\nIs that okay?	ぶんしょうがきえてしまいますが\nよろしいですか？
The BAG is full.{PAUSE_UNTIL_PRESS}	バッグがいっぱいです。{PAUSE_UNTIL_PRESS}
Return to the title screen.	タイトルがめんにもどります。
Communicating…	つうしんちゅう…
Communication completed.	つうしんがかんりょうしました。
Communication error.	つうしんエラーです。
Communication has been canceled.	つうしんがちゅうしされました。
RECEIVE	うけとる
SEND	おくる
FRIEND	ともだち
WONDER CARDS	ふしぎなカード
WONDER NEWS	ふしぎなニュース
WIRELESS COMMUNICATION	ワイヤレスつうしん
RENTAL POKéMON	レンタルポケモン
Select the first POKéMON.	1ぴきめをえらんでください。
Select the second POKéMON.	2ひきめをえらんでください。
Select the third POKéMON.	3びきめをえらんでください。
RENT	かりる
OTHERS	ほかをみる
Are these three POKéMON OK?	この3びきでよろしいですか？
POKéMON SWAP	ポケモンこうかん
Select POKéMON to swap.	わたすポケモンをえらんでください。
Select POKéMON to accept.	もらうポケモンをえらんでください。
SWAP	こうかん
RECHOOSE	えらびなおす
Quit swapping?	こうかんをやめますか？
ACCEPT	うけとる
Accept this POKéMON?	このポケモンをうけとりますか？
'''


if __name__ == '__main__':
    main()
