#include "sublist.h"
#include <stdbool.h>
#include <stddef.h>

static bool are_arrays_equal(const int *tab1, const int *tab2, size_t count) {
    for (size_t i = 0; i < count; i++) {
        if (tab1[i] != tab2[i]) {
            return false;
        }
    }
    return true;
}

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count) {
    
    // Case 1: Same size → check equality
    if (list_to_compare_element_count == base_list_element_count) {
        if (are_arrays_equal(list_to_compare, base_list, list_to_compare_element_count)) {
            return EQUAL;
        } else {
            return UNEQUAL;
        }
    }
    
    // Case 2: base_list is longer → list_to_compare might be a SUBLIST
    if (base_list_element_count > list_to_compare_element_count) {
        if (list_to_compare_element_count == 0) {
            return SUBLIST;
        }
        
        size_t max_start = base_list_element_count - list_to_compare_element_count;
        for (size_t start = 0; start <= max_start; start++) {
            if (are_arrays_equal(base_list + start, list_to_compare, list_to_compare_element_count)) {
                return SUBLIST;
            }
        }
        return UNEQUAL;
    }
    
    // Case 3: list_to_compare is longer → base_list might be a SUPERLIST
    if (list_to_compare_element_count > base_list_element_count) {
        if (base_list_element_count == 0) {
            return SUPERLIST;
        }
        
        size_t max_start = list_to_compare_element_count - base_list_element_count;
        for (size_t start = 0; start <= max_start; start++) {
            if (are_arrays_equal(list_to_compare + start, base_list, base_list_element_count)) {
                return SUPERLIST;
            }
        }
        return UNEQUAL;
    }
    
    return UNEQUAL;
}