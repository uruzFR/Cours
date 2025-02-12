#include "commun.h" // Inclusion des déclarations nécessaires

int main() {
    char ip_str[16], masque_str[16]; // Buffers pour stocker les entrées utilisateur
    struct in_addr ip, masque, reseau; // Structures pour les adresses IP et réseau

    printf("Saisir une adresse IP : ");
    scanf("%15s", ip_str); // Lecture de l'adresse IP

    printf("Saisir un masque de sous-réseau : ");
    scanf("%15s", masque_str); // Lecture du masque

    // Validation des entrées utilisateur
    if (!valider_ip(ip_str, &ip) || !valider_masque(masque_str, &masque)) {
        printf("Erreur : entrée invalide.\n");
        return 1;
    }

    // Calcul de l'adresse réseau
    calculer_adresse_reseau(ip, masque, &reseau);

    // Affichage de l'adresse réseau
    printf("Adresse réseau : %s\n", inet_ntoa(reseau));

    return 0;
}
