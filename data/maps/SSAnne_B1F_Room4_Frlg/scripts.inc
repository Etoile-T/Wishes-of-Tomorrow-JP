SSAnne_B1F_Room4_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room4_EventScript_Leonard::
	trainerbattle_single TRAINER_SAILOR_LEONARD, SSAnne_B1F_Room4_Text_LeonardIntro, SSAnne_B1F_Room4_Text_LeonardDefeat
	msgbox SSAnne_B1F_Room4_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_EventScript_Duncan::
	trainerbattle_single TRAINER_SAILOR_DUNCAN, SSAnne_B1F_Room4_Text_DuncanIntro, SSAnne_B1F_Room4_Text_DuncanDefeat
	msgbox SSAnne_B1F_Room4_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_Text_LeonardIntro::
	.string "{JPN}ふなのりと いえば しょうぶ!\n"
	.string "って いうだろ!$"

SSAnne_B1F_Room4_Text_LeonardDefeat::
	.string "{JPN}よし!\n"
	.string "いい しょうぶ だったぜ あいぼう!$"

SSAnne_B1F_Room4_Text_LeonardPostBattle::
	.string "{JPN}ガッハッハ!\n"
	.string "ふなのりに なるきは ないか?$"

SSAnne_B1F_Room4_Text_DuncanIntro::
	.string "{JPN}さあ こい!\n"
	.string "ふなのりの プライドに かけて!$"

SSAnne_B1F_Room4_Text_DuncanDefeat::
	.string "{JPN}おまえの きはくに しずめられた!$"

SSAnne_B1F_Room4_Text_DuncanPostBattle::
	.string "{JPN}クチバシティの つりの めいじんには\n"
	.string "あったかい?$"

