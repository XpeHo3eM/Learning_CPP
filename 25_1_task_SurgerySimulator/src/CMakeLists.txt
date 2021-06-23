cmake_minimum_required (VERSION 3.8)


add_executable (25_1_task_SurgerySimulator main.cpp ${MY_INCLUDE_PATH}/instruments.h ${MY_INCLUDE_PATH}/dot.h)
target_include_directories (25_1_task_SurgerySimulator PUBLIC ${MY_INCLUDE_PATH})