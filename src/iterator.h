#ifndef ITERATOR_H
#define ITERATOR_H

struct vtbl_iterator;

struct iterator{
    struct vtbl_iterator* ptr_;
};
typedef struct iterator iterator_t;

struct iter_object{
    void* pointer_;
};
typedef struct iter_object iter_object_t;

struct vtbl_iterator{
    iter_object_t* (*begin)(const void*);
    iter_object_t* (*end)(const void*, int);
    void (*advance)(iter_object_t*, int);
    iter_object_t* (*next)(iter_object_t*, int);
    iter_object_t* (*prev)(iter_object_t*, int);
    int (*distance)(const iter_object_t*, const iter_object_t*);
};
typedef struct vtbl_iterator vtbl_iterator_t;

iterator_t* init_iterator(vtbl_iterator_t*);

extern vtbl_iterator_t vtbl_array;
extern vtbl_iterator_t vtbl_list;

#endif