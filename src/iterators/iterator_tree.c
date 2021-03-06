#ifndef LIST_ITERATOR_C
#define LIST_ITERATOR_C
#include "iterator.h"
#include "iterator_tree.h"
#include "../data_structures/tree.c"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define DEBUG 0
//bidirectional access iterators
static iterator_t *begin(const void *tree)
{
    iterator_t *it = malloc(sizeof(iterator_t));
    it->pointer_ = get_leftmost_leaf(((tree_t *)tree)->root_);
    return it;
}

static iterator_t *end(const void *tree, ...)
{
    //does not work with pointers
    //int n = sizeof(array)/sizeof(array[0]);
    iterator_t *it = malloc(sizeof(iterator_t));
    tree_node_t *temp = init_node(INT_MIN);
    temp->parent_ = get_rightmost_leaf(((tree_t *)tree)->root_);
    it->pointer_ = temp;
    return it;
}

static void advance(iterator_t *it, int n)
{
    int i = 0;
    if (n > 0)
    {
        while (i < n)
        {
            ++i;
            it->pointer_ = in_order_successor((tree_node_t *)it->pointer_);
        }
    }
    else
    {
        while (n < i)
        {
            --i;
            it->pointer_ = in_order_successor((tree_node_t *)it->pointer_);
        }
    }
}

static iterator_t *next(iterator_t *it, int n)
{
    iterator_t *temp = malloc(sizeof(iterator_t));
    temp->pointer_ = it->pointer_;
    advance(temp, n);
    return temp;
}

static iterator_t *prev(iterator_t *it, int n)
{
    iterator_t *temp = malloc(sizeof(iterator_t));
    temp->pointer_ = it->pointer_;
    advance(temp, -n);
    return temp;
}
#if 1
#define DEBUG_D_T 0
static int distance(const iterator_t *it1, const iterator_t *it2)
{
    tree_node_t *first = (tree_node_t *)it1->pointer_;
    tree_node_t *last = (tree_node_t *)it2->pointer_;
    if (DEBUG_D_T)
    {
        printf("first val = %d\n", first->value_);
        printf("last val = %d\n", last->value_);
    }

    int i = 0;
    while (first && first != last)
    {
        if (DEBUG_D_T)
        {
            printf("first val = %d\n", first->value_);
            printf("updating i\n");
        }
        ++i;
        first = pre_order_successor(first);
    }

    return i - 1;
}
#endif
#if 0
#define DEBUG_D_T 0
static int distance(const iterator_t *it1, const iterator_t *it2)
{
    tree_node_t *first = (tree_node_t *)it1->pointer_;
    tree_node_t *last = (tree_node_t *)it2->pointer_;
    int key1 = first->value_;
    int key2 = last->value_;
    if (key1 > key2)
    {
        return get_distance(first, last);
    }
    return get_distance(last, first);
}
#endif

vtbl_iterator_t vtbl_tree = {
    begin,
    end,
    advance,
    next,
    prev,
    distance};

#endif