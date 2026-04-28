PROJECT(DSA)
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

set(CMAKE_FILES_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build_cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

########### cmake configuration and compiler flags ###########
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()

SET(CMAKE_BUILD_TYPE Debug)
# SET(CMAKE_C_FLAGS_DEBUG " -Wall -g")
# SET(CMAKE_CXX_FLAGS_DEBUG " -Wall -g")
# SET(CMAKE_C_FLAGS_RELEASE " -Wall")
# SET(CMAKE_CXX_FLAGS_RELEASE " -Wall")
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) #static libraries
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) #executables
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) #dynamic libraries (plugins)

find_package(GTest REQUIRED)

enable_testing()

# DATA STRUCTS

# priority queue (max heap)
add_library(priority_queue 
${PROJECT_SOURCE_DIR}/src/data_struct/priority_queue/priority_queue.cpp)
target_include_directories(priority_queue PUBLIC include)
target_link_libraries(priority_queue PRIVATE GTest::gtest_main)

add_executable(data_struct 
${PROJECT_SOURCE_DIR}/src/data_struct/main.cpp)
target_include_directories(data_struct PUBLIC include/data_struct/vector)
target_link_libraries(data_struct PUBLIC priority_queue
                                  PRIVATE GTest::gtest_main)

# ALGORITHMS (by topic)

# add_executable(duplicate_zeros
#   ${PROJECT_SOURCE_DIR}/src/algorithms/duplicate_zeros.cpp
# )

add_executable(linked_list_cycle2
  ${PROJECT_SOURCE_DIR}/src/algorithms/linked_list_cycle_2.cpp
)

add_executable(intersection_list
 ${PROJECT_SOURCE_DIR}/src/algorithms/intersection_list.cpp
)

add_executable(multidouble_list
 ${PROJECT_SOURCE_DIR}/src/algorithms/multidouble_list.cpp
)

add_executable(tree
 ${PROJECT_SOURCE_DIR}/src/algorithms/tree.cpp
)

add_executable(trie
 ${PROJECT_SOURCE_DIR}/src/algorithms/trie_impl.cpp)

add_executable(long_sub
 ${PROJECT_SOURCE_DIR}/src/algorithms/long_substr.cpp)

add_executable(valid_bst
${PROJECT_SOURCE_DIR}/src/algorithms/valid_bst.cpp)

add_executable(n_queens
${PROJECT_SOURCE_DIR}/src/algorithms/n_queens.cpp)

add_executable(sudoku_solver
${PROJECT_SOURCE_DIR}/src/algorithms/sudoku_solver.cpp)

add_executable(largest_rect_hist
${PROJECT_SOURCE_DIR}/src/algorithms/largest_rect_hist.cpp)

add_executable(letter_combin
${PROJECT_SOURCE_DIR}/src/algorithms/letter_combin.cpp)

add_executable(LRU_cache
${PROJECT_SOURCE_DIR}/src/algorithms/LRU_cache.cpp)

# sliding window

add_executable(long_subarr_of_1_after_del_one_elem
${PROJECT_SOURCE_DIR}/src/algorithms/sliding_window/long_subarr_of_1_after_del_one_elem.cpp)

add_executable(interval_list_intersect
${PROJECT_SOURCE_DIR}/src/algorithms/sliding_window/interval_list_intersect.cpp)

add_executable(max_consecutive_ones_3
${PROJECT_SOURCE_DIR}/src/algorithms/sliding_window/max_consecutive_ones_3.cpp)

add_executable(minimum_size_subarr_sum
${PROJECT_SOURCE_DIR}/src/algorithms/sliding_window/minimum_size_subarr_sum.cpp)

# string

add_executable(string_compress
${PROJECT_SOURCE_DIR}/src/algorithms/string/string_compress.cpp)

add_executable(isomorph_string
${PROJECT_SOURCE_DIR}/src/algorithms/string/isomorph_string.cpp)

add_executable(valid_palindrome
${PROJECT_SOURCE_DIR}/src/algorithms/string/valid_palindrome.cpp)

add_executable(long_substr_without_rep
${PROJECT_SOURCE_DIR}/src/algorithms/string/long_substr_without_rep.cpp)

