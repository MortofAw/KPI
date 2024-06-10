all: main

main: main.o common.o M3.o M2.o M1.o MErr.o
	gcc -o main main.o M1.o M2.o M3.o common.o MErr.o

main.o: main.c
	gcc -c main.c

common.o: common.c common.h
	gcc -c common.c 

M1.o: M1.c M1.h
	gcc -c M1.c 

M2.o: M2.c M2.h
	gcc -c M2.c 

M3.o: M3.c M3.h
	gcc -c M3.c 

MErr.o: MErr.c MErr.h
	gcc -c MErr.c 

clean:
	rm -rf *.o main 

