#include "iterator.h"
#include <stdlib.h>
#include <stdio.h>

//abstract class
iterator_t* init_iterator(vtbl_iterator_t* vtbl_iter){
    iterator_t* temp = malloc(sizeof(iterator_t));
    // temp->pointer_ = NULL;
    temp->ptr_ = vtbl_iter;
    return temp;
}