add_executable(group_anagram
${PROJECT_SOURCE_DIR}/src/algorithms/string/group_anagram.cpp)

add_executable(find_all_anogram
${PROJECT_SOURCE_DIR}/src/algorithms/string/find_all_anogram.cpp)

add_executable(is_subseq
${PROJECT_SOURCE_DIR}/src/algorithms/string/is_subseq.cpp)

add_executable(simplify_path
${PROJECT_SOURCE_DIR}/src/algorithms/string/simplify_path.cpp)

add_executable(longest_repeat_char_rep
${PROJECT_SOURCE_DIR}/src/algorithms/string/longest_repeat_char_rep.cpp)

add_executable(longest_substr_with_at_least_k_char
${PROJECT_SOURCE_DIR}/src/algorithms/string/long_substr_with_at_least_k_char.cpp)

add_executable(reverse_words_in_string_3
${PROJECT_SOURCE_DIR}/src/algorithms/string/reverse_words_in_string_3.cpp)

add_executable(top_k_freq_words
${PROJECT_SOURCE_DIR}/src/algorithms/string/top_k_freq_words.cpp)

add_executable(find_idx_of_first_occur_in_str
${PROJECT_SOURCE_DIR}/src/algorithms/string/find_idx_of_first_occur_in_str.cpp)

# array

add_executable(move_zeros
${PROJECT_SOURCE_DIR}/src/algorithms/array/move_zeros.cpp)

add_executable(summary_ranges
${PROJECT_SOURCE_DIR}/src/algorithms/array/summary_ranges.cpp)

add_executable(line_reflect
${PROJECT_SOURCE_DIR}/src/algorithms/array/line_reflection.cpp)

add_executable(merge_interval
${PROJECT_SOURCE_DIR}/src/algorithms/array/merge_interval.cpp)

add_executable(two_sum
${PROJECT_SOURCE_DIR}/src/algorithms/array/two_sum.cpp)

add_executable(merge_sort_arr
${PROJECT_SOURCE_DIR}/src/algorithms/array/merge_sort_arr.cpp)

add_executable(product_of_array
${PROJECT_SOURCE_DIR}/src/algorithms/array/product_of_array.cpp)

add_executable(single_number
${PROJECT_SOURCE_DIR}/src/algorithms/array/single_number.cpp)

add_executable(remove_element
${PROJECT_SOURCE_DIR}/src/algorithms/array/remove_element.cpp)

add_executable(intersection_of_two_arr
${PROJECT_SOURCE_DIR}/src/algorithms/array/intersection_of_two_arr.cpp)

add_executable(subarray_sum_eq_k
${PROJECT_SOURCE_DIR}/src/algorithms/array/subarr_sum_eq_k.cpp) # prefix sum pattern

add_executable(continuous_subarray_sum
${PROJECT_SOURCE_DIR}/src/algorithms/array/continuous_subarray_sum.cpp) # prefix sum pattern

add_executable(kth_larg_elem_in_arr
${PROJECT_SOURCE_DIR}/src/algorithms/array/kth_larg_elem_in_arr.cpp)

add_executable(sort_matrix_diagonal
${PROJECT_SOURCE_DIR}/src/algorithms/array/sort_matrix_diagonal.cpp)

add_executable(remove_dup_from_sort_arr_2
${PROJECT_SOURCE_DIR}/src/algorithms/array/remove_dup_from_sort_arr_2.cpp)

add_executable(find_diff_in_array
${PROJECT_SOURCE_DIR}/src/algorithms/array/find_diff_in_array.cpp)

add_executable(rotate_image
${PROJECT_SOURCE_DIR}/src/algorithms/array/rotate_image.cpp)

add_executable(3sum
${PROJECT_SOURCE_DIR}/src/algorithms/array/3sum.cpp)

add_executable(long_conseq_seq
${PROJECT_SOURCE_DIR}/src/algorithms/array/long_conseq_seq.cpp)

# graph

add_executable(num_islands
${PROJECT_SOURCE_DIR}/src/algorithms/graph/num_islands.cpp)

# math

add_executable(eval_reverse_polish_not
${PROJECT_SOURCE_DIR}/src/algorithms/math/eval_reverse_polish_not.cpp)

