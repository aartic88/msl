#-------------FOR PPP folder----------------------------------

add_executable(bnb ppp/bnc.cpp)
add_executable(name_pair ppp/name_pair.cpp)
add_executable(book ppp/book.cpp)
add_executable(patron ppp/Patron.cpp)
add_executable(rational ppp/rational.cpp)

#-------------FOR LEETCODE folder--------------------------------

add_executable(remove_outer_paran leetcode/remove_outer_paran.cpp)
target_link_libraries(remove_outer_paran msl gtest gtest_main pthread)

add_executable(basketball_game leetcode/basketball_game.cpp)
target_link_libraries(basketball_game msl gtest gtest_main pthread)

add_executable(good_string leetcode/good_string.cpp)
target_link_libraries(good_string msl gtest gtest_main pthread)

add_executable(next_greater_elem leetcode/next_greater_elem.cpp)
target_link_libraries(next_greater_elem msl gtest gtest_main pthread)