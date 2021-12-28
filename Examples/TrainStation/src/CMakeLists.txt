cmake_minimum_required (VERSION 3.8)


add_executable (28_2_task_TrainStation 
				main.cpp	train.cpp	clear.cpp)


target_include_directories (28_2_task_TrainStation PUBLIC ${MY_INCLUDE_PATH})