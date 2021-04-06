#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H
#include "doubly_linked_list.h"
#if 0
struct vtbl_list_iterator{
    iter_object_t* (*begin)(const list_t*);
    iter_object_t* (*end)(const list_t*, int);
    void (*advance)(iter_object_t*, int);
    iter_object_t* (*next)(iter_object_t*, int);
    iter_object_t* (*prev)(iter_object_t*, int);
    int (*distance)(const iter_object_t*, const iter_object_t*);
};
typedef struct vtbl_list_iterator vtbl_list_t;
#endif
extern vtbl_iterator_t vtbl_list;
#endif