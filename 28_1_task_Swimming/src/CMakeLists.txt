cmake_minimum_required (VERSION 3.8)


add_executable (28_1_task_Swimming 
				main.cpp	clear.cpp	swimmer.cpp)


target_include_directories (28_1_task_Swimming PUBLIC ${MY_INCLUDE_PATH})