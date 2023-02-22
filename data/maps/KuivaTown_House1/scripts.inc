KuivaTown_House1_MapScripts::
	.byte 0

KuivaTown_House1_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_OBTAINED_POKEMON, KuivaTown_House1_EventScript_GoingOnAdventure
	msgbox KuivaTown_House1_Text_LovelyDay, MSGBOX_DEFAULT
	release
	end

KuivaTown_House1_EventScript_GoingOnAdventure::
	msgbox KuivaTown_House1_Text_GoingOnAdventure, MSGBOX_DEFAULT	
	release
	end 

KuivaTown_House1_Text_LovelyDay:
	.string "Oh, hello {PLAYER}!\n"
	.string "Lovely day out, isn't it?$"

KuivaTown_House1_Text_GoingOnAdventure:
	.string "So, you're going on an\n"
	.string "adventure?\p"
	.string "You remind me of myself in\n"
	.string "my youth.\l"
	.string "I envy you, kiddo.$"

