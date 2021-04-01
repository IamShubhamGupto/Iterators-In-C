#ifndef ITERATOR_H
#define ITERATOR_H
struct iterator;

struct vtbl_iterator{
    struct iterator* (*begin)(void*);
    struct iterator* (*end)(void*);
    struct iterator* (*next)(struct iterator*, int);
    struct iterator* (*prev)(struct iterator*, int);
    int (*distance)(struct iterator*, struct iterator*);
    void (*advance)(struct iterator*, int);
};
typedef struct vtbl_iterator vtbl_iterator_t;

struct iterator{
    void* pointer_;
    vtbl_iterator_t* ptr_;
};
typedef struct iterator iterator_t;

iterator_t* init_iterator();

// iterator_t* begin(void*);
// iterator_t* end(void*);
// iterator_t* next(iterator_t*, int);
// iterator_t* prev(iterator_t*, int);
// int distance(iterator_t*, iterator_t*);
// void advance(iterator_t*, int);
#endif