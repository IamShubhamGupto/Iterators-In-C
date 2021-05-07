# Iterators-In-C
The aim of this project is to provide a single interface to iterate over various data-structures in the C language. The following data-structures are currently supported:
- Arrays
- Doubly Linked Lists 
- Binary Search Trees

Due to the non generic nature of the C language, the data structures are expected to hold integer values. 
## How to Compile & Run
<details>
  <summary><b> Linux & Mac </b> </summary>
  
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
    <summary> <b>List</b> </summary>
    
    #### Member Functions
    | <b> Name </b>           | <b> Definition </b>                               |
    | -------------           | -------------                                     |
    | key_type                | template type of the key in the pair              |
    | mapped_type             | template type of the value in the pair            |
    | root_                   | stores root node of the splay tree.               |
    | iterator                | a bidirectional iterator to mapped_type.          |
    | const_iterator          | a bidirectional iterator to constant mapped_type. |
    | reverse_iterator        | a bidirectional iterator to mapped_type.          |
    | const_reverse_iterator  | a bidirectional iterator to constant mapped_type. |
</details>

