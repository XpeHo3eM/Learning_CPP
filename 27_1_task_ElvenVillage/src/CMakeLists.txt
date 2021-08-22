cmake_minimum_required (VERSION 3.8)


add_executable (27_1_task_ElvenVillage
				main.cpp "tree.cpp" "clear.cpp")


target_include_directories (27_1_task_ElvenVillage PUBLIC ${MY_INCLUDE_PATH})