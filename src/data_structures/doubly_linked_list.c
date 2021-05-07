#include "../iterators/iterator.h"
#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked_list.h"
#define DEBUG 0
static node_t *init_node(int value_)
{
    node_t *temp = malloc(sizeof(node_t));
    temp->value_ = value_;
    temp->next_ = NULL;
    temp->prev_ = NULL;
    return temp;
}
#if 1
static void push_front(list_t *list, int value_)
{
    node_t *temp = init_node(value_);
    temp->next_ = list->head_;
    if (list->head_ != NULL)
    {
        list->head_->prev_ = temp;
    }
    else
    {
        list->tail_ = temp;
    }
    list->head_ = temp;
}
static void push_back(list_t *list, int value_)
{
    node_t *temp = init_node(value_);
    //no element
    if (list->head_ == NULL)
    {
        list->head_ = temp;
        list->tail_ = temp;
    }
    temp->prev_ = list->tail_;
    list->tail_->next_ = temp;
    list->tail_ = temp;
}
static void insert(list_t *list, int value_, int position)
{
    node_t *temp = list->head_;
    node_t *newNode = init_node(value_);
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next_;
        //printf("%d\n",temp->value_);
    }
    newNode->next_ = temp->next_;
    (temp->next_)->prev_ = newNode;
    newNode->prev_ = temp;
}
static void pop_back(list_t *list)
{
    node_t *head = list->head_;
    node_t *tail = list->tail_;
    //no element
    if (head == NULL)
    {
        return;
    }
    //1 element
    if (head == tail)
    {
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
static void pop_front(list_t *list)
{
    node_t *head = list->head_;
    //no element
    if (head == NULL)
    {
        return;
    }
    list->head_ = list->head_->next_;
    free(head);
    head = NULL;
}
static void erase(list_t *list, int position)
{
    node_t *current = list->head_;
    node_t *previous = NULL;
    int i = 0;
    while (i != position)
    {
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

static void display_list(list_t *list)
{
    node_t *current = list->head_;
    while (current != NULL)
    {
        printf("value = %d\t", current->value_);
        if (DEBUG)
        {
            if (current->next_ != NULL)
                printf("next value = %d\t", current->next_->value_);
            if (current->prev_ != NULL)
                printf("prev value = %d\n", current->prev_->value_);
            else
                printf("\n");
        }

        current = current->next_;
    }
    printf("\n");
}
#endif

static list_t *init_list()
{
    list_t *temp = malloc(sizeof(list_t));
    temp->head_ = NULL;
    temp->tail_ = NULL;
#if 0
    temp->ptr_ = &vtbl_list;
    temp->ptr_->self = temp;
#endif
    return temp;
}