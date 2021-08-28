cmake_minimum_required (VERSION 3.8)


add_executable (27_3_task_CompanySimulator 
				main.cpp	employee.cpp	company.cpp)


target_include_directories (27_3_task_CompanySimulator PUBLIC ${MY_INCLUDE_PATH})