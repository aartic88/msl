set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#-------------FOR PPP folder----------------------------------

add_executable(bnb ppp/bnc.cpp)
add_executable(name_pair ppp/name_pair.cpp)
add_executable(book ppp/book.cpp)
add_executable(patron ppp/Patron.cpp)
add_executable(rational ppp/rational.cpp)

#-------------FOR LEETCODE folder--------------------------------
#
#----STACK-------
add_executable(remove_outer_paran leetcode/stack/remove_outer_paran.cpp)
target_link_libraries(remove_outer_paran msl gtest gtest_main pthread)

add_executable(basketball_game leetcode/stack/basketball_game.cpp)
target_link_libraries(basketball_game msl gtest gtest_main pthread)

add_executable(good_string leetcode/stack/good_string.cpp)
target_link_libraries(good_string msl gtest gtest_main pthread)

add_executable(next_greater_elem leetcode/stack/next_greater_elem.cpp)
target_link_libraries(next_greater_elem msl gtest gtest_main pthread)
#
#
#------QUEUE------
add_executable(recent_counter leetcode/queue/recent_counter.cpp)
target_link_libraries(recent_counter msl gtest gtest_main pthread)

#
#
#-------HEAP--------
add_executable(last_stone_weight leetcode/heap/last_stone_weight.cpp)
target_link_libraries(last_stone_weight msl gtest gtest_main pthread)

add_executable(Kth_largest leetcode/heap/Kth_largest.cpp)
target_link_libraries(Kth_largest msl gtest gtest_main pthread)

#
#-------DIVIDE & CONQUER--------
add_executable(majority_element leetcode/divide&conquer/majority_element.cpp)
target_link_libraries(majority_element msl gtest gtest_main pthread)

add_executable(maxsubarray leetcode/divide&conquer/maxsubarray.cpp)
target_link_libraries(maxsubarray msl gtest gtest_main pthread)

add_executable(k_closest leetcode/divide&conquer/k_closest.cpp)
target_link_libraries(k_closest msl gtest gtest_main pthread)

add_executable(beautiful_array leetcode/divide&conquer/beautiful_array.cpp)
target_link_libraries(beautiful_array msl gtest gtest_main pthread)

add_executable(kth_largest leetcode/divide&conquer/kth_largest.cpp)
target_link_libraries(kth_largest msl gtest gtest_main pthread)

add_executable(median_sorted_arrays leetcode/divide&conquer/median_sorted_arrays.cpp)
target_link_libraries(median_sorted_arrays msl gtest gtest_main pthread) 

add_executable(search_matrix leetcode/divide&conquer/search_matrix.cpp)
target_link_libraries(search_matrix msl gtest gtest_main pthread) 

#
#------HASH TABLE-------------
add_executable(good_pairs leetcode/hashtable/good_pairs.cpp)
target_link_libraries(good_pairs msl gtest gtest_main pthread)


#-----------DFS/BFS-------------
add_executable(course_schedule leetcode/dfs_bfs/course_schedule.cpp)
target_link_libraries(course_schedule msl gtest gtest_main pthread)

add_executable(course_schedule2 leetcode/dfs_bfs/courses_chedule2.cpp)
target_link_libraries(course_schedule2 msl gtest gtest_main pthread)

add_executable(snakes_ladder leetcode/dfs_bfs/snakes_ladder.cpp)
target_link_libraries(snakes_ladder msl gtest gtest_main pthread)

add_executable(shortest_bridge leetcode/dfs_bfs/shortest_bridge.cpp)
target_link_libraries(shortest_bridge msl gtest gtest_main pthread)

add_executable(shortest_bridge_reduce_graph leetcode/dfs_bfs/shortest_bridge_reduce_graph.cpp)
target_link_libraries(shortest_bridge_reduce_graph msl gtest gtest_main pthread)