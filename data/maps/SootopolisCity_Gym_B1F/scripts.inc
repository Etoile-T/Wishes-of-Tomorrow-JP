SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_ANDREA, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	trainerbattle_single TRAINER_BRIANNA, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	trainerbattle_single TRAINER_ANNIKA, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	trainerbattle_single TRAINER_DAPHNE, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.string "{JPN}リーダーの アダンさんに おそわった\n"
	.string "すばらしい わざを みせてあげる!$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
	.string "{JPN}ゆるしてください アダンさん……$"

SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.string "{JPN}ゆかの タイルを ぜんぶ わったら\n"
	.string "どうなるか みてごらん。$"

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.string "{JPN}ここまで きても アダンさんには\n"
	.string "あえないわよ。\p"
	.string "わたしに まけたら ね!$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.string "{JPN}つよい!\n"
	.string "かわいい みためで だまされたわ!$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.string "{JPN}あなたなら アダンさんに いちげきで\n"
	.string "やられずに すむかもね。$"

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.string "{JPN}アダンさまが たたかう\n"
	.string "すがた……\p"
	.string "その うつくしさに ひかれて わたしは\n"
	.string "トレーナーに なったの。$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.string "{JPN}わたしより ずっと うつくしい\n"
	.string "たたかいかた だったわ……$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.string "{JPN}あなたの たたかいの ゆうがさは\n"
	.string "すてきだわ。\p"
	.string "ああ… ポケモンに であえて\n"
	.string "わたしは ほんとうに しあわせ。$"

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.string "{JPN}しょうぶの きびしさを\n"
	.string "おしえて あげなくちゃね。$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.string "{JPN}あら。\n"
	.string "つよいのね。$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.string "{JPN}いいことを おしえてあげる。\p"
	.string "アダンさんの ところへ いきたいなら\n"
	.string "ゆかの タイルを 1かいずつ ふむのよ。$"

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.string "{JPN}ホウエン ちほうで いちばん\n"
	.string "レベルの たかい ポケモンジム……\p"
	.string "それが ルネジムよ。$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
	.string "{JPN}なんて レベルの たかさ!$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.string "{JPN}つよい ジムに いることに まんぞく\n"
	.string "するより ほかの ばしょで\l"
	.string "しゅぎょうした ほうが つよくなれそう。\l"
	.string "なにより そのほうが たのしそうだし。$"

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.string "{JPN}わたしは アダンさんと いっしょに\n"
	.string "ポケモンを きたえているの。\p"
	.string "あまく みないでね。$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.string "{JPN}まけちゃった……$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.string "{JPN}あなた みこみが あるわ。\n"
	.string "ここで いっしょに しゅぎょうしない?$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.string "{JPN}こおりの うえを せんを こえずに\n"
	.string "ゆうがに すべる……\p"
	.string "そんな えんぎを する トレーナーは\n"
	.string "きっと エレガントで うつくしいわ!$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.string "{JPN}ちょっと なんですって!?$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.string "{JPN}あたりまえ だけど トレーナーとしての\n"
	.string "つよさは としが わかいか\l"
	.string "としよりかとは かんけい ないのよね。$"

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.string "{JPN}ポケモンと いっしょだと「あっ!」と\n"
	.string "いうまに じかんが すぎちゃうの。$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.string "{JPN}あっ!$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.string "{JPN}だめな ことは「あっ!」と いうまに\n"
	.string "わすれられたら いいのに。$"

SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.string "{JPN}よければ とっても めずらしい\n"
	.string "ポケモンで たたかって あげるわよ。$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.string "{JPN}ほらね! わたしの ポケモン\n"
	.string "よーく みてくれた?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.string "{JPN}アダンさんに じまんの ポケモンを\n"
	.string "ほめられて この ジムに きたの。\p"
	.string "ああ もっと わかい ころに\n"
	.string "アダンさんと であえていたら……$"

SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.string "{JPN}ウフフ……\n"
	.string "しんけんな かお すてきよ。$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.string "{JPN}あらまあ。\n"
	.string "てかげん しすぎたわ。$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.string "{JPN}アダンさんには ゆび いっぽん\n"
	.string "ふれられない はずよ。 ウフフ……$"

