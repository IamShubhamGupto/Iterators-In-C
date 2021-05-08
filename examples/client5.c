#include <stdio.h>
#include <stdlib.h>
#include "../src/iterators/iterator.h"
#include "../src/data_structures/tree.c"
// #include "iterator_array.h"
// #include "iterator_list.h"
#define DEBUG_MAIN 0
// #include "array_iterator.c"
int main()
{

    {
        printf("-----TREES-----\n");
        tree_t *tree = init_tree();
        insert(tree, 5);
        insert(tree, 2);
        insert(tree, 3);
        insert(tree, 4);
        insert(tree, 7);
        insert(tree, 9);
        insert(tree, 8);
        if (DEBUG_MAIN)
        {
            printf("finished inserting\n");
        }
        printf("printing tree\n");
        print_tree(tree);
        printf("\n");
        iterator_functions_t *iter_fn = init_iterator("tree");

        iterator_t *it1 = (iter_fn->ptr_)->begin(tree);
        printf("[begin] first element = %d\n", ((tree_node_t *)it1->pointer_)->value_);

        iterator_t *it2 = (iter_fn->ptr_)->end(tree);

        printf("[distance] between [begin] and [end] %d\n", (iter_fn->ptr_)->distance(it1, it2));

    }

    return 0;
}