#include <stdio.h>
#include <stdint.h>
int octet1, octet2, octet3, octet4; // Pour l'adresse IP et le masque
unsigned int ip, mask, adresse_reseau; // 32 bits pour l'adresse IP, le masque et l'adresse réseau

// Convertir les octets en entier 32 bits
unsigned int convertir_en_32_bits(int octet1, int octet2, int octet3, int octet4) {
    return (octet1 << 24) | (octet2 << 16) | (octet3 << 8) | octet4;
}

// Fonction pour calculer l'adresse réseau
unsigned int calculer_adresse_reseau(unsigned int ip, unsigned int mask) {
    return ip & mask;
}

// Fonction pour afficher une adresse IP en format "x.x.x.x"
void afficher_ip(unsigned int ip) {
    printf("%d.%d.%d.%d\n", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}

int main() {
    // Saisie de l'adresse IP
    printf("Saisir une adresse IP:\n");
    if (scanf("%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4) != 4) {
        printf("Erreur saisie incorrecte pour l'adresse IP\n");
        return 1;
    }

    // Vérifier que chaque nombre de l'adresse IP est entre 0 et 255
    if (octet1 < 0 || octet1 > 255 || octet2 < 0 || octet2 > 255 || octet3 < 0 || octet3 > 255 || octet4 < 0 || octet4 > 255) {
        printf("Erreur saisie incorrecte: %d.%d.%d.%d\n", octet1, octet2, octet3, octet4);
        return 1;
    }

    // Convertir l'adresse IP en 32 bits
    ip = convertir_en_32_bits(octet1, octet2, octet3, octet4);

    // Afficher l'adresse IP
    printf("Adresse IP: ");
    afficher_ip(ip);

    // Saisie du masque de sous-réseau
    printf("Saisir un masque de sous-réseau:\n");
    if (scanf("%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4) != 4) {
        printf("Erreur saisie incorrecte pour le masque de sous-réseau\n");
        return 1;
    }

    // Vérifier que chaque nombre du masque est entre 0 et 255
    if (octet1 < 0 || octet1 > 255 || octet2 < 0 || octet2 > 255 || octet3 < 0 || octet3 > 255 || octet4 < 0 || octet4 > 255) {
        printf("Erreur saisie incorrecte: %d.%d.%d.%d\n", octet1, octet2, octet3, octet4);
        return 1;
    }

    // Convertir le masque en 32 bits
    mask = convertir_en_32_bits(octet1, octet2, octet3, octet4);

    // Afficher le masque de sous-réseau
    printf("Masque de sous-réseau: ");
    afficher_ip(mask);

    // Calculer l'adresse réseau
    adresse_reseau = calculer_adresse_reseau(ip, mask);

    // Afficher l'adresse réseau
    printf("Adresse réseau: ");
    afficher_ip(adresse_reseau);

    return 0;
}
