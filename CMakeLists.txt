cmake_minimum_required(VERSION 3.10)
project(Stronghold)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stronghold
    main.cpp
    GameEngine.cpp
    Kingdom.cpp
    Map.cpp
    Conflict.cpp
    Market.cpp
    Alliance.cpp
    Communication.cpp
    Event.cpp
    Bank.cpp
    Economy.cpp
    Leader.cpp
    Military.cpp
    Population.cpp
    SocialClass.cpp
) 