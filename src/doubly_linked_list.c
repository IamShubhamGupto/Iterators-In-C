#include "iterator.h"
#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked_list.h"
#define DEBUG 1
node_t* init_node(int value_){
    node_t* temp = malloc(sizeof(node_t));
    temp->value_ = value_;
    temp->next_ = NULL;
    temp->prev_ = NULL;
    return temp;
}
#if 0
void push_front(list_t* list, int value_){
    node_t* temp = init_node(value_);
    temp->next_ = list->head_;
    if(list->head_ != NULL){
        list->head_->prev_ = temp;
    }else{
        list->tail_ = temp;
    }
    list->head_ = temp;
}
void push_back(list_t* list, int value_){
    node_t* temp = init_node(value_);
    //no element
    if(list->head_ == NULL){
        list->head_ = temp;
        list->tail_ = temp;
    }
    temp->prev_ = list->tail_;
    list->tail_->next_ = temp;
    list->tail_ = temp; 
}
void insert(list_t* list, int value_, int position){

}
void pop_back(list_t* list){
    node_t* head = list->head_;
    node_t* tail = list->tail_;
    //no element
    if(head == NULL){
        return;
    }
    //1 element
    if(head == tail){
        list->head_ = NULL;
        list->tail_ = NULL;
        free(head);
        head = NULL;
    }

    list->tail_ = tail->prev_;
    tail->prev_->next_ = NULL;
    tail->prev_ = NULL;
    free(tail);
    tail = NULL;

    // list->head_ = list->head_->next;
    // free(head);
    // head = NULL;
}
void pop_front(list_t* list){
    node_t* head = list->head_;
    //no element
    if(head == NULL){
        return;
    }
    list->head_ = list->head_->next_;
    free(head);
    head = NULL;
}
void erase(list_t* list, int position){
    node_t* current = list->head_;
    node_t* previous = NULL;
    int i = 0;
    while(i != position){
        ++i;
        previous = current;
        current = current->next_;
    }
    previous->next_ = current->next_;
    current->next_->prev_ = previous;
    current->next_ = NULL;
    current->prev_ = NULL;
    free(current);
    current = NULL;
}

void display_list(list_t* list){
    node_t* current = list->head_;
    while(current != NULL){
        printf("%d\t",current->value_);
        current = current->next_;
    }
    printf("\n");
}
#endif

#if 1
static vtbl_list_t vtbl_list;
void push_front(int value_){
    node_t* temp = init_node(value_);
    temp->next_ = vtbl_list.self->head_;
    if(vtbl_list.self->head_ != NULL){
        vtbl_list.self->head_->prev_ = temp;
    }else{
        vtbl_list.self->tail_ = temp;
    }
    vtbl_list.self->head_ = temp;
}
void push_back(int value_){
    node_t* temp = init_node(value_);
    //no element
    if(vtbl_list.self->head_ == NULL){
        vtbl_list.self->head_ = temp;
        vtbl_list.self->tail_ = temp;
    }
    temp->prev_ = vtbl_list.self->tail_;
    vtbl_list.self->tail_->next_ = temp;
    vtbl_list.self->tail_ = temp; 
}
void insert(int value_, int position){

}
void pop_back(){
    node_t* head = vtbl_list.self->head_;
    node_t* tail = vtbl_list.self->tail_;
    //no element
    if(head == NULL){
        return;
    }
    //1 element
    if(head == tail){
        vtbl_list.self->head_ = NULL;
        vtbl_list.self->tail_ = NULL;
        free(head);
        head = NULL;
    }

    vtbl_list.self->tail_ = tail->prev_;
    tail->prev_->next_ = NULL;
    tail->prev_ = NULL;
    free(tail);
    tail = NULL;

    // list->head_ = list->head_->next;
    // free(head);
    // head = NULL;
}
void pop_front(){
    node_t* head = vtbl_list.self->head_;
    //no element
    if(head == NULL){
        return;
    }
    vtbl_list.self->head_ = vtbl_list.self->head_->next_;
    free(head);
    head = NULL;
}
void erase(int position){
    node_t* current = vtbl_list.self->head_;
    node_t* previous = NULL;
    int i = 0;
    while(i != position){
        ++i;
        previous = current;
        current = current->next_;
    }
    previous->next_ = current->next_;
    current->next_->prev_ = previous;
    current->next_ = NULL;
    current->prev_ = NULL;
    free(current);
    current = NULL;
}

void display_list(){
    node_t* current = vtbl_list.self->head_;
    while(current != NULL){
        printf("%d\t",current->value_);
        current = current->next_;
    }
    printf("\n");
}
#endif
static vtbl_list_t vtbl_list = {
    NULL,
    push_front,
    push_back,
    insert,
    pop_back,
    pop_front,
    erase,
    display_list
};
list_t* init_list(){
    list_t* temp = malloc(sizeof(list_t));
    temp->head_ = NULL;
    temp->tail_ = NULL;
    temp->ptr_ = &vtbl_list;
    temp->ptr_->self = temp;
    return temp;
}