#ifndef ITERATOR_H
#define ITERATOR_H
typedef struct vtbl_iterator vtbl_iterator_t;
struct iterator{
    vtbl_iterator_t* ptr_;
};
typedef struct iterator iterator_t;

struct iter_object{
    void* pointer_;
};
typedef struct iter_object iter_object_t;

#if 1
struct vtbl_iterator{
    iter_object_t* (*begin)(const void*);
    iter_object_t* (*end)(const void*, int);
    void (*advance)(iter_object_t*, int);
    iter_object_t* (*next)(iter_object_t*, int);
    iter_object_t* (*prev)(iter_object_t*, int);
    int (*distance)(const iter_object_t*, const iter_object_t*);
};
#endif 
typedef struct vtbl_iterator vtbl_iterator_t;

iterator_t* init_iterator(vtbl_iterator_t*);

#endif