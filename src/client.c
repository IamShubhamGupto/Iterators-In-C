#include<stdio.h>
#include "doubly_linked_list.h"

int main(){
    list_t* list = init_list();
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

    list->ptr_->push_back(10);
    list->ptr_->push_back(20);
    list->ptr_->push_back(30);
    list->ptr_->push_front(40);
    list->ptr_->display();
    list->ptr_->pop_front();
    list->ptr_->display();
    list->ptr_->pop_back();
    list->ptr_->display();
    return 0;
}