PewterCity_House2_Frlg_MapScripts::
	.byte 0

PewterCity_House2_EventScript_OldMan::
	msgbox PewterCity_House2_Text_MonsLearnTechniquesAsTheyGrow, MSGBOX_NPC
	end

PewterCity_House2_EventScript_LittleBoy::
	msgbox PewterCity_House2_Text_MonsEasierCatchIfStatused, MSGBOX_NPC
	end

PewterCity_House2_Text_MonsLearnTechniquesAsTheyGrow::
	.string "{JPN}ポケモンは そだつと\n"
	.string "あたらしい わざを おぼえる。\p"
	.string "でも ひとから おしえて もらわないと\n"
	.string "おぼえない わざも あるんだ。$"

PewterCity_House2_Text_MonsEasierCatchIfStatused::
	.string "{JPN}じょうたいいじょうに なった ポケモンは\n"
	.string "つかまえやすく なる。\p"
	.string "ねむり どく やけど まひ…\n"
	.string "どれも こうかてき だ。\p"
	.string "でも ポケモンを かならず\n"
	.string "つかまえられる わけじゃ ない!$"

