#include "commun.h"

int main() {
    char ip_str[16];
    struct in_addr ip;

    printf("Saisir une adresse IP (format: x.x.x.x) : ");
    scanf("%15s", ip_str);

    if (!valider_ip(ip_str, &ip)) {
        printf("Erreur : format incorrect.\n");
        return 1;
    }

    printf("Adresse IP (32 bits) : %u\n", ntohl(ip.s_addr));
    return 0;
}
