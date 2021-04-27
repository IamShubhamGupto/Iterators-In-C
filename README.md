# Iterators-In-C
The aim of this project is to provide a single interface to iterate over various data-structures in the C language. The following data-structures are currently supported:
- Arrays
- Doubly Linked Lists 
- Binary Search Trees

Due to the non generic nature of the C language, the data structures are expected to hold integer values. 
## How to compile  
<b> Linux & Mac </b>  
```shell
git clone https://github.com/IamShubhamGupto/Iterators-In-C.git
make -f makefile.mk clientfile=<ENTER PATH TO CLIENT FILE NAME HERE>
./bin/a.out
```  

<b>EXAMPLE </b>
```shell
make -f makefile.mk clientfile=clientfiles/client1.c
./bin/a.out
```
### Clean Up
In order to clean the generated files, run ```make -f makefile.mk clean```.
