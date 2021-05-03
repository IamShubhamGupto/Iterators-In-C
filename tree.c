#include "../iterators/iterator.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

#define DEBUG 0

static tree_node_t* init_node(const int value_){
    tree_node_t* temp = (tree_node_t*)malloc(sizeof(tree_node_t));
    temp->value_ = value_;
    temp->left_ = NULL;
    temp->right_ = NULL;
    temp->parent_ = NULL;
    return temp;
}

static tree_t* init_tree(){
    tree_t* temp = (tree_t*)malloc(sizeof(tree_t));
    temp->root_ = NULL;
    return temp;
}
#define DEBUG_IN 0
static void insert(tree_t* tree, const int new){
    tree_node_t* current = tree->root_;
    tree_node_t* previous = NULL;
    tree_node_t* new_node = init_node(new);

    while(current != NULL){
        previous = current;
        if(new < current->value_){
            current = current->left_;
        }else{
            current = current->right_;
        }
    }
    new_node->parent_ = previous;
    if(previous == NULL){
        if(DEBUG_IN){
            printf("[insert] root\n");
        }
        new_node->parent_ = NULL;
        tree->root_ = new_node;

    }else if (new < previous->value_){
        if(DEBUG_IN){
            printf("[insert] left\n");
        }
        previous->left_ = new_node;
    }else{
        if(DEBUG_IN){
            printf("[insert] right\n");
        }
        previous->right_ = new_node;
    }
}
static int is_empty(const tree_t* tree){
    return tree->root_ == NULL;
}

/*
struct tree_node_t* erase(tree_t* tree , struct tree_node_t* myroot ,const int value)
{
    tree_node_t *root = myroot;
    if(root==NULL)
        return root;
    if(value<root->value_)
            root->left_ = erase(tree,root->left_,value);
    else if (value>root->value_)
            root->right_ = erase(tree,root->right_,value);
    else
    {
        if(root->left_==NULL)
        {
            struct tree_node_t *temp = root->right_;
            free(root);
            return *temp;
        }
        else if(root->right_==NULL)
        {
            struct tree_node_t *temp = root->left_;
            free(root);
            return *temp;
        }
        tree_node_t* temp = get_leftmost_leaf(root->right_);
        root->value_ = temp->value_;
        root->right_ = erase(tree,root->right_,temp->value_);
    }
*/    
    // tree_node_t* previous = NULL;
    // while(current && current->value_ != value){
    //     previous = current;
    //     if(value < current->value_){
    //         current = current->left_;
    //     }else{
    //         current = current->right_;
    //     }
    // }

    // //delete_node(tree->root_, current, previous);

    // if(current == NULL){
    //     printf("Key not found!!\n");
    //     return;
    // }else if(current->left_ == NULL || current->right_ == NULL){
    //     if(current != tree->root_){
    //         if(previous->left_ == current){
    //             previous->left_ = NULL;
    //         }else{
    //             previous->right_ = NULL;
    //         }
    //     }else{
    //         tree->root_ = NULL;
    //     }
    //     free(current);
    //     current = NULL;
    // }else if(current->left_ && current->right_){
    //     tree_node_t* temp = in_order_successor(current->right_);

    // }
}

static tree_node_t* find(const tree_t* tree, const int value){
    tree_node_t* current = tree->root_;
    while(current && current->value_ != value){
        if(value < current->value_)
        {
            current = current->left_;
        }
        else
        {
            current = current->right_;
        }
    }
    if(current && current->value_ == value)
    {
        return current;
    }
    return NULL;

}

#define DEBUG_PT 0
static void print_tree(const tree_t* tree) 
{
  if(is_empty(tree))
  {
    printf("Empty tree !!\n");
    return;
  }
  tree_node_t* root = tree->root_;
  if(DEBUG_PT)
  {
    printf("[printTree]current root is %d\n", root->value_ );
  }
  print_in_order(root, "", 0);
}

static void print_in_order(tree_node_t* root, char* prefix, int isLeft)
{
    //char left[3] = "   ";
    //char right[3] = "│  ";
    if(root != NULL)
    {
        char prefix2[strlen(prefix)+5];
        strcpy(prefix2, prefix);
        printf("%s",prefix);
        printf(isLeft ? "├──" : "└──");
        printf("%d\n",root->value_);
        // if(isLeft){
        //     strcat(prefix2,left);
        // }else{
        //     strcat(prefix2,right);
        // }
        strcat(prefix2,(isLeft ? "│  " : "   "));
        print_in_order(root->left_, prefix2 , 1);
        print_in_order(root->right_, prefix2, 0);
  }
}

static tree_node_t* get_leftmost_leaf(tree_node_t* root)
{
    while(root && root->left_ != NULL)
    {
        root = root->left_;
    }
    return root;
}

static tree_node_t* get_rightmost_leaf(tree_node_t* root)
{
    while(root && root->right_ != NULL)
    {
        root = root->right_;
    }
    return root;
}

static tree_node_t* in_order_successor(tree_node_t* node){
    tree_node_t* parent = NULL;
    if(node == NULL)
    {
        return node;
    }
    if(node->right_ != NULL)
    {
        node = node->right_;
        node = get_leftmost_leaf(node);
    }else
    {
        parent = node->parent_;
        while (parent != NULL && node == parent->right_)
        {
            node = parent;
            parent = parent->parent_;
        }
        node = parent;
    }
    return node;
}

static tree_node_t* in_order_predecessor(tree_node_t* node){
    tree_node_t* parent = NULL;
    if(node == NULL)
    {
        return node;
    }
    if(node->left_ != NULL)
    {
        node = node->left_;
        node = get_rightmost_leaf(node);
    }else
    {
        parent = node->parent_;
        while (parent != NULL && node == parent->left_)
        {
            node = parent;
            parent = parent->parent_;
        }
        node = parent;
    }
    return node;
}