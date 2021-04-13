#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "iterator.h"
#include "iterator_list.h"
#include "iterator_array.h"


//abstract class
iterator_t* init_iterator(const char* vtbl_iter){
    iterator_t* temp = malloc(sizeof(iterator_t));
    // temp->pointer_ = NULL;
    if(strcmp(vtbl_iter,"list")==0){
       temp->ptr_ = &vtbl_list; 
    }else if(strcmp(vtbl_iter,"array")==0){
        temp->ptr_ = &vtbl_array;
    }else{
        printf("Invalid data structure\n");
        printf("Exiting...\n");
        exit(0);
    }
    return temp;
}
