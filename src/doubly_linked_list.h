#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct node{
    int value_;
    struct node* next_;
    struct node* prev_;
};
typedef struct node node_t;

#if 0
struct vtbl_list_t;
#endif 

struct doubly_linked_list{
    node_t* head_;
    node_t* tail_;
    #if 0
    struct vtbl_list_t* ptr_;
    #endif
};
typedef struct doubly_linked_list list_t;
#if 0
struct vtbl_list_t{
    // node_t* list_ptr;
    void (*push_front)(list_t*, int);
    void (*push_back)(list_t*, int);
    void (*insert)(list_t*, int, int);
    void (*pop_back)(list_t*);
    void (*pop_front)(list_t*);
    void (*erase)(list_t*, int);
    void (*display)(list_t*);
};
#endif

#if 0
struct vtbl_list_t{
    list_t* self;
    void (*push_front)( int);
    void (*push_back)( int);
    void (*insert)( int, int);
    void (*pop_back)();
    void (*pop_front)();
    void (*erase)( int);
    void (*display)();
};

typedef struct vtbl_list_t vtbl_list_t;
#endif

static node_t* init_node(int);
static list_t* init_list();
static void push_front(list_t*, int);
static void push_back(list_t*, int);
static void insert(list_t*, int, int);
static void pop_back(list_t*);
static void pop_front(list_t*);
static void erase(list_t*, int);
static void display_list(list_t*);


#endif