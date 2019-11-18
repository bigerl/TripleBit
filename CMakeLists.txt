cmake_minimum_required(VERSION 3.13)
project(untitled2)


set(CMAKE_CXX_STANDARD 98)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

file(GLOB CPP_FILES
        ${PROJECT_SOURCE_DIR}/TripleBit/*.cpp
        ${PROJECT_SOURCE_DIR}/TripleBit/*.h
        ${PROJECT_SOURCE_DIR}/TripleBit/util/*.cpp
        ${PROJECT_SOURCE_DIR}/TripleBit/util/*.h
        )
add_executable(tripleBitQuery TripleBitQuery/TripleBitQuery.cpp ${CPP_FILES})

target_link_libraries(tripleBitQuery Threads::Threads raptor)

target_include_directories(tripleBitQuery PUBLIC ${PROJECT_SOURCE_DIR}/TripleBit/)

#target_sources(tripleBitQuery PUBLIC ${PROJECT_SOURCE_DIR}/TripleBit/)
# include_directories(${PROJECT_SOURCE_DIR}/TripleBit)