#include "commun.h" // Inclusion des déclarations nécessaires

int main() {
    char ip_str[16]; // Buffer pour stocker l'adresse IP saisie
    struct in_addr ip; // Structure pour stocker l'adresse IP convertie

    printf("Saisir une adresse IP (format: x.x.x.x) : ");
    scanf("%15s", ip_str); // Lecture de l'adresse IP

    // Validation du format de l'adresse IP
    if (!valider_ip(ip_str, &ip)) {
        printf("Erreur : format incorrect.\n");
        return 1;
    }

    // Affichage de l'adresse IP en notation décimale 32 bits
    printf("Adresse IP (32 bits) : %u\n", ntohl(ip.s_addr));

    return 0;
}
