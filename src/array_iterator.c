#include "array_iterator.h"
#include <stdlib.h>
#include <stdio.h>
#define DEBUG 1
//random access iterators
iterator_t* begin(const int* array){
    iterator_t* it = malloc(sizeof(iterator_t));
    it->pointer_ = array;
    return it;
}

iterator_t* end(const int* array, int n){
    //does not work with pointers
    //int n = sizeof(array)/sizeof(array[0]);
    iterator_t* it = malloc(sizeof(iterator_t));
    it->pointer_ = array+n;
    return it;
}

void advance(iterator_t* it, int n){
    it->pointer_ = it->pointer_ + n;
}

iterator_t* next(iterator_t* it, int n){
    advance(it, n);
    return it;
}

iterator_t* prev(iterator_t* it, int n){
    advance(it, -n);
    return it;
}

int distance(const iterator_t* it1, const iterator_t* it2){
    return it2->pointer_ - it1->pointer_;
}

