a.out : client.o iterator.o doubly_linked_list.o
	gcc client.o iterator.o doubly_linked_list.o
client.o : client.c iterator.h
	gcc -c client.c
iterator.o : iterator.c iterator.h
	gcc -c iterator.c
doubly_linked_list.o : doubly_linked_list.c doubly_linked_list.h
	gcc -c doubly_linked_list.c