CC = gcc
CFLAGS = -Wall -g

all: main

main: main.o common.o menu.o vector_filling.o \
	  vector_sorting.o print_vector.o 3D_filling.o print_3D.o \
	  3D_sorting.o measurement.o 
	$(CC) $(CFLAGS) -o main main.o common.o menu.o vector_filling.o \
		vector_sorting.o print_vector.o 3D_filling.o print_3D.o \
		3D_sorting.o  measurement.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

common.o: common.c common.h
	$(CC) $(CFLAGS) -c common.c 

menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -c menu.c 

vector_filling.o: vector_filling.c vector_filling.h
	$(CC) $(CFLAGS) -c vector_filling.c 

vector_sorting.o: vector_sorting.c vector_sorting.h
	$(CC) $(CFLAGS) -c vector_sorting.c

print_vector.o: print_vector.c print_vector.h
	$(CC) $(CFLAGS) -c print_vector.c

3D_filling.o: 3D_filling.c 3D_filling.h
	$(CC) $(CFLAGS) -c 3D_filling.c

3D_sorting.o: 3D_sorting.c 3D_sorting.h
	$(CC) $(CFLAGS) -c 3D_sorting.c

print_3D.o: print_3D.c print_3D.h
	$(CC) $(CFLAGS) -c print_3D.c

measurement.o: measurement.c measurement.h
	$(CC) $(CFLAGS) -c measurement.c

clean:
	rm -rf *.o main 