add_executable(reverse_integer
${PROJECT_SOURCE_DIR}/src/algorithms/math/reverse_integer.cpp)

add_executable(robot_return_orig
${PROJECT_SOURCE_DIR}/src/algorithms/math/robot_return_orig.cpp)

add_executable(path_crossing
${PROJECT_SOURCE_DIR}/src/algorithms/math/path_crossing.cpp)

# list

add_executable(merge_two_sort_list
${PROJECT_SOURCE_DIR}/src/algorithms/list/merge_two_sort_list.cpp)

add_executable(add_two_numbers_other
${PROJECT_SOURCE_DIR}/src/algorithms/list/add_two_numbers_other.cpp)

add_executable(add_two_numbers
 ${PROJECT_SOURCE_DIR}/src/algorithms/list/add_two_numbers.cpp
)

# tree

add_executable(find_dup_subtree
${PROJECT_SOURCE_DIR}/src/algorithms/tree/find_dup_subtree.cpp)

add_executable(binary_right_side_view
${PROJECT_SOURCE_DIR}/src/algorithms/tree/binary_right_side_view.cpp)

add_executable(lowest_common_ancestor_of_binary
${PROJECT_SOURCE_DIR}/src/algorithms/tree/lowest_common_ancestor_of_binary.cpp)

add_executable(symmetric_tree
${PROJECT_SOURCE_DIR}/src/algorithms/tree/symmetric_tree.cpp)

add_executable(bin_tree_zigzag_level_order_trav
${PROJECT_SOURCE_DIR}/src/algorithms/tree/bin_tree_zigzag_level_order_trav.cpp)

add_executable(balanced_binary_tree
${PROJECT_SOURCE_DIR}/src/algorithms/tree/balanced_binary_tree.cpp)

# dynamic prog

add_executable(fibonacci_num
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/fibonacci_num.cpp)

add_executable(climbing_stairs
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/climbing_stairs.cpp)

add_executable(house_robber
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/house_robber.cpp)
target_link_libraries(house_robber PRIVATE GTest::gtest_main)

add_executable(house_robber_2
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/house_robber_2.cpp)
target_link_libraries(house_robber_2 PRIVATE GTest::gtest_main)

add_executable(min_cost_path
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/min_cost_path.cpp)

add_executable(decod_digit
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/decod_digit.cpp)

add_executable(subset_sum
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/subset_sum.cpp)

add_executable(coin_change
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/coin_change.cpp)

add_executable(best_sell_stock
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/best_sell_stock.cpp)

add_executable(perfect_square
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/perfect_square.cpp)

add_executable(jump_game_2
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/jump_game_2.cpp)
target_link_libraries(jump_game_2 PRIVATE GTest::gtest_main)

add_executable(max_subarray
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/max_subarray.cpp)
target_link_libraries(max_subarray PRIVATE GTest::gtest_main)

add_executable(jump_game
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/jump_game.cpp)
target_link_libraries(jump_game PRIVATE GTest::gtest_main)

add_executable(unique_path
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/unique_path.cpp)
target_link_libraries(unique_path PRIVATE GTest::gtest_main)

add_executable(unique_paths_2
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/unique_paths_2.cpp)
target_link_libraries(unique_paths_2 PRIVATE GTest::gtest_main)

add_executable(min_path_sum
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/min_path_sum.cpp)
target_link_libraries(min_path_sum PRIVATE GTest::gtest_main)

add_executable(edit_distance
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/edit_distance.cpp)
target_link_libraries(edit_distance PRIVATE GTest::gtest_main)

add_executable(decode_ways
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/decode_ways.cpp)
target_link_libraries(decode_ways PRIVATE GTest::gtest_main)

add_executable(uniq_bst
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/uniq_bst.cpp)
target_link_libraries(uniq_bst PRIVATE GTest::gtest_main)

add_executable(uniq_bst_2
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/uniq_bst_2.cpp)
target_link_libraries(uniq_bst_2 PRIVATE GTest::gtest_main)

add_executable(interleav_str
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/interleav_str.cpp)
target_link_libraries(interleav_str PRIVATE GTest::gtest_main)

