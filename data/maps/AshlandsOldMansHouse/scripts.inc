AshlandsOldMansHouse_MapScripts::
	.byte 0

@ ============================================================================
@  THE OLD PROPHET'S HOUSE (Ashlands) -- opened when the old man vanishes
@  after the FENTANYL quest. Holds the CATALPA BOW (item ball) that opens
@  the gravesite crossing in the Act 2 National Park.
@  Three generations in one room: the prophet, Prof. Clarkson, and the boy
@  who became Team Mutrid's masked leader.
@ ============================================================================
@ The Catalpa Bow item ball: quest stage 3 on pickup.
AshlandsOldMansHouse_EventScript_BowBall::
	finditem ITEM_CATALPA_BOW
	goto_if_eq VAR_RESULT, FALSE, AshlandsOldMansHouse_EventScript_BowBallEnd
	compare VAR_QUEST_FATHERS_WISH, 2
	goto_if_ne AshlandsOldMansHouse_EventScript_BowBallEnd
	setvar VAR_QUEST_FATHERS_WISH, 3
	startquest QUEST_GRANDFATHERS_WISH
AshlandsOldMansHouse_EventScript_BowBallEnd::
	end

AshlandsOldMansHouse_EventScript_FamilyShrine::
	msgbox AshlandsOldMansHouse_Text_FamilyShrine, MSGBOX_SIGN
	end

AshlandsOldMansHouse_EventScript_Letters::
	msgbox AshlandsOldMansHouse_Text_Letters, MSGBOX_SIGN
	end

@ ============================================================================
@  Text
@ ============================================================================
AshlandsOldMansHouse_Text_FamilyShrine::
	.string "{JPN}はいの なかでも ちり ひとつなく\n"
	.string "ととのえられた ちいさな かみだなだ。\p"
	.string "しゃしんが 3まい ならんでいる。\p"
	.string "よげんしゃの ころもを まとった ろうじんが\n"
	.string "かざんを せに いかめしく たっている。\p"
	.string "ちょうさノートを もった わかものが\n"
	.string "てれくさそうに わらっている…\l"
	.string "まちがいなく クラークソンはかせだ。\p"
	.string "そして まつりの めんを もった\n"
	.string "おとこのこ。\p"
	.string "おとこのこの かおは けずりとられている。\n"
	.string "なんねんも かけて ゆびの つめで\l"
	.string "けずったようだ。$"

AshlandsOldMansHouse_Text_Letters::
	.string "{JPN}いのりの ひもで たばねた てがみだ。\n"
	.string "どれも おなじ ひっせき。\p"
	.string "「ちちうえ やまは かみでは ありません。\n"
	.string "しくみです。 しょうめい できます。\l"
	.string "C」\p"
	.string "「ちちうえ へんじを ください。 あのこは\n"
	.string "あなたの いうことを ききます。 ぎしきは\l"
	.string "たとえだと つたえて ください。 C」\p"
	.string "「ちちうえ。 あのこから てがみが こなく\n"
	.string "なりました。 みはって いてください。 C」\p"
	.string "さいごの てがみは ひらかれていない。\n"
	.string "ふうは きられていない。$"
