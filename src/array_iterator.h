#ifndef ARRAY_ITERATOR_H
#define ARRAY_ITERATOR_H

struct array_iterator{
    int* pointer_;
};
typedef struct array_iterator iterator_t;

// iterator_t* init_iterator();

iterator_t* begin(const int*);
iterator_t* end(const int*, int);
iterator_t* next(iterator_t*, int);
iterator_t* prev(iterator_t*, int);
int distance(const iterator_t*, const iterator_t*);
void advance(iterator_t*, int);
#endif