#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include "array_iterator.h"

int main(){
    list_t* list = init_list();
    push_back(list,10);
    push_back(list,20);
    push_back(list,30);
    push_front(list,40);
    display_list(list);
    pop_front(list);
    display_list(list);
    pop_back(list);
    display_list(list);   

    {
        int n = 10;
        int array [n];
        for(int i = 0; i < n; ++i){
            array[i] = i+1;
        }
        iterator_t* it1 = begin(array);
        printf("first element = %d\n", *it1->pointer_);

        iterator_t* it2 = end(array, n);
        
        printf("%d\n", distance(it1,it2));

        iterator_t* it3 = prev(it2,1);
        printf("last element = %d\n", *it3->pointer_);

        //same output
        //advance(it1,1);
        iterator_t* it4 = next(it1,1);
        printf("Second element of the array = %d\n",*it4->pointer_);

    }
    


    #if 0
    list->ptr_->push_back(list,10);
    list->ptr_->push_back(list,20);
    list->ptr_->push_back(list,30);
    list->ptr_->push_front(list,40);
    list->ptr_->display(list);
    list->ptr_->pop_front(list);
    list->ptr_->display(list);
    list->ptr_->pop_back(list);
    list->ptr_->display(list);
    #endif 
    
    #if 0
    list->ptr_->push_back(10);
    list->ptr_->push_back(20);
    list->ptr_->push_back(30);
    list->ptr_->push_front(40);
    list->ptr_->display();
    list->ptr_->pop_front();
    list->ptr_->display();
    list->ptr_->pop_back();
    list->ptr_->display();
    #endif
    return 0;
}