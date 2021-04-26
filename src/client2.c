#include <stdio.h>
#include <stdlib.h>
#include "iterator.h"
// #include "iterator_array.h"
// #include "iterator_list.h"
#define DEBUG 0
// #include "array_iterator.c"
int main(){

    {
        printf("\n-----ARRAYS-----\n");
        int n = 10;
        int array [n];
        for(int i = 0; i < n; ++i){
            array[i] = i+1;
        }

        iterator_functions_t* iter_fn = init_iterator("array");

        printf("[Looping using iterators]\n");
        iterator_t* first = (iter_fn->ptr_)->begin(array);
        iterator_t* last = (iter_fn->ptr_)->end(array,n);
        while(first->pointer_ != last->pointer_){
            printf("%d\t",*((int*)first->pointer_));
            first = iter_fn->ptr_->next(first,1);
        }
        printf("\n");
        
        iterator_t* it1 = (iter_fn->ptr_)->begin(array);
        printf("[begin] first element = %d\n", *(int*)it1->pointer_);

        iterator_t* it2 = (iter_fn->ptr_)->end(array, n);

        printf("[distance] [end] %d\n", (iter_fn->ptr_)->distance(it1,it2));

        iterator_t* it3 = (iter_fn->ptr_)->prev(it2,1);
        printf("[prev] last element = %d\n", *(int*)it3->pointer_);

        //same output
        //iter_fn->ptr_->advance(it1,1);
        iterator_t* it4 =(iter_fn->ptr_)->next(it1,1);
        printf("[next] Second element of the array = %d\n",*(int*)it4->pointer_);

    }

    return 0;
}