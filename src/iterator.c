#include "iterator.h"
#include "doubly_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

//abstract class
iterator_t* begin(void* ptr){

}
iterator_t* end(void* ptr){

}
iterator_t* next(iterator_t* it, int n){

}
iterator_t* prev(iterator_t* it, int n){

}
int distance(iterator_t* it1, iterator_t* it2){

}
void advance(iterator_t* it, int n){

}

static vtbl_iterator_t vtbl_iter = {
    begin,
    end,
    next,
    prev,
    distance,
    advance
};

iterator_t* init_iterator(){
    iterator_t* temp = malloc(sizeof(iterator_t));
    temp->pointer_ = NULL;
    temp->ptr_ = &vtbl_iter;
    return temp;
}