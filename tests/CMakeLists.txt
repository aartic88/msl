enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

# create an executable for test
add_executable(stl_test stl_test.cpp)
# Link test executable against gtest & gtest_main. This will not work in windows
target_link_libraries(stl_test gtest gtest_main pthread)
# Mark the executable as a test
add_test(stl_test stl_test)