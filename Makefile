# Declaratiile de variabile
CC = gcc
CFLAGS = -g -Wall -lm -std=c99
 
# Regula de compilare
all: problema1 problema2

problema1: boxes.c
	$(CC) -o problema1 boxes.c $(CFLAGS)

problema2: codifications.c
	$(CC) -o problema2 codifications.c -ggdb3 $(CFLAGS)


.PHONY : clean
clean :
	rm -f problema1 problema2
	rm -f *.out
	rm my_diff
