cmake_minimum_required (VERSION 3.8)

add_executable (26_3_task_WindowControl 
				main.cpp	window.cpp	commands.cpp	clear.cpp)

target_include_directories (26_3_task_WindowControl PUBLIC ${MY_INCLUDE_PATH})