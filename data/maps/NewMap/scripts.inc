NewMap_MapScripts::
	.byte 0

@ ============================================================================
@  Villagers - the pre-dawn oni sighting (foreshadow the climb up Mt. Munen)
@ ============================================================================
NewMap_EventScript_Watchman::
	lock
	faceplayer
	msgbox NewMap_Text_Watchman, MSGBOX_DEFAULT
	release
	end

NewMap_EventScript_WorriedWoman::
	lock
	faceplayer
	msgbox NewMap_Text_WorriedWoman, MSGBOX_DEFAULT
	release
	end

NewMap_EventScript_OldMan::
	lock
	faceplayer
	msgbox NewMap_Text_OldMan, MSGBOX_DEFAULT
	release
	end

NewMap_EventScript_Kid::
	lock
	faceplayer
	goto_if_set FLAG_NEWMAP_TUNNEL_RUMOR, NewMap_EventScript_KidDare
	msgbox NewMap_Text_Kid, MSGBOX_DEFAULT
	release
	end

NewMap_EventScript_KidDare::
	msgbox NewMap_Text_KidDare, MSGBOX_DEFAULT
	release
	end

NewMap_EventScript_Skeptic::
	lock
	faceplayer
	msgbox NewMap_Text_Skeptic, MSGBOX_DEFAULT
	release
	end

NewMap_EventScript_MountainHint::
	lock
	faceplayer
	msgbox NewMap_Text_MountainHint, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@  Tame Pokemon ambiance (cry when spoken to)
@ ============================================================================
NewMap_EventScript_Poochyena::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	msgbox NewMap_Text_Poochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

NewMap_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox NewMap_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

NewMap_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox NewMap_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

@ ============================================================================
@  Munen Tunnel entrance + Itsuki's boarded-up house
@ ============================================================================
NewMap_EventScript_TunnelSign::
	msgbox NewMap_Text_TunnelSign, MSGBOX_SIGN
	end

NewMap_EventScript_ApprenticeDoorCrates::
	lock
	msgbox NewMap_Text_ApprenticeDoorCrates, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@  Text
@ ============================================================================
NewMap_Text_Watchman::
	.string "{JPN}よあけまえに れつを つくって やつらが\n"
	.string "もんを くぐって いった。 みんな\l"
	.string "オニの めんを つけて ひとことも しゃべらずに。\p"
	.string "まっすぐ スターサミットへ のぼって\n"
	.string "ふりかえりも しなかった。 ぞっとしたよ。$"

NewMap_Text_WorriedWoman::
	.string "{JPN}あなたも めんの ひとたちを みたの？\p"
	.string "オニの めんを つけた ひとたちが\n"
	.string "さんちょうに なんの ようが あるのかしら…$"

NewMap_Text_OldMan::
	.string "{JPN}ひの でる まえの オニの めん。\p"
	.string "わしの じいさまの ころなら それは\n"
	.string "ふたつの うち どちらかじゃった。 まつりか\p"
	.string "さばきか。 たいこの おとは きこえんのう。$"

NewMap_Text_Kid::
	.string "{JPN}みたよ！ でっかくて こわい あかい めん！\p"
	.string "やまみちを すっごい はやさで\n"
	.string "かけのぼってった。 さむくも ないみたいに！\l"
	.string "うえに なにが あるのか しりたい！$"

NewMap_Text_Skeptic::
	.string "{JPN}めんの れんちゅう？ ふん。 まつりの\n"
	.string "いちざが はやめに けいこ してるのさ。\p"
	.string "…でも やけに しずかに でていったな。\n"
	.string "それに だれも おりて きていない。$"

NewMap_Text_MountainHint::
	.string "{JPN}あとを おって のぼる つもり？\p"
	.string "うえは きけんよ。 きりの なかでは\n"
	.string "つよい ポケモンが えものを ねらってるの。$"

NewMap_Text_Poochyena::
	.string "{JPN}まちの ポチエナが とびらの そばで\n"
	.string "みみを たてて じっと やまを みている。$"

NewMap_Text_Skitty::
	.string "{JPN}まるまると した エネコが ひだまりで\n"
	.string "なんの しんぱいも なく うとうとしている。$"

