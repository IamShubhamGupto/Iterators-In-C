#include <stdio.h>
#include <stdlib.h>
#include "../src/iterators/iterator.h"
#include "../src/data_structures/doubly_linked_list.c"
// #include "iterator_array.h"
// #include "iterator_list.h"
#define DEBUG 0
// #include "array_iterator.c"
int main(){
    {
        printf("\n-----LISTS-----\n");
        list_t* list = init_list();
        push_back(list,10);
        push_back(list,20);
        push_back(list,30);
        push_back(list,70);
        push_back(list,60);
        push_back(list,40);
        display_list(list);
        pop_back(list);
        pop_back(list);
        push_front(list,1);
        push_front(list,2);
        display_list(list);
        if(DEBUG){
            printf("%d\n", list->tail_->prev_->value_);
        }
        
        // pop_front(list);
        // display_list(list);
        // pop_back(list);
        // display_list(list);  

        iterator_functions_t* iter_fn = init_iterator("list");

        iterator_t* it1 = (iter_fn->ptr_)->begin(list);
        printf("[begin] first element = %d\n", ((node_t*)it1->pointer_)->value_);

        iterator_t* it2 = (iter_fn->ptr_)->end(list);

        printf("[distance] [end] %d\n", (iter_fn->ptr_)->distance(it1,it2));

        iterator_t* it3 = (iter_fn->ptr_)->prev(it2,1);
        printf("[prev] last element = %d\n", ((node_t*)it3->pointer_)->value_);

        //same output
        iterator_t* it6 = (iter_fn->ptr_)->begin(list);
        iter_fn->ptr_->advance(it6,3); 
        printf("[advance] The 3rd step from beginning of array = %d\n",((node_t*)it6->pointer_)->value_);

        iterator_t* it4 = (iter_fn->ptr_)->next(it1,1);
        printf("[next] Second element of the array = %d\n",((node_t*)it4->pointer_)->value_);

        printf("[Looping forward using iterators using step 2]\n");
        iterator_t* first = (iter_fn->ptr_)->begin(list);
        iterator_t* last = (iter_fn->ptr_)->end(list);
        while(first->pointer_ != NULL && first->pointer_ != last->pointer_){
            printf("%d\t",((node_t*)first->pointer_)->value_);
            first = iter_fn->ptr_->next(first,2);
        }
        printf("\n");

        printf("[Looping forward using next iterator using step 2]\n");
        
        iterator_t* it5 = (iter_fn->ptr_)->begin(list);
        printf("First element of the array = %d\n",((node_t*)it5->pointer_)->value_);
        while(it5!= last->pointer_)
        {
            it5 = (iter_fn->ptr_)->next(it5,2);
            printf("[NEXT] element of the array = %d\n",((node_t*)it5->pointer_)->value_);
        }


    }
     
    return 0;
}