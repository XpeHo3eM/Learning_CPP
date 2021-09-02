cmake_minimum_required (VERSION 3.8)


add_executable (28_3_task_Restaurant 
				main.cpp	restaurant.cpp)


target_include_directories (28_3_task_Restaurant PUBLIC ${MY_INCLUDE_PATH})