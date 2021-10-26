cmake_minimum_required (VERSION 3.8)


add_executable (31_1_SharedPtrToy 
				main.cpp	sharedPtrToy.cpp	dog.cpp)

target_include_directories (31_1_SharedPtrToy PUBLIC ${MY_INCLUDE_PATH})