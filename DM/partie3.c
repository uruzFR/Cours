#include "commun.h"

int main() {
    char ip_str[16], masque_str[16];
    struct in_addr ip, masque, reseau;

    printf("Saisir une adresse IP : ");
    scanf("%15s", ip_str);
    printf("Saisir un masque de sous-réseau : ");
    scanf("%15s", masque_str);

    if (!valider_ip(ip_str, &ip) || !valider_masque(masque_str, &masque)) {
        printf("Erreur : entrée invalide.\n");
        return 1;
    }

    calculer_adresse_reseau(ip, masque, &reseau);
    printf("Adresse réseau : %s\n", inet_ntoa(reseau));
    return 0;
}
