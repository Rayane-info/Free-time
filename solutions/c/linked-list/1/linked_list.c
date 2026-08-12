#include "linked_list.h"
#include "stdlib.h"
#include "assert.h"
#include "stdio.h"

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

// constructs a new (empty) list
struct list *list_create(void){
    struct list *new_list = malloc(sizeof(struct list));
    if (new_list){
        new_list->first = NULL;
        new_list->last = NULL;
    }
    return new_list;
}

struct list_node *node_create(ll_data_t item_data){
    struct list_node *new_node = malloc(sizeof(struct list_node));
    if (new_node){
        new_node->data = item_data;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    return new_node;    
}

// counts the items on a list
size_t list_count(const struct list *list){
    if (!list || !list->first){
        return 0;
    }
    size_t count = 0;
    struct list_node *curr = list->first;
    while (curr){
        count++;
        curr = curr->next;
    }
    return count;
}

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data){
    if (!list){
        return;
    }
    if (!list->first){
        struct list_node *new_node = node_create(item_data);
        list->first = new_node;
        list->last = new_node;
        return;
    } else {
        struct list_node *new_node = node_create(item_data);
        new_node->prev = list->last;
        list->last->next = new_node;
        list->last = new_node;
        return;
    } 
}

// removes item from back of a list
ll_data_t list_pop(struct list *list){
    if (!list || !list->first){
        return 0;
    }
    if (list->first == list->last){
        ll_data_t data = list->last->data;
        free(list->last);
        list->first = NULL;
        list->last = NULL;
        return data;
    } else {
        ll_data_t data = list->last->data;
        struct list_node *last = list->last->prev;
        free(list->last);
        last->next = NULL;
        list->last = last;
        return data;
    }
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data){
    struct list_node *new_node = node_create(item_data);
    if (!list){
        return;
    }   
    if (!list->first){
        list->first = new_node;
        list->last = new_node;
        return;
    } else {
        struct list_node *first = list->first;
        new_node->next = first;
        first->prev = new_node;
        list->first = new_node;
        return;
    }
}

// removes item from front of a list
ll_data_t list_shift(struct list *list){
    if (!list || !list->first){
        return 0;
    }
    if (list->first == list->last){
        ll_data_t data = list->first->data;
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        return data;
    } else {
        ll_data_t data = list->first->data;
        struct list_node *next = list->first->next;
        free(list->first);
        next->prev = NULL;
        list->first = next;
        return data;
    }
}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data){
    if (!list || !list->first){
        return;
    }
    struct list_node *curr = list->first;
    while (curr){
        if (curr->data == data){
            if (curr->next == NULL){
                list_pop(list);
                return;
            } else if (curr->prev == NULL){
                list_shift(list);
                return;
            } else {
                struct list_node *prev = curr->prev;
                prev->next = curr->next;
                curr->next->prev = prev;
                free(curr);
                return;
            }
        }
        curr = curr->next;
    }
}

// destroys an entire list
void list_destroy(struct list *list){    
    if (!list){
        return;
    }
    struct list_node *curr = list->first;
    while (curr){
        struct list_node *next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
    return;
}

// ============ NEW FUNCTIONS ============

struct list_node *list_find(struct list *list, ll_data_t data){
    if (!list || !list->first){
        return NULL;
    }
    struct list_node *curr = list->first;
    while (curr){
        if (curr->data == data){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

struct list_node *list_find_last(struct list *list, ll_data_t data){
    if (!list || !list->first){
        return NULL;
    }
    struct list_node *curr = list->last;
    while (curr){
        if (curr->data == data){
            return curr;
        }
        curr = curr->prev;
    }
    return NULL;
}

struct list_node *list_get_node(struct list *list, size_t index){
    if (!list || !list->first){
        return NULL;
    }
    struct list_node *curr = list->first;
    size_t count = 0;
    while (curr){
        if (count == index){
            return curr;
        }
        count++;
        curr = curr->next;
    }
    return NULL;
}

ll_data_t list_get(struct list *list, size_t index){
    struct list_node *node = list_get_node(list, index);
    if (!node) return 0;
    return node->data;
}

ll_data_t list_remove_at(struct list *list, size_t index){
    if (!list || !list->first){
        return 0;
    }
    struct list_node *curr = list->first;
    size_t count = 0;
    while (curr){
        if (index == count){
            if (!curr->next){
                ll_data_t data = list->last->data;
                list_pop(list);
                return data;
            }
            if (!curr->prev){
                ll_data_t data = list->first->data;
                list_shift(list);
                return data;
            }
            struct list_node *prev = curr->prev;
            struct list_node *next = curr->next;
            ll_data_t data = curr->data;
            prev->next = next;
            next->prev = prev;
            free(curr);
            return data;
        }
        count++;
        curr = curr->next;
    }
    return 0;
}

void list_print(const struct list *list){
    if (!list || !list->first){
        return;
    }
    struct list_node *curr = list->first;
    while (curr){
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    return;
}

struct list *list_copy(const struct list *list){
    if (!list || !list->first){
        return NULL;
    }
    
    struct list *copy_list = list_create();
    if (!copy_list) return NULL;
    
    struct list_node *curr = list->first;
    while (curr){
        list_push(copy_list, curr->data);  // ← Use list_push!
        curr = curr->next;
    }
    
    return copy_list;
}