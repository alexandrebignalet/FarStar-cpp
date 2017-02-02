cmake_minimum_required(VERSION 3.6)
project(FarStar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


set(SOURCE_FILES
        main.cc
        src/Equipment.cc src/Equipment.h
        src/Ship.cc src/Ship.h
        src/Weapon.cc src/Weapon.h
        src/Container.cc src/Container.h
        src/Phaser.cc src/Phaser.cc
        src/Blaster.cc src/Blaster.h
        tests/PhaserTest.h tests/PhaserTest.cc
        )

add_executable(FarStar ${SOURCE_FILES})

target_link_libraries(FarStar gtest gtest_main)
