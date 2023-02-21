.set LOCALID_MAN, 1

KuivaTown_House2_MapScripts::
	.byte 0

KuivaTown_House2_EventScript_Man::
	lock
	faceplayer
	msgbox KuivaTown_House2_Text_SoBoring, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

KuivaTown_House2_Text_SoBoring:
	.string "The only thing to do around here\n"
	.string "is watch TV.\l"
	.string "Who would want to live here?\p"
	.string "…\p"
	.string "Oh… Us.$"

