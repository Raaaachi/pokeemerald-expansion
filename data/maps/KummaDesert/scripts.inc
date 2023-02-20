.set LOCALID_BALTOY, 2

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
	addobject LOCALID_BALTOY
	msgbox KummaDesert_Text_BagSeemsToBeShaking, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BALTOY, KummaDesert_Movement_BaltoyApproach
	waitmovement 0 
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0 
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_BALTOY, CRY_MODE_ENCOUNTER	
	delay 40
	playbgm MUS_DP_LAKE_EVENT, TRUE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_KUMMA_DESERT_STATE, 1
	setvar VAR_NEW_GAME_STATE, 1
	special ChooseStarter 
	setflag FLAG_FORCE_FACE_RIGHT
	delay 1
	removeobject LOCALID_BALTOY
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 8
	fadescreen FADE_TO_BLACK
	delay 8
	warp MAP_KUIVA_TOWN_PLAYERS_HOUSE_1F, 4, 6
	release
	end

KummaDesert_Movement_BaltoyApproach:
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

