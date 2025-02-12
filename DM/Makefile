CC = gcc  # Compilateur utilisé
CFLAGS = -Wall -Wextra -Werror  # Options de compilation pour activer les avertissements stricts
OBJ = commun.o  # Objet commun utilisé par toutes les parties

# Cible principale pour générer tous les exécutables
all: partie1 partie2 partie3 partie4 partie5 partie6

# Compilation du fichier source commun en objet
commun.o: commun.c commun.h
	$(CC) $(CFLAGS) -c commun.c -o commun.o

# Compilation de chaque partie en incluant le fichier objet commun
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

# Suppression des fichiers objets et exécutables
clean:
	rm -f *.o partie1 partie2 partie3 partie4 partie5 partie6

# Nettoyage et recompilation complète
re: clean all
