#include <stdio.h>
#include "commun.h"

int main() {
    uint32_t ip, masque, adresse_reseau, adresse_broadcast, premier_hote, dernier_hote;

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
    premier_hote = calculer_premier_hote(adresse_reseau);
    dernier_hote = calculer_dernier_hote(adresse_broadcast);

    // Affichage des résultats
    printf("Première adresse hôte : ");
    afficher_adresse_ip(premier_hote);

    printf("Dernière adresse hôte : ");
    afficher_adresse_ip(dernier_hote);

    return 0;
}
