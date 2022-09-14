CC=gcc
CFLAGS= -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11

all: clean lab3_original lab3_modificado

lab3_original:
	$(CC) $(CFLAGS) -pg ./src/lab3_original.c -o ./bin/lab3_original.out
	
lab3_modificado:
	$(CC) $(CFLAGS) -pg ./src/lab3_modificado.c -o ./bin/lab3_modificado.out

clean:
	rm -f ./bin/*
	rm -f ./*.txt
	rm -f ./*.out