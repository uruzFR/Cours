#include "commun.h"

int main() {
    char masque_str[16];
    struct in_addr masque;

    printf("Saisir un masque de sous-réseau : ");
    scanf("%15s", masque_str);

    if (!valider_masque(masque_str, &masque)) {
        printf("Erreur : masque de sous-réseau invalide.\n");
        return 1;
    }

    printf("CIDR : /%d\n", calculer_cidr(masque));
    return 0;
}
