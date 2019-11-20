cmake_minimum_required(VERSION 3.10)
project(TripleBit)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

file(GLOB CPP_FILES
        ${PROJECT_SOURCE_DIR}/TripleBit/*.cpp
        ${PROJECT_SOURCE_DIR}/TripleBit/*.h
        ${PROJECT_SOURCE_DIR}/TripleBit/util/*.cpp
        ${PROJECT_SOURCE_DIR}/TripleBit/util/*.h
        )
include_directories(${PROJECT_SOURCE_DIR}/TripleBit/)

add_executable(triplebitQuery TripleBitQuery/TripleBitQuery.cpp ${CPP_FILES})
target_link_libraries(triplebitQuery Threads::Threads raptor)

add_executable(buildTripleBitFromN3 BuildTripleBitFromN3/BuildTripleBit.cpp ${CPP_FILES})
target_link_libraries(buildTripleBitFromN3 Threads::Threads raptor)

add_executable(buildTripleBitFromRDF BuildTripleBitFromRDF/BuildTripleBit.cpp ${CPP_FILES})
target_link_libraries(buildTripleBitFromRDF Threads::Threads raptor)