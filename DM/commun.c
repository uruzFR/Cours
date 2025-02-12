#include <stdio.h>
#include <stdlib.h>
#include "commun.h"

int saisir_adresse_ip(uint32_t *ip) {
    int octet1, octet2, octet3, octet4;
    
    printf("Saisir une adresse IP (format: x.x.x.x) : ");
    
    if (scanf("%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4) != 4) {
        printf("Erreur : format incorrect.\n");
        return 1;
    }

    if (octet1 < 0 || octet1 > 255 || octet2 < 0 || octet2 > 255 || 
        octet3 < 0 || octet3 > 255 || octet4 < 0 || octet4 > 255) {
        printf("Erreur : adresse IP invalide (%d.%d.%d.%d).\n", octet1, octet2, octet3, octet4);
        return 1;
    }

    *ip = (octet1 << 24) | (octet2 << 16) | (octet3 << 8) | octet4;
    return 0;
}

int valider_masque_sous_reseau(uint32_t mask) {
    return (mask & (mask + 1)) == 0;
}

uint32_t calculer_adresse_reseau(uint32_t ip, uint32_t masque) {
    return ip & masque;
}

uint32_t calculer_adresse_broadcast(uint32_t adresse_reseau, uint32_t masque) {
    return adresse_reseau | ~masque;
}

uint32_t calculer_premier_hote(uint32_t adresse_reseau) {
    return adresse_reseau + 1;
}

uint32_t calculer_dernier_hote(uint32_t adresse_broadcast) {
    return adresse_broadcast - 1;
}

uint32_t calculer_nombre_hot(uint32_t adresse_reseau, uint32_t adresse_broadcast) {
    return (adresse_broadcast - adresse_reseau) - 1;
}

void afficher_adresse_ip(uint32_t ip) {
    printf("%d.%d.%d.%d\n", 
        (ip >> 24) & 0xFF, 
        (ip >> 16) & 0xFF, 
        (ip >> 8) & 0xFF, 
        ip & 0xFF);
}
