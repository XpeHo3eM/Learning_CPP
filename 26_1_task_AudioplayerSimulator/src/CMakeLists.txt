﻿cmake_minimum_required (VERSION 3.8)

add_executable (26_1_task_AudioplayerSimulator 
				main.cpp	track.cpp	audioPlayer.cpp 
				clear.cpp	date.cpp	commands.cpp)

target_include_directories (26_1_task_AudioplayerSimulator PUBLIC ${MY_INCLUDE_PATH})