#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct node{
    int value_;
    struct node* left_;
    struct node* right_;
    struct node* parent_;
};
typedef struct node node_t;

#if 0
struct vtbl_list_t;
#endif 

struct tree{
    node_t* root_;
    #if 0
    struct vtbl_list_t* ptr_;
    #endif
};
typedef struct tree tree_t;

node_t* init_node(int);
tree_t* init_treet();
void insert(tree_t*, int);
void erase(tree_t*, int);
void find(tree_t*, int, int);
void clear(tree_t*);
void display_tree(tree_t*);


#endif