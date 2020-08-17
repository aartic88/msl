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

add_executable(SinglyLinkedList_test SinglyLinkedList_test.cpp)
target_link_libraries(SinglyLinkedList_test msl gtest gtest_main pthread)
add_test(SinglyLinkedList_test SinglyLinkedList_test)

add_executable(doublylinklist_test doublylinklist_test.cpp)
target_link_libraries(doublylinklist_test msl gtest gtest_main pthread)
add_test(doublylinklist_test doublylinklist_test)

add_executable(CircularlyLinkedList_test CircularlyLinkedList_test.cpp)
target_link_libraries(CircularlyLinkedList_test msl gtest gtest_main pthread)
add_test(CircularlyLinkedList_test CircularlyLinkedList_test)

add_executable(ArrayStack_test ArrayStack_test.cpp)
target_link_libraries(ArrayStack_test msl gtest gtest_main pthread)
add_test(ArrayStack_test ArrayStack_test)

add_executable(LinkedStack_test LinkedStack_test.cpp)
target_link_libraries(LinkedStack_test msl gtest gtest_main pthread)
add_test(LinkedStack_test LinkedStack_test)

add_executable(ArrayVector_test ArrayVector_test.cpp)
target_link_libraries(ArrayVector_test msl gtest gtest_main pthread)
add_test(ArrayVector_test ArrayVector_test)

add_executable(NodeList_test NodeList_test.cpp)
target_link_libraries(NodeList_test msl gtest gtest_main pthread)
add_test(NodeList_test NodeList_test)

add_executable(LinkedBinaryTree_test LinkedBinaryTree_test.cpp)
target_link_libraries(LinkedBinaryTree_test msl gtest gtest_main pthread)
add_test(LinkedBinaryTree_test LinkedBinaryTree_test)

add_executable(ListPriorityQueue_test ListPriorityQueue_test.cpp)
target_link_libraries(ListPriorityQueue_test msl gtest gtest_main pthread)
add_test(ListPriorityQueue_test ListPriorityQueue_test)

add_executable(heappriorityqueue_test heappriorityqueue_test.cpp)
target_link_libraries(heappriorityqueue_test msl gtest gtest_main pthread)
add_test(heappriorityqueue_test heappriorityqueue_test)