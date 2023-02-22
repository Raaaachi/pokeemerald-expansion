.set LOCALID_SANDSHREW, 2

KummaDesert_MapScripts::
	.byte 0

KummaDesert_EventScript_NoPokemon::
	lockall 
	msgbox KummaDesert_Text_ShouldNotGoThere, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	release
	end 

KummaDesert_EventScript_FoundBag1::
	lockall 
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, KummaDesert_Movement_ApproachBag1
	waitmovement 0
	delay 16 
	goto KummaDesert_EventScript_StarterSequence

KummaDesert_EventScript_FoundBag2::
	lockall 
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, KummaDesert_Movement_ApproachBag2
	waitmovement 0
	delay 16 
	goto KummaDesert_EventScript_StarterSequence

KummaDesert_Movement_ApproachBag1:
	walk_up
	walk_up
	step_end

KummaDesert_Movement_ApproachBag2:
	walk_left
	walk_up
	walk_up
	step_end

KummaDesert_EventScript_StarterSequence::
	addobject LOCALID_SANDSHREW
	msgbox KummaDesert_Text_BagSeemsToBeShaking, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SANDSHREW, KummaDesert_Movement_SandshrewApproach
	waitmovement 0 
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0 
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_SANDSHREW, CRY_MODE_ENCOUNTER	
	delay 40
	playbgm MUS_DP_LAKE_EVENT, TRUE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_OBTAINED_POKEMON
	setvar VAR_KUMMA_DESERT_STATE, 1
	setvar VAR_NEW_GAME_STATE, 1
	special ChooseStarter 
	setflag FLAG_FORCE_FACE_RIGHT
	delay 1
	removeobject LOCALID_SANDSHREW
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 32
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox KummaDesert_Text_SomethingElseInside, MSGBOX_DEFAULT
	call KummaDesert_EventScript_ReceivePokedex
	delay 32
	warp MAP_KUIVA_TOWN_PLAYERS_HOUSE_1F, 4, 6
	release
	end

KummaDesert_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message KummaDesert_Text_FoundPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	closemessage
	return

KummaDesert_Movement_SandshrewApproach:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

KummaDesert_Text_ShouldNotGoThere:
	.string "It's too dangerous to go there without\n"
	.string "a Pokémon.$"

KummaDesert_Text_BagSeemsToBeShaking:
	.string "The bag seems to be shaking…\n"
	.string "Maybe something is inside?$"

KummaDesert_Text_SomethingElseInside:
	.string "Seems something else is inside the bag.$"

KummaDesert_Text_FoundPokedex:
	.string "{PLAYER} found the Pokédex!$"

