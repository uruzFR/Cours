#include "commun.h" // Inclusion des déclarations nécessaires

int main() {
    char masque_str[16]; // Buffer pour stocker l'entrée utilisateur
    struct in_addr masque; // Structure pour stocker le masque de sous-réseau

    printf("Saisir un masque de sous-réseau : ");
    scanf("%15s", masque_str); // Lecture du masque

    // Validation du masque de sous-réseau
    if (!valider_masque(masque_str, &masque)) {
        printf("Erreur : masque de sous-réseau invalide.\n");
        return 1;
    }

    // Affichage du préfixe CIDR correspondant
    printf("CIDR : /%d\n", calculer_cidr(masque));
    
    return 0;
}
