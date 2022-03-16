cmake_minimum_required (VERSION 3.8)


project ("37_1_task_Qt_Calculator" VERSION 1.0)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/msvc2019_64/lib/cmake")

find_package(Qt5 COMPONENTS 
			Core
			Gui
			Widgets
			REQUIRED)

add_executable (37_1_task_Qt_Calculator
				main.cpp    calc.cpp    calc.h    calc.ui)

target_link_libraries(37_1_task_Qt_Calculator
					  Qt5::Core
					  Qt5::Gui
					  Qt5::Widgets)

if (WIN32)
	set (QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}/../..")
	
	set (DEBUG_SUFFIX)
	if (CMAKE_BUILD_TYPE STREQUAL "Debug")
		set (DEBUG_SUFFIX "d")	
	endif()

	if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
		add_custom_command (TARGET ${PROJECT_NAME} POST_BUILD
				COMMAND ${CMAKE_COMMAND} -E make_directory
				"$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
		add_custom_command (TARGET ${PROJECT_NAME} POST_BUILD
				COMMAND ${CMAKE_COMMAND} -E copy
				"${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
				"$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
	endif()

	foreach (QT_LIB Core Gui Widgets)
		add_custom_command (TARGET ${PROJECT_NAME} POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy
			"${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
			"$<TARGET_FILE_DIR:${PROJECT_NAME}>")
	endforeach (QT_LIB)
endif()