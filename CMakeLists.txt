cmake_minimum_required(VERSION 3.15)
project(AsioPractice)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-lpthread")
find_package(Boost REQUIRED)
find_package(gflags)

add_executable(AsioPractice main.cpp Server.cpp Server.h Session.cpp Session.h UtilityValue.h Client.cpp Client.h)
target_link_libraries(AsioPractice ${Boost_LIBRARIES} gflags)