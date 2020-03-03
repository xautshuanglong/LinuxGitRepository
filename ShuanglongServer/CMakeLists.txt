# cmake version 3.10.2

# For Library
# CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)
# PROJECT(ShuanglongServer)
# FILE(GLOB SRC_LIST_CPP ${PROJECT_SOURCE_DIR}/src/*.cpp)
# FILE(GLOB SRC_LIST_C ${PROJECT_SOURCE_DIR}/src/*.c)
# INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
# SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# ADD_LIBRARY(myprint SHARED ${SRC_LIST_CPP} ${SRC_LIST_C})

# For Executable
cmake_minimum_required(VERSION 3.10.2)

project(ShuanglongServer)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_MAIN)

message(STATUS "PROJECT_SOURCE_DIR" ${PROJECT_SOURCE_DIR})
# message(WARNING "messge warning test")
# message(AUTHOR_WARNING "messge author_warning test")
# message(SEND_ERROR "messge send_error test")
# message(FATAL_ERROR "messge fatal_error test")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/utils)

add_executable(${PROJECT_NAME}.out ${SRC_MAIN})

target_link_libraries(${PROJECT_NAME}.out utils)

