cmake_minimum_required(VERSION 3.4)
project(boostMulticastExample)

find_package(Boost 1.60.0 COMPONENTS system REQUIRED)

if(Boost_FOUND)
    message(WARNING "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(WARNING "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(WARNING "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(boostMulticastExample ${SOURCE_FILES})

target_link_libraries(boostMulticastExample ${Boost_LIBRARIES})