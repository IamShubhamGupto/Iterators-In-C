# Iterators-In-C
The aim of this project is to provide a single interface to iterate over various data-structures in the C language. The following data-structures are currently supported:
- Arrays
- Doubly Linked Lists 
- Binary Search Trees 


Due to the non generic nature of the C language, the data structures are expected to hold integer values. 
## How to Compile & Run
<details>
  <summary> Linux & Mac </summary>
  
  ```shell
  git clone https://github.com/IamShubhamGupto/Iterators-In-C.git
  cd Iterators-In-C
  make -f makefile.mk clientfile=<ENTER PATH TO CLIENT FILE NAME HERE>
  ./bin/a.out
  ```  

  <b>EXAMPLE </b>
  
  ```shell
  make -f makefile.mk clientfile=examples/client1.cpp
  ./bin/a.out
  ```
  #### Clean Up
  In order to clean the generated files, run ```make -f makefile.mk clean```.
</details>  

## Data Structures
<details>
  <summary> <b>List </b></summary>
  
  #### Node Members
  | <b> Name        </b>          | <b> Definition </b>                               |
  | -------------                 | -------------                                     |
  | value_                        | stores an integer value.                  |
  | next_                         | stores pointer to next node.         |
  | prev_                         | stores pointer to previous node.            |
  
  #### List Members
  | <b> Name        </b>          | <b> Definition </b>                               |
  | -------------                 | -------------                                     |
  | head_                         | stores pointer to the first node in the list.     |
  | tail_                         | stores pointer to the last node in the list        |
  
  #### List Functions
  | <b> Name        </b>          | <b> Definition </b>                               |
  | -------------                 | -------------                                     |
  | init_list                     | allocate space to list instance.                   |
  | init_node                     | allocate space and initialize value of list node.         |
  | push_front                    | insert node at beginning of the list .            |
  | push_back                     | insert node at end of list.         |
  | insert                        | insert node at a specificed postion in the list. |
  | pop_back                      | delete node from end of the list.          |
  | pop_front                     | delete node from beginning of the list. |
  | erase                         | delete node from a specified postion in the list. |
  | display_list                  | visually display the list. |
  
  
</details>

<details>
  <summary><b> Tree </b> </summary>
  
  #### Node Members
  | <b> Name        </b>          | <b> Definition </b>                               |
  | -------------                 | -------------                                     |
  | value_                        | stores an integer value.                  |
  | left_                         | stores pointer to the left child node.         |
  | right_                        | stores pointer to the right child node.            |
  | parent_                       | stores pointer to the parent node.            |
  
  #### Tree Members
  | <b> Name        </b>          | <b> Definition </b>                               |
  | -------------                 | -------------                                     |
  | root_                         | stores pointer to the root node of the tree     |
  
  #### Tree Functions
  | <b> Name        </b>          | <b> Definition </b>                               |
  | -------------                 | -------------                                     |
  | init_tree                     | allocate space to tree instance.                   |
  | init_node                     | allocate space and initialize value of tree node.         |
  | insert                        | insert node into the tree. |
  | find                          | search for an element in the list|
  | erase                         | delete specified value from a tree |
  | print_tree                    | visually display the tree. |
  | print_in_order                | helper function utilized by print_tree |
  | is_empty                      | returns 0 or 1 based on if the tree is empty or not |
  | get_leftmost_leaf             | returns the leftmost child node from the specified node |
  | get_rightmost_leaf            | returns the rightmost child node from the specified node |
  | in_order_successor            | returns the in-order-successor from the specified node|
  | in_order_predecessor          | returns the in-order-predeccessor from the specified node|  
  | pre_order_successor           | returns the pre-order-successor from the specified node| 
</details>

## Iterator Functions
  | <b> Name        </b>          | <b> Definition </b>                               |
  | -------------                 | -------------                                     |
  | init_iterator                 | initialize a concrete iterator class for a type of data structure.        |
  | begin                         | return an iterator object pointing to the first element of the data structure.         |
  | end                           | return an iterator object pointing to the last element of the data structure.          |
  | next                          | increment the iterator by certain postions / by 1 in case of a bidirectional iterator          |
  | prev                          | decrement the iterator by certain postions  / by 1 in case of a bidirectional iterator         |
  | advance                       | increment/ decrement the iterator by a specified value                                  |
  | distance                      | return the number of elements/distance between given 2 iterators. pre-order distance in-case of a tree.                                 |

### By
- [Shubham Gupta](https://github.com/IamShubhamGupto)
- [Shubham Kumar](https://github.com/shubham2k)

### License
This work is licened under [GPL v3.0](LICENSE).
