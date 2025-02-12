#include <stdio.h>
#include "commun.h"

int main() {
    uint32_t ip, masque, adresse_reseau, adresse_broadcast;

    // Saisir l'adresse IP
    if (saisir_adresse_ip(&ip) != 0) {
        return 1;
    }

    // Saisir le masque de sous-réseau
    if (saisir_adresse_ip(&masque) != 0) {
        return 1;
    }

    // Vérifier si le masque est valide
    if (!valider_masque_sous_reseau(masque)) {
        printf("Erreur : masque de sous-réseau invalide.\n");
        return 1;
    }

    // Calcul de l'adresse réseau
    adresse_reseau = calculer_adresse_reseau(ip, masque);

    // Calcul de l'adresse de broadcast
    adresse_broadcast = calculer_adresse_broadcast(adresse_reseau, masque);

    // Affichage de l'adresse de broadcast
    printf("Adresse broadcast : ");
    afficher_adresse_ip(adresse_broadcast);

    return 0;
}