NewMap_Text_Wingull::
	.string "{JPN}キャモメが やねの うえで けづくろいを しながら\n"
	.string "やまみちを みている。$"

NewMap_Text_KidDare::
	.string "{JPN}ゲンじいさんと はなしたんだろ？\p"
	.string "ほんとに はかばの トンネルに\n"
	.string "はいるの？！ ほんきで？！\p"
	.string "まえに トウヤに とびらを さわれって\n"
	.string "けしかけたら あいつ 1しゅうかん ないてたんだよ。\p"
	.string "…じつは はいって すぐの ところで\n"
	.string "ひかる ものを みたんだ。 とりには\l"
	.string "もどってない。 あげるよ。 たぶん。$"

NewMap_Text_TunnelSign::
	.string "{JPN}ムネントンネル\p"
	.string "やまの しにびとの\n"
	.string "ねむる ばしょ。 むらの ちょうろうの\l"
	.string "めいにより ふういんする。\p"
	.string "おこしては ならない。\p"
	.string "…かんばんの したの ふうが\n"
	.string "やぶれている。 とびらは ひらいたままだ。$"

NewMap_Text_ApprenticeDoorCrates::
	.string "{JPN}おもい きばこが とびらの まえに\n"
	.string "つまれ くぎで うちつけられている。\p"
	.string "ふたに だいくの しるしが ある:\n"
	.string "「ゲン」\p"
	.string "だれかが この いえを そっとして\n"
	.string "おきたかった ようだ。$"

@ ============================================================================
@  POMPEII NIGHT MARKET (Spirited Away veil-market direction)
@  Ready-to-attach labels -- no objects are placed yet. In Porymap, add the
@  object and point its script at one of these:
@    NewMap_EventScript_LanternLighter  (OBJ_EVENT_GFX_OLD_WOMAN, FACE_UP)
@    NewMap_EventScript_FoodStall       (OBJ_EVENT_GFX_COOK or POKEFAN_M, behind a counter)
@    NewMap_EventScript_TrinketStall    (OBJ_EVENT_GFX_WOMAN_5 or GENTLEMAN)
@    NewMap_EventScript_KimonoDancer    (OBJ_EVENT_GFX_KIMONO_GIRL, WANDER or spin)
@    NewMap_EventScript_MaskedPatron    (OBJ_EVENT_GFX_MAGMA_MEMBER_M, FACE_DOWN)
@    NewMap_EventScript_MarketSign      (bg_event sign)
@  PALETTE NOTE: 3 mon species (Poochyena/Skitty/Wingull) already live on this
@  map -- prefer standard-palette human NPCs here, and verify nothing turns
@  invisible after adding gfx (see palette-exhaustion notes).
@ ============================================================================
NewMap_EventScript_LanternLighter::
	lock
	faceplayer
	msgbox NewMap_Text_LanternLighter, MSGBOX_DEFAULT
	release
	end

NewMap_EventScript_FoodStall::
	lock
	faceplayer
	message NewMap_Text_FoodStallGreeting
	waitmessage
	pokemart NewMap_FoodStallMart
	msgbox NewMap_Text_FoodStallFarewell, MSGBOX_DEFAULT
	release
	end

	.align 2
NewMap_FoodStallMart:
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_LEMONADE
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_RAGE_CANDY_BAR
	.2byte ITEM_CASTELIACONE
	pokemartlistend

NewMap_EventScript_TrinketStall::
	lock
	faceplayer
	message NewMap_Text_TrinketStallGreeting
	waitmessage
	pokemart NewMap_TrinketStallMart
	msgbox NewMap_Text_TrinketStallFarewell, MSGBOX_DEFAULT
	release
	end

	.align 2
NewMap_TrinketStallMart:
	.2byte ITEM_CLEANSE_TAG
	.2byte ITEM_SPELL_TAG
	.2byte ITEM_SMOKE_BALL
	.2byte ITEM_DUSK_BALL
	pokemartlistend

NewMap_EventScript_KimonoDancer::
	lock
	faceplayer
	msgbox NewMap_Text_KimonoDancer, MSGBOX_DEFAULT
	release
	end

