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

add_executable(doublelinklist_test doublelinklist_test.cpp)
target_link_libraries(doublelinklist_test msl gtest gtest_main pthread)
add_test(doublelinklist_test doublelinklist_test)

add_executable(arraylinkedlist_test arraylinkedlist_test.cpp)
target_link_libraries(arraylinkedlist_test msl gtest gtest_main pthread)
add_test(arraylinkedlist_test arraylinkedlist_test)

add_executable(Singlylinklist_test Singlylinklist_test.cpp)
target_link_libraries(Singlylinklist_test msl gtest gtest_main pthread)
add_test(Singlylinklist_test Singlylinklist_test)

add_executable(doublylinklist_test doublylinklist_test.cpp)
target_link_libraries(doublylinklist_test msl gtest gtest_main pthread)
add_test(doublylinklist_test doublylinklist_test)
