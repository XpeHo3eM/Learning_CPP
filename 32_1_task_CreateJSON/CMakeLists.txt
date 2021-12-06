cmake_minimum_required (VERSION 3.8)

project ("32_1_task_CreateJSON" VERSION 1.0)

set (CMAKE_CXX_STANDART 14)

set (JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory (nlohmann_json)

add_executable (32_1_task_CreateJSON main.cpp)

target_link_libraries (32_1_task_CreateJSON PRIVATE nlohmann_json::nlohmann_json)