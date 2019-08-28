cmake_minimum_required(VERSION 3.14)
project(boost_udp)

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS_ON)
set(Boost_USE_MULTITHREADED_ON)

find_package(Boost COMPONENTS filesystem REQUIRED)
if (NOT Boost_FOUND)
    MESSAGE(FATAL_ERROR "Could not find boost library.")
endif ()

include_directories(${Boost_INCLUDE_DIRS})

add_executable(boost_udp main.cpp user_interface.cpp user_interface.hpp player_stats.hpp)
target_link_libraries(boost_udp ${Boost_LIBRARIES})