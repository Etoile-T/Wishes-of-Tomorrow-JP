PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory:
	.string "{JPN}ホウエンちほうには いわと こおりと\n"
	.string "はがねの ちからを あらわす\l"
	.string "3びきの ポケモンが いるの。\p"
	.string "どれも どうくつの おくふかくに\n"
	.string "かくれている らしいわ。\p"
	.string "ちいさい ころに\n"
	.string "そんな はなしを きいたのよ。$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.string "{JPN}「6つの てんが 3つの とびらを ひらく」\p"
	.string "おじいちゃんが よく いってたけど\n"
	.string "どういう いみか わからないんだ。$"

