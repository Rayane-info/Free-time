#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef int ll_data_t;
struct list;

// constructs a new (empty) list
struct list *list_create(void);

// creates a new node
struct list_node *node_create(ll_data_t item_data);


// counts the items on a list
size_t list_count(const struct list *list);

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data);

// removes item from back of a list
ll_data_t list_pop(struct list *list);

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data);

// removes item from front of a list
ll_data_t list_shift(struct list *list);

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data);

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list);

// ============ NEW FUNCTIONS TO IMPLEMENT ============

// 1. Find the first node containing data
// Returns: pointer to node, or NULL if not found
struct list_node *list_find(struct list *list, ll_data_t data);

// 2. Find the last node containing data (search from tail)
// Returns: pointer to node, or NULL if not found
struct list_node *list_find_last(struct list *list, ll_data_t data);

// 3. Get node at specific index (0-based)
// Returns: pointer to node, or NULL if index out of bounds
struct list_node *list_get_node(struct list *list, size_t index);


ll_data_t list_get(struct list *list, size_t index);

// 6. Remove and return data at specific index
ll_data_t list_remove_at(struct list *list, size_t index);


// 9. Print the list (for debugging)
void list_print(const struct list *list);

// 10. Create a copy of the list
struct list *list_copy(const struct list *list);

#endif
