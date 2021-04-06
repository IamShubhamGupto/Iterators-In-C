#ifndef LIST_ITERATOR_C
#define LIST_ITERATOR_C
#include "iterator.h"
#include "iterator_list.h"
#include "doubly_linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#define DEBUG 0
//bidirectional access iterators
static iter_object_t* begin(const list_t* list){
    iter_object_t* it = malloc(sizeof(iter_object_t));
    it->pointer_ = list->head_;
    return it;
}

static iter_object_t* end(const list_t* list, int n){
    //does not work with pointers
    //int n = sizeof(array)/sizeof(array[0]);
    iter_object_t* it = malloc(sizeof(iter_object_t));
    node_t* temp = init_node(-1);
    temp->prev_ = list->tail_;
    it->pointer_ = temp;
    if(DEBUG){
        printf("[end DEBUG] %d\n", ((node_t*)it->pointer_)->prev_->value_);
    }
    return it;
}

static void advance(iter_object_t* it, int n){
    int i = 0;
    if(n > 0){
        while(i < n){
            ++i;
            it->pointer_ = ((node_t*)it->pointer_)->next_;
        }
    }else{
        while(n < i){
            --i;
            it->pointer_ = ((node_t*)it->pointer_)->prev_;
        }
    }
    
    
}

static iter_object_t* next(iter_object_t* it, int n){
    advance(it, n);
    return it;
}

static iter_object_t* prev(iter_object_t* it, int n){
    advance(it, -n);
    return it;
}

static int distance(const iter_object_t* it1, const iter_object_t* it2){
    node_t* first = (node_t*)it1->pointer_;
    node_t* last = (node_t*)it2->pointer_;
    int i = 1;
    while(first != last && first->next_ != NULL){
        ++i;
        first = first->next_;
    }
    return i;
}

vtbl_list_t vtbl_list = {
    begin,
    end,
    advance,
    next,
    prev,
    distance
};

#endif

