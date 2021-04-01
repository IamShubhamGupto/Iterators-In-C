#include<stdio.h>
#include "doubly_linked_list.h"

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