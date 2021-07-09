cmake_minimum_required (VERSION 3.8)

add_executable (25_2_task_ComputerSimulator 
                main.cpp        cpu.cpp        disk.cpp        gpu.cpp 
                kbd.cpp         ram.cpp        const.cpp)
target_include_directories (25_2_task_ComputerSimulator PUBLIC ${MY_INCLUDE_PATH})