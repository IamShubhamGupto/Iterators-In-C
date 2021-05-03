#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct tree_node{
    int value_;
    struct tree_node* left_;
    struct tree_node* right_;
    struct tree_node* parent_;
};
typedef struct tree_node tree_node_t;

struct tree{
    tree_node_t* root_;
};
typedef struct tree tree_t;

static tree_node_t* init_node(const int);
static tree_t* init_tree();
static void insert(tree_t*, const int);
//struct tree_node_t* erase(tree_t* tree ,struct tree_node_t*, const int);
static tree_node_t* find(const tree_t*, const int);
static void clear(tree_t*);
static void print_tree(const tree_t*);
static void print_in_order(tree_node_t*, char*, int);
static int is_empty(const tree_t*);

static tree_node_t* get_leftmost_leaf(tree_node_t*);
static tree_node_t* get_rightmost_leaf(tree_node_t*);
static tree_node_t* in_order_successor(tree_node_t*);
static tree_node_t* in_order_predecessor(tree_node_t*);


#endif