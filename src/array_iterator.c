#ifndef ARRAY_ITERATOR_C
#define ARRAY_ITERATOR_C
#include "iterator.h"
#include "array_iterator.h"
#include <stdlib.h>
#include <stdio.h>
#define DEBUG 1
//random access iterators
iter_object_t* begin(const void* array){
    iter_object_t* it = malloc(sizeof(iter_object_t));
    it->pointer_ = (int*)array;
    return it;
}

iter_object_t* end(const void* array, int n){
    //does not work with pointers
    //int n = sizeof(array)/sizeof(array[0]);
    iter_object_t* it = malloc(sizeof(iter_object_t));
    it->pointer_ = (int*)array + n;
    return it;
}

void advance(iter_object_t* it, int n){
    it->pointer_ = (int*)it->pointer_ + n;
}

iter_object_t* next(iter_object_t* it, int n){
    advance(it, n);
    return it;
}

iter_object_t* prev(iter_object_t* it, int n){
    advance(it, -n);
    return it;
}

int distance(const iter_object_t* it1, const iter_object_t* it2){
    return (int*)it2->pointer_ - (int*)it1->pointer_;
}

vtbl_iterator_t vtbl_array = {
    begin,
    end,
    advance,
    next,
    prev,
    distance
};

#endif

