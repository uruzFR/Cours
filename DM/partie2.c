#include <stdio.h>
#include "commun.h"

int main() {
    unsigned int masque;

    printf("Saisir un masque de sous-réseau (format: x.x.x.x) :\n");

    if (saisir_adresse_ip(&masque) != 0) {
        return 1; // Erreur de saisie
    }

    if (valider_masque_sous_reseau(masque)) {
        printf("Masque de sous-réseau valide : %u\n", masque);
    } else {
        printf("Erreur : masque de sous-réseau invalide.\n");
    }

    return 0;
}
