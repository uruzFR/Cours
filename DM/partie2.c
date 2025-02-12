#include "commun.h" // Inclusion des déclarations nécessaires

int main() {
    char masque_str[16]; // Buffer pour stocker le masque de sous-réseau saisi
    struct in_addr masque; // Structure pour stocker l'adresse du masque

    printf("Saisir un masque de sous-réseau (format: x.x.x.x) : ");
    scanf("%15s", masque_str); // Lecture du masque de sous-réseau

    // Validation du masque de sous-réseau
    if (!valider_masque(masque_str, &masque)) {
        printf("Erreur : masque de sous-réseau invalide.\n");
        return 1;
    }

    // Confirmation du masque valide
    printf("Masque de sous-réseau valide : %s\n", masque_str);

    return 0;
}
