#ifndef ITERATOR_H
#define ITERATOR_H
typedef struct vtbl_iterator vtbl_iterator_t;
struct iterator_functions{
    vtbl_iterator_t* ptr_;
};
typedef struct iterator_functions iterator_functions_t;

struct iter_object{
    void* pointer_;
};
typedef struct iter_object iterator_t;

#if 1
struct vtbl_iterator{
    iterator_t* (*begin)(const void*);
    iterator_t* (*end)(const void*, int);
    void (*advance)(iterator_t*, int);
    iterator_t* (*next)(iterator_t*, int);
    iterator_t* (*prev)(iterator_t*, int);
    int (*distance)(const iterator_t*, const iterator_t*);
};
#endif 
typedef struct vtbl_iterator vtbl_iterator_t;

iterator_functions_t* init_iterator(const char*);

#endif