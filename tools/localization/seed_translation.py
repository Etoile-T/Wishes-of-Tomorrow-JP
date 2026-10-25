#!/usr/bin/env python3
"""Reviewed first-batch kana translations. Run on the pinned English catalog."""
import json,subprocess
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
# Keyed by file and definition label, rather than an unscoped English replace.
translations = {
'src/main_menu.c': {
'gText_MainMenuNewGame':'さいしょから はじめる',
'gText_MainMenuContinue':'つづきから はじめる',
'gText_MainMenuOption':'せってい',
'gText_MainMenuMysteryGift':'ふしぎな おくりもの',
'gText_MainMenuMysteryGift2':'ふしぎな おくりもの',
'gText_MainMenuMysteryEvents':'ふしぎな できごと',
'gText_ContinueMenuPlayer':'しゅじんこう', 'gText_ContinueMenuTime':'プレイじかん',
'gText_ContinueMenuPokedex':'ポケモンずかん','gText_ContinueMenuBadges':'バッジ',
},
'src/start_menu.c': {'sText_QuestMenu':'クエスト'},
'src/quests.c': {
'sText_AllHeader':'すべての クエスト','sText_InactiveHeader':'みじゅちゅう',
'sText_ActiveHeader':'しんこうちゅう','sText_RewardHeader':'ほうしゅう うけとり',
'sText_CompletedHeader':'かんりょうずみ','sText_Active':'じゅちゅう',
'sText_Reward':'ほうしゅう','sText_Complete':'かんりょう',
'sText_ShowLocation':'ばしょ: {STR_VAR_2}',
'sText_StartForMore':'{ENG}START{JPN}で くわしく',
'sText_ReturnRecieveReward':r'{STR_VAR_2}に もどり\nほうしゅうを うけとろう！',
'sText_Type':'{R_BUTTON}しゅるい','sText_Caught':'つかまえた',
'sText_Found':'みつけた','sText_Read':'よんだ','sText_Back':'もどる','sText_Close':'とじる',
},
'src/strings.c': {
'gText_MenuPokedex':'ポケモンずかん','gText_MenuPokemon':'ポケモン',
'gText_MenuBag':'バッグ','gText_MenuPokenav':'ポケナビ','gText_MenuSave':'レポート',
'gText_MenuOption':'せってい','gText_MenuExit':'とじる','gText_MenuRetire':'リタイア',
'gText_MenuRest':'きゅうけい','gText_MenuDexNav':'ずかんナビ',
'gText_MenuOptionPokedex':'ポケモンずかん','gText_MenuOptionPokemon':'ポケモン',
'gText_MenuOptionBag':'バッグ','gText_MenuOptionPokenav':'ポケナビ',
'gText_MenuOptionSave':'レポート','gText_MenuOptionOption':'せってい','gText_MenuOptionExit':'とじる',
'gText_QuestAnnounce':r'クエスト {STR_VAR_1}\n{STR_VAR_2}に なりました。',
'gText_QuestComplete':'かんりょう','gText_QuestActive':'しんこうちゅう',
'gText_QuestLoc_MtMunen':'ムネンやま','gText_QuestLoc_MunenVillage':'ムネンむら',
'gText_QuestLoc_SennenStation':'センネンえき','gText_QuestLoc_NationalPark':'しぜんこうえん',
'gText_QuestLoc_Pompeii':'ポンペイ','gText_QuestLoc_FrostwoodTown':'フロストウッドタウン',
'gText_QuestLoc_ShinTokyo':'シントウキョウ','gText_QuestLoc_HotelZ':'ホテル{ENG}Z',
'gText_Quest_StopTheMachine_Name':'そうちを とめろ',
'gText_Quest_StopTheMachine_Desc1':r'こんやは しおが ひく。\nなみのりで みなみの ほこらへ。\nそのあと ミュートリッドの とうへ。',
'gText_Quest_StopTheMachine_DoneDesc':r'ダークそうちは とまった。\nねがいは もとのすがたに。',
'gText_Quest_HarnessDarkness_Name':'やみを あやつる',
'gText_Quest_HarnessDarkness_Desc1':r'ほこらで ダークポケモンを\n１たい リライブし\nはかせの じょしゅに ほうこく。',
'gText_Quest_HarnessDarkness_Desc2':r'そらへの みちが ひらけた。\nダークポケモンを ５たい スナッチし\nはかせの じょしゅの もとへ。',
'gText_Quest_HarnessDarkness_DoneDesc':r'ポケモンたちの やみは\nいまや あなたに したがう。',
'gText_Quest_MinistersFavor_Name':'ろうやぶり',
'gText_Quest_MinistersFavor_Desc1':r'シントウキョウの みなとで\nだいじんと あい ミクマンクを\nろうやから たすけだそう。',
'gText_Quest_MinistersFavor_DoneDesc':r'ミクマンクは じゆうの み。\nだいじんも やくそくを はたした。',
'gText_Quest_MegaDoomsday_Name':'メガの しゅうまつ',
'gText_Quest_MegaDoomsday_Desc':r'ホテル{ENG}Z{JPN}で リダと\nカナリィに あおう。',
'gText_Quest_MegaDoomsday_DoneDesc':r'ホテル{ENG}Z{JPN}で リダと\nカナリィに あった。',
'gText_Quest_TwoMinutes_Name':'ながい ２ふんかん',
'gText_Quest_TwoMinutes_Desc':r'ぼうそうメガ １９しゅの メガストーンを\nモミジに とどけよう。\nあつめた かずも きいてみよう。',
'gText_Quest_TwoMinutes_DoneDesc':r'１９しゅの サンプルが そろい\nモミジは けんさを はじめた。',
'gText_Quest_PrimalSignatures_Name':'ゲンシの はんのう',
'gText_Quest_PrimalSignatures_Desc':r'さけめで いじょうな はんのう。\nゲンシグラードンと\nゲンシカイオーガを つかまえよう。',
'gText_Quest_PrimalSignatures_DoneDesc':r'２たいの ゲンシを つかまえた。\nモミジも データを てにいれた。',
'gText_Quest_SkyHighMega_Name':'てんくうの メガ',
'gText_Quest_SkyHighMega_Desc':r'さけめの なにかが\nゲンシの ちからを ねらっている。\nメガレックウザを つかまえよう。',
'gText_Quest_SkyHighMega_DoneDesc':r'メガレックウザを つかまえた。\nさけめも おちつきはじめている。',
'gText_Quest_WakingMountain_Name':'めざめる やま',
'gText_Quest_WakingMountain_Desc1':r'せんねんの こおりが われはじめた。\nりゆうを しる クラークソンはかせを\nさがしに いこう。',
'gText_Quest_WakingMountain_Desc2':r'はかせが さんちょうで よんでいる。\nこおりが とぎれる ばしょ\nスターサミットへ のぼろう。',
'gText_Quest_WakingMountain_DoneDesc':r'やまが めざめた。 このさき\nなにが おこるかは だれも しらない。',
'gText_Quest_OneThatGotAway_Name':'かえらない ひと',
'gText_Quest_OneThatGotAway_Desc1':r'ムネンむらの しょうねんは\nこおりに きえた ちちを まっている。\nなにが あったか たしかめよう。',
'gText_Quest_OneThatGotAway_Desc2':r'ちちおやは いきていた！\nむらへ もどり しょうねんに しらせ\nながい まちじかんを おわらせよう。',
'gText_Quest_OneThatGotAway_DoneDesc':r'みずうみでの ながい まちじかんは\nおわった。 おやこは\nふたたび ともに すごしている。',
'gText_Quest_FrozenTracks_Name':'こおりついた せんろ',
'gText_Quest_FrozenTracks_Desc':r'ミュートリッドだんが センネンせんの\nはぐるまを こおらせた。\nこおりを とかす ほうほうを さがそう。',
'gText_Quest_FrozenTracks_DoneDesc':r'ウインディの ほのおで\nセンネンせんの こおりが とけ\nれっしゃが また はしりだした。',
'gText_Quest_EightWays_Name':'８つの みらい',
'gText_Quest_EightWays_Desc':r'こうえんの ブリーダーが\nイーブイを そだてている。\nみとめられれば えらばれるかも。',
'gText_Quest_EightWays_DoneDesc':r'イーブイは あなたを えらんだ。\nどんな すがたに そだつかは\nあなたしだい。',
'gText_Quest_HeavyMetal_Name':'ヘビーメタル',
'gText_Quest_HeavyMetal_Desc':r'こうえんの コレクターは\nストライクと めずらしい パートナー\n３しゅの どれかを こうかんしたい。',
'gText_Quest_HeavyMetal_DoneDesc':r'ストライクを コレクターに わたした。\nかわりに もらった パートナーを\nたいせつに しよう。',
'gText_Quest_SaveFace_Name':'めんぼくを まもれ',
'gText_Quest_SaveFace_Desc1':r'ゲンししょうの でしが\nできたての めんを トンネルで\nなくした。 さがして あげよう。',
'gText_Quest_SaveFace_Desc2':r'なくした めんが みつかった。\nポンペイの ゲンししょうに\nとどけよう。',
'gText_Quest_SaveFace_DoneDesc':r'めんは ぶじに もどった。\nししょうの めんぼくも\nでしの いばしょも まもられた。',
'gText_Quest_GrandfathersWish_Name':'おじいさんの さいごの ねがい',
'gText_Quest_GrandfathersWish_Desc':r'アズサユミを もって みずを わたり\nむすこの はかで\nとむらいの ぎしきを おこなおう。',
'gText_Quest_GrandfathersWish_DoneDesc':r'はかの まえで ユミが うたった。\nさいごの ねがいは\nさいごまで とどけられた。',
'gText_Quest_LifesWork_Name':'はかせが のこしたもの',
'gText_Quest_LifesWork_Desc':r'けんきゅうを こわしてほしい。\nはかせの さいごの ねがいを はたしに\nムネンの けんきゅうじょへ。',
'gText_Quest_LifesWork_DoneDesc':r'けんきゅうが あくようされることは\nもう ない。 はかせの しごとは\nねがったとおりの さいごを むかえた。',
'gText_Quest_ToastyTime_Name':'ほっとする じかん',
'gText_Quest_ToastyTime_Desc':r'ジムリーダーの ちちに ココアを\nもらった。 ふたりの むすめを\nゆうしょくに つれもどそう。',
'gText_Quest_ToastyTime_DoneDesc':r'しまいたちは あたたまり\nいえへ むかった。 ごはんの じかんだ。',
}}
# Fullwidth digits have no independent mapping in the original charmap.
for defs in translations.values():
    for label, target in list(defs.items()):
        defs[label] = target.translate(str.maketrans('０１２３４５６７８９','0123456789'))
rows = json.loads((ROOT/'localization/catalog.json').read_text())
import re
count = 0
for file, defs in translations.items():
    text = subprocess.check_output(['git','show','23be896714d43ed3c0657a167d0b73f787f31153:'+file], cwd=ROOT, text=True)
    for label, target in defs.items():
        definition = re.search(r'\b'+re.escape(label)+r'\s*\[[^\]]*\]\s*=\s*_\(', text)
        if not definition:
            raise ValueError((file,label))
        candidates = [r for r in rows if r['file']==file and r['start']>=definition.end()]
        row = min(candidates, key=lambda r:r['start'])
        row.update(translation='{JPN}'+target, status='translated', target=label)
        count += 1
(ROOT/'localization/catalog.json').write_text(json.dumps(rows, ensure_ascii=False, indent=2)+'\n')
print('Seeded', count)
