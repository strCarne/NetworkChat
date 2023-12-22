cmake_minimum_required(VERSION 3.25)
project(ClientGUI)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_executable(ClientGUI
    main.cpp
    Menu.hpp
    Menu.cpp
    Button.cpp
    Button.hpp
    Message.hpp
    Message.cpp
    Messages.hpp
    Messages.cpp
    InputBox.hpp
    InputBox.cpp
    TCPClient.hpp
    TCPClient.cpp
    )
include_directories(/usr/local/include)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})

include_directories("~/SFML/include/")
target_link_libraries(ClientGUI sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
