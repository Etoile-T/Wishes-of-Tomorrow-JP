#!/usr/bin/env python3
"""Add the opening story batch to the English-source catalog before applying."""
import json,re,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
path=ROOT/'localization/catalog.json'
rows=json.loads(path.read_text())
translations={
'data/maps/MunenVillage/scripts.inc': {
'MunenText_Intro1':r'ムネンやま。\nいまから せんねんまえ。$',
'MunenText_Intro2':r'このやまに ほしが おちたという。\pほしは ねがいを かなえたという。\pそして せかいを おわらせたという。$',
'MunenText_Intro3':r'いきのこった ひとびとは ふうじた。\pあの ほしを。\nほしと ともに きたものを。\pひとは それを ふめつのねがいと よび\pにどと めざめぬよう いのった。$',
'MunenText_Intro4':r'それから せんねん。\nねむりは つづいていた。\pだが きょう ふういんが ゆらぐ。$',
'MunenText_MomFirst':r'おはよう。 よく ねむれた？\pクラークソンはかせから でんごんよ。\nけんきゅうじょに きてほしいって。\pさむいから きをつけてね。\nきょうは もう きりが でているわ。$',
'MunenText_MomAgain':r'はかせが けんきゅうじょで まってるわ。\nあたたかくして いくのよ。$',
'MunenText_Clarkson':r'きたか。\pわしは このやまの きおくを しらべとる。\nふるい こおりや つたわる はなしをな。\pこおった みずうみの そこで みつけた。\nこおりの なかで ねむる ３たいを。\pわしが よみがえらせた。 あやまちだった。\pさあ １たい えらぶがいい。\nむこうにも えらんで もらいなさい。$',
'MunenText_ClarksonAfter':r'もう なついたか。 よしよし。\pそのこは やまが ながらく ひめてきた\nこたえの ひとかけらなのだ。$',
'MunenText_IceTyrunt':r'こおりの なかで なにかが うごいた。\pまるで ここは じぶんの りょうちだと\nいわんばかりに こちらを みている。\pこのこを えらびますか？$',
'MunenText_IceAmaura':r'こおりの なかで なにかが うごいた。\pきづいて もらえて うれしいのか\nしもごしに にっこりと ほほえんだ。\pこのこを えらびますか？$',
'MunenText_IceAnorith':r'こおりの なかで なにかが うごいた。\pこちらの すがたは みえないようだが\nあごで こおりを たしかめている。\pこのこを えらびますか？$',
'MunenText_StarterChosen':r'こおりが われた。\pせんねんぶりに いきを すう。\nそして これからも あなたの そばで\lいきていくことを えらんだ。$',
'MunenText_GotStarter':r'{ENG}{PLAYER}{JPN}は\n{ENG}{STR_VAR_1}{JPN}を うけとった！$',
'MunenText_OldLady':r'やまの ゆきが\nとけておるのじゃ。\pとけては ならぬ ゆきが。 けっしてな。\pムネンに しが せまっておる。\pかぜが そう つげておるわ。$',
'MunenText_HaruShout':r'？？？: おい！ まてよ！$',
'MunenText_HaruIntro':r'なるほど。 ここに いたのか。\pクラークソンはかせが おれの ぶんも\nのこしたって いってたんだ！\lぜんぶ おまえに わたすかよ。\pのこりは おれが もらう。\pわすれるなよ\n{ENG}{PLAYER}{JPN}。$',
'MunenText_HaruFarewell':r'つぎに あったら\nきっちり けりを つけようぜ。\pじゃあな。 また みちで あおう。$',
},
'src/quest_toast.c': {
'sText_ToastStart':'クエスト はっせい', 'sText_ToastUpdate':'クエスト こうしん','sText_ToastComplete':'クエスト かんりょう',
}}
for file, defs in translations.items():
    text=subprocess.check_output(['git','show','23be896714d43ed3c0657a167d0b73f787f31153:'+file],cwd=ROOT,text=True)
    for label,target in defs.items():
        m=re.search(r'(?m)^'+label+r':+\s*\n\s*\.string\s*',text) if file.endswith('.inc') else re.search(r'\b'+label+r'\[\]\s*=\s*_\(',text)
        if not m: raise ValueError(label)
        row=min((r for r in rows if r['file']==file and r['start']>=m.end()),key=lambda r:r['start'])
        row.update(translation='{JPN}'+target.translate(str.maketrans('０１２３４５６７８９','0123456789')),status='translated',target=label)
path.write_text(json.dumps(rows,ensure_ascii=False,indent=2)+'\n')
print('Added',sum(map(len,translations.values())))
