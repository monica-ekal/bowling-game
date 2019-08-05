cmake_minimum_required(VERSION 3.14)
project(BowlingGame)


set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES BowlingGame.h BowlingGame.cpp BowlingGame_main.cpp)
add_executable(BowlingGame ${SOURCE_FILES})

