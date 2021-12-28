cmake_minimum_required (VERSION 3.8)


add_executable (29_1_task_PetsMeeting 
				main.cpp	animal.cpp)


target_include_directories (29_1_task_PetsMeeting PUBLIC ${MY_INCLUDE_PATH})