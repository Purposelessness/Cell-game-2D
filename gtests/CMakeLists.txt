# 'Google_test' is the subproject name
project(GoogleTest)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
add_executable(GoogleTest_run TestField.cpp)
target_link_libraries(GoogleTest_run gtest gtest_main)
