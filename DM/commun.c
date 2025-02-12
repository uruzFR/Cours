#include "commun.h"

int valider_ip(const char *ip_str, struct in_addr *ip) {
    return inet_pton(AF_INET, ip_str, ip) == 1;
}

int valider_masque(const char *masque_str, struct in_addr *masque) {
    if (inet_pton(AF_INET, masque_str, masque) != 1) {
        return 0;
    }

    uint32_t m = ntohl(masque->s_addr);
    int found_zero = 0;
    
    for (int i = 31; i >= 0; i--) {
        if ((m >> i) & 1) {
            if (found_zero) return 0;
        } else {
            found_zero = 1;
        }
    }
    return 1;
}

void calculer_adresse_reseau(struct in_addr ip, struct in_addr masque, struct in_addr *reseau) {
    reseau->s_addr = ip.s_addr & masque.s_addr;
}

void calculer_adresse_broadcast(struct in_addr reseau, struct in_addr masque, struct in_addr *broadcast) {
    broadcast->s_addr = reseau.s_addr | ~masque.s_addr;
}

int calculer_cidr(struct in_addr masque) {
    uint32_t m = ntohl(masque.s_addr);
    int bits = 0;
    
    while (m) {
        bits += m & 1;
        m >>= 1;
    }
    return bits;
}
