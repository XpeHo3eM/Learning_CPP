cmake_minimum_required (VERSION 3.8)

add_executable (26_2_task_MobileSimulator 
				main.cpp	commands.cpp	contact.cpp		addressBook.cpp)

target_include_directories (26_2_task_MobileSimulator PUBLIC ${MY_INCLUDE_PATH})