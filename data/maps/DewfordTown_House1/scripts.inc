DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "{JPN}こういう ちいさな しまで\n"
	.string "ポケモンと かぞく なかよく くらすのも\l"
	.string "なかなか いい もんですよ$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "{JPN}わたしは おおきな みなとまち カイナから\n"
	.string "ここの おっとの ところへ とついだの\p"
	.string "この ちいさな しまでは じかんが\n"
	.string "ゆっくり ながれるわ でも きれいな\l"
	.string "うみに かこまれて それも しあわせよ$"

DewfordTown_House1_Text_Zigzagoon:
	.string "{JPN}ジグザグマ: ぐぐう!$"

