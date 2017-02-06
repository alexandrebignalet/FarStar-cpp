cmake_minimum_required(VERSION 3.6)
project(FarStar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


set(SOURCE_FILES
        main.cc
        src/Equipment.cc include/Equipment.h
        include/Ship.h src/Ship.cc
        src/Weapon.cc include/Weapon.h
        src/Container.cc include/Container.h
        src/Phaser.cc include/Phaser.h
        src/Blaster.cc include/Blaster.h
        src/TransportShip.cc include/TransportShip.h
        src/WarShip.cc include/WarShip.h
        src/LightWeightWarShip.cc include/LightWeightWarShip.h
        src/HybridShip.cc include/HybridShip.h
        src/HeavyWarShip.cc include/HeavyWarShip.h)

set(TEST_FILES
        tests/EquipmentTest.cc
        tests/BlasterTest.cc
        tests/TransportShipTest.cc
        tests/WarShipTest.cc
        tests/LightWeightWarShipTest.cc
        tests/HybridShipTest.cc
        tests/HeavyWarShipTest.cc)

add_executable(FarStar ${SOURCE_FILES} ${TEST_FILES})

target_link_libraries(FarStar gtest gtest_main)
