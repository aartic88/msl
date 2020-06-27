enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

# create an executable for test
add_executable(prime_test prime_test.cpp)
# Link test executable against gtest, pthread & gtest_main. This will not work in windows
# Link with msl librabry
target_link_libraries(prime_test msl gtest gtest_main pthread)
# Mark the executable as a test
add_test(prime_test prime_test)

# create an executable for test
add_executable(linkedlist_test linkedlist_test.cpp)
# Link test executable against gtest, pthread & gtest_main. This will not work in windows
# Link with msl librabry
target_link_libraries(linkedlist_test msl gtest gtest_main pthread)
# Mark the executable as a test
add_test(linkedlist_test linkedlist_test)

# create an executable for test
add_executable(arraylist_test arraylist_test.cpp)
# Link test executable against gtest, pthread & gtest_main. This will not work in windows
# Link with msl librabry
target_link_libraries(arraylist_test msl gtest gtest_main pthread)
# Mark the executable as a test
add_test(arraylist_test linkedlist_test)