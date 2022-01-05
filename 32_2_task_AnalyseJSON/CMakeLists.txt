cmake_minimum_required (VERSION 3.8)

project ("32_2_task_AnalyseJSON" VERSION 1.0)

#set (CMAKE_CXX_STANDART 17)

set (MY_INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_subdirectory (nlohmann_json)
add_subdirectory (src)