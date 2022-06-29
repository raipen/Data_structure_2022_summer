all: pb3

pb3: selectionSort.o pb3.o
	gcc -o pb3.out selectionSort.o pb3.o

selectionSort.o: selectionSort.h selectionSort.c
	gcc -c -o selectionSort.o selectionSort.c

pb3.o: pb3.c selectionSort.h
	gcc -c -o pb3.o pb3.c