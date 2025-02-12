#include "commun.h"

// Valide le format de l'adresse IP en notation décimale pointée
int valider_ip(const char *ip_str, struct in_addr *ip) {
    return inet_pton(AF_INET, ip_str, ip) == 1;
}

// Vérifie si un masque de sous-réseau est valide (doit être une suite de 1 suivie de 0 en binaire)
int valider_masque(const char *masque_str, struct in_addr *masque) {
    if (inet_pton(AF_INET, masque_str, masque) != 1) {
        return 0; // Format invalide
    }

    uint32_t m = ntohl(masque->s_addr); // Conversion en format hôte
    int found_zero = 0;

    // Vérifie que les bits sont bien consécutifs (1 en début, 0 ensuite)
    for (int i = 31; i >= 0; i--) {
        if ((m >> i) & 1) {
            if (found_zero) return 0; // Si un 0 a déjà été trouvé, ce n'est pas un masque valide
        } else {
            found_zero = 1;
        }
    }
    return 1;
}

// Calcule l'adresse réseau en appliquant un ET logique entre l'IP et le masque
void calculer_adresse_reseau(struct in_addr ip, struct in_addr masque, struct in_addr *reseau) {
    reseau->s_addr = ip.s_addr & masque.s_addr;
}

// Calcule l'adresse de broadcast en appliquant un OU logique entre l'adresse réseau et l'inverse du masque
void calculer_adresse_broadcast(struct in_addr reseau, struct in_addr masque, struct in_addr *broadcast) {
    broadcast->s_addr = reseau.s_addr | ~masque.s_addr;
}

// Détermine la longueur du préfixe CIDR (nombre de bits à 1 dans le masque)
int calculer_cidr(struct in_addr masque) {
    uint32_t m = ntohl(masque.s_addr); // Conversion en format hôte
    int bits = 0;

    // Compte le nombre de bits à 1 dans le masque
    while (m) {
        bits += m & 1;
        m >>= 1;
    }
    return bits;
}
