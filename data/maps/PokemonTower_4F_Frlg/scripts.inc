PokemonTower_4F_Frlg_MapScripts::
	.byte 0

PokemonTower_4F_EventScript_Paula::
	trainerbattle_single TRAINER_CHANNELER_PAULA, PokemonTower_4F_Text_PaulaIntro, PokemonTower_4F_Text_PaulaDefeat
	msgbox PokemonTower_4F_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Laurel::
	trainerbattle_single TRAINER_CHANNELER_LAUREL, PokemonTower_4F_Text_LaurelIntro, PokemonTower_4F_Text_LaurelDefeat
	msgbox PokemonTower_4F_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Jody::
	trainerbattle_single TRAINER_CHANNELER_JODY, PokemonTower_4F_Text_JodyIntro, PokemonTower_4F_Text_JodyDefeat
	msgbox PokemonTower_4F_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_Text_PaulaIntro::
	.string "{JPN}ゆうれい! いやっ!\n"
	.string "キエーッ!$"

PokemonTower_4F_Text_PaulaDefeat::
	.string "{JPN}ゆうれいは どこ?$"

PokemonTower_4F_Text_PaulaPostBattle::
	.string "{JPN}ゆめでも みてたのかしら…$"

PokemonTower_4F_Text_LaurelIntro::
	.string "{JPN}いっしょに のろわれろ!\n"
	.string "キエーッ!$"

PokemonTower_4F_Text_LaurelDefeat::
	.string "{JPN}なにっ!$"

PokemonTower_4F_Text_LaurelPostBattle::
	.string "{JPN}わたしたちには ゆうれいの\n"
	.string "しょうたいが わからない…$"

PokemonTower_4F_Text_JodyIntro::
	.string "{JPN}ふふふ…\n"
	.string "われを たおすな!$"

PokemonTower_4F_Text_JodyDefeat::
	.string "{JPN}え?\n"
	.string "だれ? なに?$"

PokemonTower_4F_Text_JodyPostBattle::
	.string "{JPN}なくなった ポケモンたちが\n"
	.string "やすらかに ねむれますように…$"