add_executable(triangle
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/triangle.cpp)
target_link_libraries(triangle PRIVATE GTest::gtest_main)

add_executable(palindrome_part
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/palindrome_part.cpp)
target_link_libraries(palindrome_part PRIVATE GTest::gtest_main)

add_executable(max_prod_sub
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/max_prod_sub.cpp)
target_link_libraries(max_prod_sub PRIVATE GTest::gtest_main)

add_executable(max_sq
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/max_sq.cpp)
target_link_libraries(max_sq PRIVATE GTest::gtest_main)

add_executable(diff_way_to_add_parenth
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/diff_way_to_add_parenth.cpp)
target_link_libraries(diff_way_to_add_parenth PRIVATE GTest::gtest_main)

add_executable(ugly_num_2
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/ugly_num_2.cpp)
target_link_libraries(ugly_num_2 PRIVATE GTest::gtest_main)

add_executable(best_sell_stock_cooldown
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/best_sell_stock_cooldown.cpp)
target_link_libraries(best_sell_stock_cooldown PRIVATE GTest::gtest_main)

add_executable(super_ugly_num
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/super_ugly_num.cpp)
target_link_libraries(super_ugly_num PRIVATE GTest::gtest_main)

add_executable(coin_change_leet
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/coin_change_leet.cpp)
target_link_libraries(coin_change_leet PRIVATE GTest::gtest_main)

add_executable(house_robber_3
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/house_robber_3.cpp)
target_link_libraries(house_robber_3 PRIVATE GTest::gtest_main)

add_executable(int_break
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/int_break.cpp)
target_link_libraries(int_break PRIVATE GTest::gtest_main)

add_executable(count_num_with_uniq_dig
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/count_num_with_uniq_dig.cpp)
target_link_libraries(count_num_with_uniq_dig PRIVATE GTest::gtest_main)

add_executable(largest_div_subset
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/largest_div_subset.cpp)
target_link_libraries(largest_div_subset PRIVATE GTest::gtest_main)

add_executable(guess_num_high_or_low_2
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/guess_num_high_or_low_2.cpp)
target_link_libraries(guess_num_high_or_low_2 PRIVATE GTest::gtest_main)

add_executable(wiggle_subseq
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/wiggle_subseq.cpp)
target_link_libraries(wiggle_subseq PRIVATE GTest::gtest_main)

add_executable(combin_sum_4
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/combin_sum_4.cpp)
target_link_libraries(combin_sum_4 PRIVATE GTest::gtest_main)

add_executable(rotate_function
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/rotate_function.cpp)
target_link_libraries(rotate_function PRIVATE GTest::gtest_main)

add_executable(uniq_sub_in_wrap_str
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/uniq_sub_in_wrap_str.cpp)
target_link_libraries(uniq_sub_in_wrap_str PRIVATE GTest::gtest_main)

add_executable(ones_and_zeros
${PROJECT_SOURCE_DIR}/src/algorithms/dynamic_prog/ones_and_zeros.cpp)
target_link_libraries(ones_and_zeros PRIVATE GTest::gtest_main)

# greedy

add_executable(atm_machine
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/atm_machine.cpp)

add_executable(longest_palindrome
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/longest_palindrome.cpp)
target_link_libraries(longest_palindrome PRIVATE GTest::gtest_main)

add_executable(assign_cookies
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/assign_cookies.cpp)
target_link_libraries(assign_cookies PRIVATE GTest::gtest_main)

add_executable(can_place_flower
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/can_place_flower.cpp)
target_link_libraries(can_place_flower PRIVATE GTest::gtest_main)

add_executable(valid_palindrome_2
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/valid_palindrome_2.cpp)
target_link_libraries(valid_palindrome_2 PRIVATE GTest::gtest_main)

add_executable(di_string_match
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/di_string_match.cpp)
target_link_libraries(di_string_match PRIVATE GTest::gtest_main)

add_executable(part_arr_into_three_part
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/part_arr_into_three_part.cpp)
target_link_libraries(part_arr_into_three_part PRIVATE GTest::gtest_main)

add_executable(max_69_num
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/max_69_num.cpp)
target_link_libraries(max_69_num PRIVATE GTest::gtest_main)

