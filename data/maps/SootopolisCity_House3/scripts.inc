SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "{JPN}あなた ポケモントレーナー でしょ?\p"
	.string "ルネの アダンさんには ファンが おおいの。\n"
	.string "でしの ミクリさん よりもね!\p"
	.string "あなたには ファン いる?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "{JPN}あら じゃあ けっこう つよいのね。$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "{JPN}あらら……\n"
	.string "それは ちょっと さみしいわね。\p"
	.string "ファンが つくように もうすこし\n"
	.string "がんばってみたら?$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "{JPN}ねっしんな ファンは ホウエンの そと\n"
	.string "からも やってくるのよ。\p"
	.string "ミナモの トレーナー ファンクラブに\n"
	.string "いったときは ほんとうに すごかったわ。$"

