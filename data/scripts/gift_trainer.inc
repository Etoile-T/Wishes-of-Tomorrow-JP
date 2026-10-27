MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "{JPN}ふしぎな おくりものを ごりよう\n"
	.string "いただき ありがとう ございます。\p"
	.string "この ふしぎなカードを もっていると\n"
	.string "フレンドリィショップで アンケートに\l"
	.string "こたえることが できます。\p"
	.string "アンケートを つかって ルネシティに\n"
	.string "トレーナーを まねくことが できます。\p"
	.string "…アンケート ようの ひみつの\n"
	.string "あいことばを おしえましょう:\p"
	.string "「すごい トレーナー\n"
	.string "ください」\p"
	.string "これを アンケートに かいて\n"
	.string "ワイヤレス\l"
	.string "つうしんシステムに おくってください。$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "{JPN}ふしぎな おくりものを ごりよう\n"
	.string "いただき ありがとう ございます。\p"
	.string "あなたを さがして トレーナーが\n"
	.string "ルネシティに やってきました。\p"
	.string "おとずれた トレーナーとの\n"
	.string "バトルを おたのしみください。\p"
	.string "ほかの あいことばを いれると\n"
	.string "ほかの トレーナーも まねけます。\p"
	.string "つかえそうな ほかの あいことばを\n"
	.string "さがしてみてください。$"
