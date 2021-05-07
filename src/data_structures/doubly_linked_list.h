#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct node
{
    int value_;
    struct node *next_;
    struct node *prev_;
};
typedef struct node node_t;

struct doubly_linked_list
{
    node_t *head_;
    node_t *tail_;
};
typedef struct doubly_linked_list list_t;

static node_t *init_node(int);
static list_t *init_list();
static void push_front(list_t *, int);
static void push_back(list_t *, int);
static void insert(list_t *, int, int);
static void pop_back(list_t *);
static void pop_front(list_t *);
static void erase(list_t *, int);
static void display_list(list_t *);

#endif