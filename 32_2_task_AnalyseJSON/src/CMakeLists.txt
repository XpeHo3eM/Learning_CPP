 
set (JSON_BuildTests OFF CACHE INTERNAL "")


add_executable (32_2_task_AnalyseJSON 
				main.cpp	createJSON.cpp)


target_include_directories (32_2_task_AnalyseJSON PUBLIC ${MY_INCLUDE_PATH})
target_link_libraries (32_2_task_AnalyseJSON PRIVATE nlohmann_json::nlohmann_json)