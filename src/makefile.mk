a.out : client.o iterator.o doubly_linked_list.o array_iterator.o
	gcc client.o iterator.o doubly_linked_list.o array_iterator.o
client.o : client.c iterator.h
	gcc -c client.c
iterator.o : iterator.c iterator.h
	gcc -c iterator.c
array_iterator.o : array_iterator.c array_iterator.h
	gcc -c array_iterator.c 
doubly_linked_list.o : doubly_linked_list.c doubly_linked_list.h
	gcc -c doubly_linked_list.c