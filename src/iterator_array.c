#ifndef ARRAY_ITERATOR_C
#define ARRAY_ITERATOR_C
#include "iterator.h"
#include "iterator_array.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#define DEBUG 1
//random access iterators
static iterator_t* begin(const void* array){
    iterator_t* it = malloc(sizeof(iterator_t));
    it->pointer_ = (int*)array;
    return it;
}

static iterator_t* end(const void* array,...){
    //does not work with pointers
    //int n = sizeof(array)/sizeof(array[0]);
    va_list valist;
    va_start(valist,1);
    int n = va_arg(valist, int);
    va_end(valist);
    iterator_t* it = malloc(sizeof(iterator_t));
    it->pointer_ = (int*)array + n;
    return it;
}

static void advance(iterator_t* it, int n){
    it->pointer_ = (int*)it->pointer_ + n;
}

static iterator_t* next(iterator_t* it, int n){
    advance(it, n);
    return it;
}

static iterator_t* prev(iterator_t* it, int n){
    advance(it, -n);
    return it;
}

static int distance(const iterator_t* it1, const iterator_t* it2){
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

