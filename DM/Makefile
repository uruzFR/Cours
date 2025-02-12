CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = commun.o

all: partie1 partie2 partie3 partie4 partie5 partie6

commun.o: commun.c commun.h
	$(CC) $(CFLAGS) -c commun.c -o commun.o

partie1: partie1.c $(OBJ)
	$(CC) $(CFLAGS) partie1.c $(OBJ) -o partie1

partie2: partie2.c $(OBJ)
	$(CC) $(CFLAGS) partie2.c $(OBJ) -o partie2

partie3: partie3.c $(OBJ)
	$(CC) $(CFLAGS) partie3.c $(OBJ) -o partie3

partie4: partie4.c $(OBJ)
	$(CC) $(CFLAGS) partie4.c $(OBJ) -o partie4

partie5: partie5.c $(OBJ)
	$(CC) $(CFLAGS) partie5.c $(OBJ) -o partie5

partie6: partie6.c $(OBJ)
	$(CC) $(CFLAGS) partie6.c $(OBJ) -o partie6

clean:
	rm -f *.o partie1 partie2 partie3 partie4 partie5 partie6

re: clean all
