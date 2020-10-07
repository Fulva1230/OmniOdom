cmake_minimum_required(VERSION 3.17)
project(omniodom C CXX)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.10.0
)
FetchContent_MakeAvailable(googletest)

find_package(Eigen3 MODULE REQUIRED)

add_library(omniodom src/timer.h src/wheelrecorder.cpp src/wheelrecorder.h src/anglesensor.h src/wheelstate.h src/wheelrecord.cpp src/wheelrecord.h)
target_include_directories(omniodom PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(omniodom Eigen3::Eigen)

add_executable(odomtest test/odomtest.cpp)
target_link_libraries(odomtest gtest_main gmock omniodom)
