a.out : client.o iterator.o doubly_linked_list.o iterator_array.o iterator_list.o tree.o iterator_tree.o
	gcc -g -std=c11 client.o iterator.o doubly_linked_list.o iterator_array.o iterator_list.o tree.o iterator_tree.o
client.o : $(clientfile) iterator.h iterator_array.h doubly_linked_list.h tree.h
	gcc -c -g -std=c11 $(clientfile) -o client.o
iterator.o : iterator.c iterator.h
	gcc -c -g -std=c11 iterator.c
iterator_array.o : iterator_array.c iterator_array.h
	gcc -c -g -std=c11 iterator_array.c 
doubly_linked_list.o : doubly_linked_list.c doubly_linked_list.h
	gcc -c -g -std=c11 doubly_linked_list.c
iterator_list.o : iterator_list.c iterator_list.h
	gcc -c -g -std=c11 iterator_list.c
tree.o : tree.c tree.h
	gcc -c -g -std=c11 tree.c
iterator_tree.o : iterator_tree.c iterator_tree.h
	gcc -c -g -std=c11 iterator_tree.c

