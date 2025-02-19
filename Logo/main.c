#include <stdio.h>
#include <stdlib.h>

typedef struct position_t {
    int x;
    int y;
} Position;

void initialiser_grille();
void afficher_grille(Position joueur, Position cible);
void afficher_position(Position pos);

#define LARGEUR 20
#define HAUTEUR 20

int grille[HAUTEUR][LARGEUR];

void afficher_position(Position pos)
{
    printf("x=%d y=%d\n", pos.x, pos.y);
}

void initialiser_grille()
{
    for (int y = 0; y < HAUTEUR; y++)
    {
        for (int x = 0; x < LARGEUR; x++)
        {
            grille[y][x] = ' ';
        }
    }
}

void afficher_grille(Position joueur, Position cible)
{
    for (int y = 0; y < HAUTEUR; y++)
    {
        for (int x = 0; x < LARGEUR; x++)
        {
            if (x == joueur.x && y == joueur.y)
                printf("J ");
            else if (x == cible.x && y == cible.y)
                printf("C ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main()
{
    Position joueur = {0, 0};
    Position cible = {5, 5};

    initialiser_grille();
    
    printf("Hello logo\n");

    printf("Joueur: ");
    afficher_position(joueur);
    printf("Cible: ");
    afficher_position(cible);
    
    afficher_grille(joueur, cible);
    
    return EXIT_SUCCESS;
}
