cmake_minimum_required(VERSION 3.17)
project(borodulinartm_iz1)

set(CMAKE_CXX_STANDARD 14)

set(LIB_SOURCE_FILES ./code/rebuilder_mass.c)
add_library(study_std_lib ${LIB_SOURCE_FILES})
add_executable(prog ./code/main.c)
target_link_libraries(prog study_std_lib)

# gtest libs
enable_testing()
find_package(GTest REQUIRED)

# adds the gtest directory
include_directories(${GTEST_INCLUDE_DIRS})
message(${GTEST_LIBRARIES})

# add tests
add_executable(tests ./code/tests.cpp)

target_link_libraries(tests ${GTEST_LIBRARIES} -lpthread)
target_link_libraries(tests study_std_lib)