a.out : client.o iterator.o doubly_linked_list.o iterator_array.o
	gcc -g client.o iterator.o doubly_linked_list.o iterator_array.o
client.o : client.c iterator.h
	gcc -c -g client.c
iterator.o : iterator.c iterator.h
	gcc -c -g iterator.c
iterator_array.o : iterator_array.c iterator_array.h
	gcc -c -g iterator_array.c 
doubly_linked_list.o : doubly_linked_list.c doubly_linked_list.h
	gcc -c -g doubly_linked_list.c
iterator_list.o : iterator_list.c iterator_list.h
	gcc -c -g iterator_list.c
