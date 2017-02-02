cmake_minimum_required(VERSION 3.6)
project(FarStar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


set(SOURCE_FILES
        main.cc
        src/Equipment.cc include/Equipment.h
        src/Ship.cc include/Ship.h
        src/Weapon.cc include/Weapon.h
        src/Container.cc include/Container.h
        src/Phaser.cc src/Phaser.cc
        src/Blaster.cc include/Blaster.h
        tests/PhaserTest.h tests/PhaserTest.cc
        )

add_executable(FarStar ${SOURCE_FILES})

target_link_libraries(FarStar gtest gtest_main)