@ Masked figure browsing the market. Reacts to the Carved Mask -- ties the
@ Act 2 disguise into town before the player ever needs it.
NewMap_EventScript_MaskedPatron::
	lock
	faceplayer
	checkitem ITEM_CARVED_MASK
	goto_if_eq VAR_RESULT, TRUE, NewMap_EventScript_MaskedPatronNod
	msgbox NewMap_Text_MaskedPatron, MSGBOX_DEFAULT
	release
	end

NewMap_EventScript_MaskedPatronNod::
	msgbox NewMap_Text_MaskedPatronNod, MSGBOX_DEFAULT
	release
	end

NewMap_EventScript_MarketSign::
	msgbox NewMap_Text_MarketSign, MSGBOX_SIGN
	end

@ The slab over the Munen Tunnel mouth. Master Gen has it rolled aside when
@ he gives the Save Face quest (FLAG_POMPEII_TUNNEL_ROCK_CLEARED hides it).
NewMap_EventScript_TunnelRock::
	msgbox NewMap_Text_TunnelRock, MSGBOX_SIGN
	end

NewMap_Text_TunnelRock::
	.string "{JPN}おおきな いしの いたが ふるい\n"
	.string "トンネルの いりぐちを ふさいでいる。 むらの\l"
	.string "はんぶんが かからないと うごかせないだろう。\p"
	.string "ふちには あたらしい のみの あとが ある。\n"
	.string "きりくちを みるに めんづくりの\l"
	.string "しごとの ようだ。$"

NewMap_Text_LanternLighter::
	.string "{JPN}くらく なる まえに ちょうちんは ぜんぶ\n"
	.string "ともす きまり。 ひとつ のこらずね。\p"
	.string "じゅんれいしゃの ためじゃ ないのよ。\n"
	.string "「べつの」 おきゃくさんの ため。\p"
	.string "かみが あかく ひかって はじめて\n"
	.string "でてくる おきゃくさん。$"

NewMap_Text_FoodStallGreeting::
	.string "{JPN}あつあつ！ あまい！ やきたてだよ！\p"
	.string "のぼる まえに しっかり くっとかないと\n"
	.string "やまに くわれちまうぞ！ はっは！$"

NewMap_Text_FoodStallFarewell::
	.string "{JPN}トンネルの いりぐちに たべものを\n"
	.string "おいていくなよ。 「なにか」が よってくるからな。$"

NewMap_Text_TrinketStallGreeting::
	.string "{JPN}おまもりに まよけは いかが たびのかた。\p"
	.string "こんしゅうは この 10ねんぶんより\n"
	.string "うれたよ。 なんでだろうね。$"

NewMap_Text_TrinketStallFarewell::
	.string "{JPN}きよめのおふだは バッグの\n"
	.string "そとがわに つけておきな。 やつらが\l"
	.string "くるのが みえるように しないと。$"

NewMap_Text_KimonoDancer::
	.string "{JPN}まつりには まいてが ひつようだから\n"
	.string "わたしは けいこするの。 めんの ひとたちが\l"
	.string "いても いなくてもね。\p"
	.string "いつか たいこが なりひびいたら\n"
	.string "ポンペイは この いちばが なんの ための\l"
	.string "ものか おもいだすわ。$"

NewMap_Text_MaskedPatron::
	.string "{JPN}オニの めんを つけた ひとかげが\n"
	.string "やたいの あいだで ぴくりとも せず たっている。\p"
	.string "しなものを みるでもなく\n"
	.string "しゃべるでもない。\p"
	.string "ちょうちんの かずを かぞえているのだ。$"

NewMap_Text_MaskedPatronNod::
	.string "{JPN}めんの ひとかげの しせんが こしに さげた\n"
	.string "ほりものの めんへと おちた。\p"
	.string "ひとかげは ゆっくりと うなずき\n"
	.string "また ちょうちんを かぞえはじめた。\p"
	.string "だれかと まちがえられたようだ。\n"
	.string "あるいは なにかと。$"

NewMap_Text_MarketSign::
	.string "{JPN}ポンペイ よるの いちば\p"
	.string "「ちょうちんの あかりは 2しゅるいの\n"
	.string "おきゃくさまを おむかえします。\p"
	.string "「2しゅるいめの おきゃくさまを\n"
	.string "じろじろ みないで ください」$"