add_executable(min_subseq_in_non_incr_ord
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/min_subseq_in_non_incr_ord.cpp)
target_link_libraries(min_subseq_in_non_incr_ord PRIVATE GTest::gtest_main)

add_executable(max_units_on_truck
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/max_units_on_truck.cpp)
target_link_libraries(max_units_on_truck PRIVATE GTest::gtest_main)

add_executable(min_oper_to_make_arr_inc
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/min_oper_to_make_arr_inc.cpp)
target_link_libraries(min_oper_to_make_arr_inc PRIVATE GTest::gtest_main)

add_executable(largest_odd_num_in_str
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/largest_odd_num_in_str.cpp)
target_link_libraries(largest_odd_num_in_str PRIVATE GTest::gtest_main)

add_executable(min_num_of_move_to_seat_every
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/min_num_of_move_to_seat_every.cpp)
target_link_libraries(min_num_of_move_to_seat_every PRIVATE GTest::gtest_main)

add_executable(min_sum_of_four_dig
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/min_sum_of_four_dig.cpp)
target_link_libraries(min_sum_of_four_dig PRIVATE GTest::gtest_main)

add_executable(min_num_of_oper_to_conv_time
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/min_num_of_oper_to_conv_time.cpp)
target_link_libraries(min_num_of_oper_to_conv_time PRIVATE GTest::gtest_main)

add_executable(remove_dig_from_numb_to_max_res
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/remove_dig_from_numb_to_max_res.cpp)
target_link_libraries(remove_dig_from_numb_to_max_res PRIVATE GTest::gtest_main)

add_executable(min_amount_of_time_to_fill_cup
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/min_amount_of_time_to_fill_cup.cpp)
target_link_libraries(min_amount_of_time_to_fill_cup PRIVATE GTest::gtest_main)

add_executable(gas_station
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/gas_station.cpp)
target_link_libraries(gas_station PRIVATE GTest::gtest_main)

add_executable(wiggle_sort_2
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/wiggle_sort_2.cpp)
target_link_libraries(wiggle_sort_2 PRIVATE GTest::gtest_main)

add_executable(increase_trip_subseq
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/increase_trip_subseq.cpp)
target_link_libraries(increase_trip_subseq PRIVATE GTest::gtest_main)

add_executable(task_scheduler
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/task_scheduler.cpp)
target_link_libraries(task_scheduler PRIVATE GTest::gtest_main)

add_executable(max_len_of_pair_chain
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/max_len_of_pair_chain.cpp)
target_link_libraries(max_len_of_pair_chain PRIVATE GTest::gtest_main)

add_executable(dota2_senate
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/dota2_senate.cpp)
target_link_libraries(dota2_senate PRIVATE GTest::gtest_main)

add_executable(max_swap
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/max_swap.cpp)
target_link_libraries(max_swap PRIVATE GTest::gtest_main)

add_executable(valid_parentheses
${PROJECT_SOURCE_DIR}/src/algorithms/greedy/valid_parentheses.cpp)
target_link_libraries(valid_parentheses PRIVATE GTest::gtest_main)

# backtracking

add_executable(permutation_2
${PROJECT_SOURCE_DIR}/src/algorithms/backtracking/permutation_2.cpp)
target_link_libraries(permutation_2 PRIVATE GTest::gtest_main)

# sort

add_executable(merge_sort
${PROJECT_SOURCE_DIR}/src/algorithms/sort/merge_sort.cpp)

add_executable(find_k_closest_elem
${PROJECT_SOURCE_DIR}/src/algorithms/sort/find_k_closest_elem.cpp)

add_executable(sort_colors
${PROJECT_SOURCE_DIR}/src/algorithms/sort/sort_colors.cpp)
target_link_libraries(sort_colors PRIVATE GTest::gtest_main)

add_executable(insertion_sort_list
${PROJECT_SOURCE_DIR}/src/algorithms/sort/insertion_sort_list.cpp)
target_link_libraries(insertion_sort_list PRIVATE GTest::gtest_main)

add_executable(sort_list
${PROJECT_SOURCE_DIR}/src/algorithms/sort/sort_list.cpp)
target_link_libraries(sort_list PRIVATE GTest::gtest_main)

