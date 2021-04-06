#ifndef ARRAY_ITERATOR_H
#define ARRAY_ITERATOR_H

#if 0
struct vtbl_array_iterator{
    iter_object_t* (*begin)(const int*);
    iter_object_t* (*end)(const int*, int);
    void (*advance)(iter_object_t*, int);
    iter_object_t* (*next)(iter_object_t*, int);
    iter_object_t* (*prev)(iter_object_t*, int);
    int (*distance)(const iter_object_t*, const iter_object_t*);
};
typedef struct vtbl_array_iterator vtbl_array_t;
#endif
extern vtbl_iterator_t vtbl_array;

#endif