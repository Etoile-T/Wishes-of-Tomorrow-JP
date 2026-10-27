AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "{JPN}こういった ふねは めずらしいので\n"
	.string "けんがく しておるのですよ。\p"
	.string "フムフム……\n"
	.string "ほかにも へやが ありそうですな……$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "{JPN}あら こんな ところまで くるなんて\n"
	.string "キミも ものずきね!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "{JPN}ものずきな うえに つよいなんて……$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "{JPN}となりの へやの おとこの ひと……\p"
	.string "ただの けんがく だって いうけど\n"
	.string "どうだか わからないわ。$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "{JPN}キミって ほんとに つよい トレーナーね!\n"
	.string "きねんに とうろく させて ちょうだい!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "{JPN}こんな ところまで また くるなんて\n"
	.string "キミって ほんとに ものずきね!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "{JPN}ちょっと つよすぎない?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "{JPN}あの おとこ ぜったい なにか たくらんでる!\n"
	.string "だって ほんとに あやしいんだもの!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "{JPN}わーっ!\n"
	.string "みつかった! …… って あれ?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "{JPN}なんだ ママじゃ なかったのか。$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "{JPN}ママに おこられそうだから にげてきたんだ。\n"
	.string "ここに いること ないしょに してね!$"

