cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

file(GLOB_RECURSE TASKS_FILES "src/*/*.cpp")
foreach(TASK_FILE ${TASKS_FILES})
    get_filename_component(TASK_NAME ${TASK_FILE} NAME_WE)
    add_executable(${TASK_NAME} ${TASK_FILE})
endforeach()
