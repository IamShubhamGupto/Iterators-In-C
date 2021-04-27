OUTPUT_PATH = bin
ITERATOR_PATH = src/iterators
DS_PATH = src/data_structures
FLAGS = -c -g -std=c11
CC = gcc

a.out : client.o iterator.o doubly_linked_list.o iterator_array.o iterator_list.o tree.o iterator_tree.o
	@mkdir -p ${OUTPUT_PATH}
	$(CC) -g -std=c11 ${OUTPUT_PATH}/client.o ${OUTPUT_PATH}/iterator.o ${OUTPUT_PATH}/doubly_linked_list.o ${OUTPUT_PATH}/iterator_array.o ${OUTPUT_PATH}/iterator_list.o ${OUTPUT_PATH}/tree.o ${OUTPUT_PATH}/iterator_tree.o -o ${OUTPUT_PATH}/a.out

client.o : $(clientfile) 
	@mkdir -p ${OUTPUT_PATH}
	$(CC) $(FLAGS) $(clientfile) -o ${OUTPUT_PATH}/client.o

iterator.o : ${ITERATOR_PATH}/iterator.c 
	$(CC) $(FLAGS) ${ITERATOR_PATH}/iterator.c -o ${OUTPUT_PATH}/iterator.o

iterator_array.o : ${ITERATOR_PATH}/iterator_array.c 
	$(CC) $(FLAGS) ${ITERATOR_PATH}/iterator_array.c -o ${OUTPUT_PATH}/iterator_array.o

doubly_linked_list.o : ${DS_PATH}/doubly_linked_list.c 
	$(CC) $(FLAGS) ${DS_PATH}/doubly_linked_list.c -o ${OUTPUT_PATH}/doubly_linked_list.o

iterator_list.o : ${ITERATOR_PATH}/iterator_list.c 
	$(CC) $(FLAGS) ${ITERATOR_PATH}/iterator_list.c -o ${OUTPUT_PATH}/iterator_list.o

tree.o : ${DS_PATH}/tree.c 
	$(CC) $(FLAGS) ${DS_PATH}/tree.c -o ${OUTPUT_PATH}/tree.o

iterator_tree.o : ${ITERATOR_PATH}/iterator_tree.c 
	$(CC) $(FLAGS) ${ITERATOR_PATH}/iterator_tree.c -o ${OUTPUT_PATH}/iterator_tree.o

clean:
	rm -r -f $(OUTPUT_PATH)/

