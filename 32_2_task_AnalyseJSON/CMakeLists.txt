cmake_minimum_required (VERSION 3.8)

project ("32_2_task_AnalyseJSON" VERSION 1.0)

set (CMAKE_CXX_STANDART 17)
 
set (JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory (nlohmann_json)

add_executable (32_2_task_AnalyseJSON 
					main.cpp	createJSON.cpp	 createJSON.h)

target_link_libraries (32_2_task_AnalyseJSON PRIVATE nlohmann_json::nlohmann_json)