SplitCave_2F_MapScripts::
	.byte 0

Route114_EventScript_Shane::
	trainerbattle_single TRAINER_SHANE, SplitCave_2F_Text_ShaneIntro, SplitCave_2F_Text_ShaneDefeat
	msgbox SplitCave_2F_Text_ShanePostBattle, MSGBOX_AUTOCLOSE
	end