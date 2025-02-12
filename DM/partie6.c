#include <stdio.h>
#include "commun.h"

int main() {
    uint32_t ip, masque, adresse_reseau, adresse_broadcast, nombre_hot;

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

    // Calcul des adresses
    adresse_reseau = calculer_adresse_reseau(ip, masque);
    adresse_broadcast = calculer_adresse_broadcast(adresse_reseau, masque);
    nombre_hot = calculer_nombre_hot(adresse_reseau, adresse_broadcast);

    // Affichage du résultat
    printf("Nombre total d'hôtes disponibles : %u\n", nombre_hot);

    return 0;
}
