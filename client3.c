#include <stdio.h>
#include <stdlib.h>
#include "../src/iterators/iterator.h"
#include "../src/data_structures/tree.c"
// #include "iterator_array.h"
// #include "iterator_list.h"
#define DEBUG_MAIN 0
// #include "array_iterator.c"
int main(){

    {
        printf("-----TREES-----\n");
        tree_t* tree = init_tree();
        insert(tree,10);
        insert(tree,30);
        insert(tree,20);
        insert(tree,40);
        if(DEBUG_MAIN){
            printf("finished inserting\n");
        }
        printf("printing tree\n");
        print_tree(tree);
        printf("\n");
        iterator_functions_t* iter_fn = init_iterator("tree");

        iterator_t* it1 = (iter_fn->ptr_)->begin(tree);
        printf("[begin] first element = %d\n", ((tree_node_t*)it1->pointer_)->value_);

        iterator_t* it2 = (iter_fn->ptr_)->end(tree);

        printf("[distance] [end] %d\n", (iter_fn->ptr_)->distance(it1,it2));

        iterator_t* it3 = (iter_fn->ptr_)->prev(it2,1);
        printf("[prev] last element = %d\n", ((tree_node_t*)it3->pointer_)->value_);

        //same output
        //iter_fn->ptr_->advance(it1,1);
        iterator_t* it4 = (iter_fn->ptr_)->next(it1,1);
        printf("[next] Second element of the tree = %d\n",((tree_node_t*)it4->pointer_)->value_);

        printf("[Looping using iterators]\n");
        iterator_t* first = (iter_fn->ptr_)->begin(tree);
        iterator_t* last = (iter_fn->ptr_)->end(tree);
        while(first->pointer_ != NULL && first->pointer_ != last->pointer_){
            printf("%d\t",((tree_node_t*)first->pointer_)->value_);
            first = iter_fn->ptr_->next(first,1);
        }
        printf("\n");

        printf("[distance] [next] %d\n", (iter_fn->ptr_)->distance(first,it4));
    }

    return 0;
}