add_executable(maximum_gap
${PROJECT_SOURCE_DIR}/src/algorithms/sort/maximum_gap.cpp)
target_link_libraries(maximum_gap PRIVATE GTest::gtest_main)

add_executable(simple_sort
${PROJECT_SOURCE_DIR}/src/algorithms/sort/simple_sort.cpp)
target_link_libraries(simple_sort  PUBLIC  priority_queue
                                PRIVATE GTest::gtest_main)

# search

add_executable(find_min_in_rot_sort_arr
${PROJECT_SOURCE_DIR}/src/algorithms/search/find_min_in_rot_sort_arr.cpp)

add_executable(two_sum_2
${PROJECT_SOURCE_DIR}/src/algorithms/search/two_sum_2.cpp)

add_executable(search_2d_matrix
${PROJECT_SOURCE_DIR}/src/algorithms/search/search_2d_matrix.cpp)

# GTest ALGORITHM test's

# dp test
# gtest_discover_tests(jump_game_2)
# gtest_discover_tests(max_subarray)
# gtest_discover_tests(jump_game)
# gtest_discover_tests(unique_path)
# gtest_discover_tests(unique_paths_2)
# gtest_discover_tests(min_path_sum)
# gtest_discover_tests(edit_distance)
# gtest_discover_tests(decode_ways)
# gtest_discover_tests(uniq_bst)
# gtest_discover_tests(uniq_bst_2)
# gtest_discover_tests(interleav_str)
# gtest_discover_tests(triangle)
# gtest_discover_tests(palindrome_part)
# gtest_discover_tests(max_prod_sub)
# gtest_discover_tests(house_robber_2)
# gtest_discover_tests(diff_way_to_add_parenth)
# gtest_discover_tests(ugly_num_2)
# gtest_discover_tests(best_sell_stock_cooldown)
# gtest_discover_tests(super_ugly_num)
# gtest_discover_tests(coin_change_leet)
# gtest_discover_tests(house_robber_3)
# gtest_discover_tests(int_break)
# gtest_discover_tests(count_num_with_uniq_dig)
# gtest_discover_tests(largest_div_subset)
# gtest_discover_tests(guess_num_high_or_low_2)
# gtest_discover_tests(wiggle_subseq)
# gtest_discover_tests(combin_sum_4)
# gtest_discover_tests(rotate_function)
# gtest_discover_tests(uniq_sub_in_wrap_str)
# gtest_discover_tests(ones_and_zeros)

# greedy test
# gtest_discover_tests(longest_palindrome)
# gtest_discover_tests(assign_cookies)
# gtest_discover_tests(valid_palindrome_2)
# gtest_discover_tests(di_string_match)
# gtest_discover_tests(part_arr_into_three_part)
# gtest_discover_tests(max_69_num)
# gtest_discover_tests(min_subseq_in_non_incr_ord)
# gtest_discover_tests(max_units_on_truck)
# gtest_discover_tests(min_oper_to_make_arr_inc)
# gtest_discover_tests(largest_odd_num_in_str)
# gtest_discover_tests(min_num_of_move_to_seat_every)
# gtest_discover_tests(min_sum_of_four_dig)
# gtest_discover_tests(min_num_of_oper_to_conv_time)
# gtest_discover_tests(remove_dig_from_numb_to_max_res)
# gtest_discover_tests(min_amount_of_time_to_fill_cup)
# gtest_discover_tests(gas_station)
# gtest_discover_tests(wiggle_sort_2)
# gtest_discover_tests(increase_trip_subseq)
# gtest_discover_tests(task_scheduler)
# gtest_discover_tests(max_len_of_pair_chain)
# gtest_discover_tests(dota2_senate)
# gtest_discover_tests(max_swap)
# gtest_discover_tests(valid_parentheses)

# backtrack test
# gtest_discover_tests(permutation_2)

# sort
# gtest_discover_tests(sort_colors)
# gtest_discover_tests(insertion_sort_list)
# gtest_discover_tests(sort_list)
# gtest_discover_tests(maximum_gap)
# gtest_discover_tests(simple_sort)
gtest_discover_tests(data_struct)