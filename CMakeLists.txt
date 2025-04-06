cmake_minimum_required(VERSION 3.21)
project(sandsim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE thirdparty/include)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    # Win64
    target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE thirdparty/lib/win64)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE SDL3)
else()
    # Win32
	target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE thirdparty/lib/win32)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE SDL3)
endif()