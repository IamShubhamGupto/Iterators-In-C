#include <stdio.h>
#include <stdlib.h>
#include "iterator.h"
#include "doubly_linked_list.h"
#include "iterator_array.h"
#include "iterator_list.h"
#define DEBUG 0
// #include "array_iterator.c"
int main(){
    {
        printf("\n-----LISTS-----\n");
        list_t* list = init_list();
        push_back(list,10);
        push_back(list,20);
        push_back(list,30);
        push_front(list,40);
        display_list(list);
        if(DEBUG){
            printf("%d\n", list->tail_->prev_->value_);
        }
        
        // pop_front(list);
        // display_list(list);
        // pop_back(list);
        // display_list(list);  

        iterator_t* iter_fn = init_iterator(&vtbl_list);

        iter_object_t* it1 = ((vtbl_list_t*)iter_fn->ptr_)->begin(list);
        printf("[begin] first element = %d\n", ((node_t*)it1->pointer_)->value_);

        iter_object_t* it2 = ((vtbl_list_t*)iter_fn->ptr_)->end(list, 0);

        printf("[distance] [end] %d\n", ((vtbl_list_t*)iter_fn->ptr_)->distance(it1,it2));

        iter_object_t* it3 = ((vtbl_list_t*)iter_fn->ptr_)->prev(it2,1);
        printf("[prev] last element = %d\n", ((node_t*)it3->pointer_)->value_);

        //same output
        //iter_fn->ptr_->advance(it1,1);
        iter_object_t* it4 = ((vtbl_list_t*)iter_fn->ptr_)->next(it1,1);
        printf("[next] Second element of the array = %d\n",((node_t*)it4->pointer_)->value_);
    }
     

    {
        printf("\n-----ARRAYS-----\n");
        int n = 10;
        int array [n];
        for(int i = 0; i < n; ++i){
            array[i] = i+1;
        }

        iterator_t* iter_fn = init_iterator(&vtbl_array);
        
        iter_object_t* it1 = ((vtbl_array_t*)iter_fn->ptr_)->begin(array);
        printf("[begin] first element = %d\n", *(int*)it1->pointer_);

        iter_object_t* it2 = ((vtbl_array_t*)iter_fn->ptr_)->end(array, n);

        printf("[distance] [end] %d\n", ((vtbl_array_t*)iter_fn->ptr_)->distance(it1,it2));

        iter_object_t* it3 = ((vtbl_array_t*)iter_fn->ptr_)->prev(it2,1);
        printf("[prev] last element = %d\n", *(int*)it3->pointer_);

        //same output
        //iter_fn->ptr_->advance(it1,1);
        iter_object_t* it4 =((vtbl_array_t*)iter_fn->ptr_)->next(it1,1);
        printf("[next] Second element of the array = %d\n",*(int*)it4->pointer_);

    }
    return 0;
}