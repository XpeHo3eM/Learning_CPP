cmake_minimum_required (VERSION 3.17)

set (CMAKE_CXX_STANDARD 14)

set (BUILD_CPR_TESTS OFF)
set (CMAKE_USE_OPENSSL OFF)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG c8d33915dbd88ad6c92b258869b03aba06587ff9) # the commit hash for 1.5.0
FetchContent_MakeAvailable(cpr)

add_executable (30_2_task_UsersRequests		
				main.cpp)

target_link_libraries (30_2_task_UsersRequests PRIVATE cpr::cpr)
target_include_directories (30_2_task_UsersRequests PUBLIC ${MY_INCLUDE_PATH})