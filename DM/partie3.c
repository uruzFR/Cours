#include <stdio.h>
#include "commun.h"

int main() {
    uint32_t ip, masque, adresse_reseau;

    // Saisir l'adresse IP
    if (saisir_adresse_ip(&ip) != 0) {
        return 1; // Erreur de saisie
    }

    // Saisir le masque de sous-réseau
    if (saisir_adresse_ip(&masque) != 0) {
        return 1; // Erreur de saisie
    }

    // Vérifier si le masque est valide
    if (!valider_masque_sous_reseau(masque)) {
        printf("Erreur : masque de sous-réseau invalide.\n");
        return 1;
    }

    // Calcul de l'adresse réseau
    adresse_reseau = calculer_adresse_reseau(ip, masque);

    // Affichage de l'adresse réseau
    printf("Adresse réseau : ");
    afficher_adresse_ip(adresse_reseau);

    return 0;
}
