#include <stdio.h>
#include <stdint.h>

//Partie 2

int octet1, octet2, octet3, octet4; //Varaibles pour le masque de sous-réseau
unsigned int ip; //Variable pour le masque de sous-réseau 32 bits

int main(){
    printf("Saisir un masque de sous-réseau:\n");
    
    //Saisie et verification du format de l'adresse saisie
    if (scanf("%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4) != 4) {
        printf("Erreur saisie incorrecte\n");
        return 1;
    }

    int masque(uint32_t mask) {
    return (mask & (mask + 1)) == 0;  // Vérifie que tous les 1 sont suivis de 0
}

    // Vérifier que chaque nombre est entre 0 et 255
    if (octet1 < 0 || octet1 > 255 || octet2 < 0 || octet2 > 255 || octet3 < 0 || octet3 > 255 || octet4 < 0 || octet4 > 255) {
        printf("Erreur saisie incorrecte: %d.%d.%d.%d\n", octet1, octet2, octet3, octet4);
        return 1;
    }

    // Convertir l'adresse IP en 32 bits
    ip = (octet1 << 24) | (octet2 << 16) | (octet3 << 8) | octet4;

    printf("masque sous-réseau (32 bits):%u\n", ip);

    return 0;
}


