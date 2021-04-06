#ifndef ARRAY_ITERATOR_C
#define ARRAY_ITERATOR_C
#include "iterator.h"
#include "iterator_array.h"
#include <stdlib.h>
#include <stdio.h>
#define DEBUG 1
//random access iterators
static iter_object_t* begin(const int* array){
    iter_object_t* it = malloc(sizeof(iter_object_t));
    it->pointer_ = (int*)array;
    return it;
}

static iter_object_t* end(const int* array, int n){
    //does not work with pointers
    //int n = sizeof(array)/sizeof(array[0]);
    iter_object_t* it = malloc(sizeof(iter_object_t));
    it->pointer_ = (int*)array + n;
    return it;
}

static void advance(iter_object_t* it, int n){
    it->pointer_ = (int*)it->pointer_ + n;
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
    return (int*)it2->pointer_ - (int*)it1->pointer_;
}

vtbl_array_t vtbl_array = {
    begin,
    end,
    advance,
    next,
    prev,
    distance
};

#endif

