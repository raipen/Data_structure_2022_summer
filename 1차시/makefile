all: pb1

pb1: selectionSort.o pb1.o
	gcc -o pb1.out selectionSort.o pb1.o

selectionSort.o: selectionSort.h selectionSort.c
	gcc -c -o selectionSort.o selectionSort.c

pb1.o: pb1.c selectionSort.h
	gcc -c -o pb1.o pb1.c