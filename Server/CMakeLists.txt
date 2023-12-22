cmake_minimum_required(VERSION 3.25)
project(Server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_executable(Server
    main.cpp
    TCPServer.hpp
    TCPServer.cpp
)