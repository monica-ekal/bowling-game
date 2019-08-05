cmake_minimum_required(VERSION 3.14)
project(BowlingGame)

include_directories(/home/monica/googletest/googletest/include/)
set(CMAKE_CXX_STANDARD 11)

link_directories(/home/monica/googletest/build/lib)
set(SOURCE_FILES BowlingTests.cpp ../src/BowlingGame.h ../src/BowlingGame.cpp)
add_executable(BowlingGameTests ${SOURCE_FILES})

target_link_libraries(BowlingGameTests gtest gtest_main pthread)