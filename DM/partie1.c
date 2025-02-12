#include <stdio.h>
#include "commun.h"

int main() {
    unsigned int ip;
    if (saisir_adresse_ip(&ip) == 0) {
        printf("Adresse IP (32 bits) : %u\n", ip);
    }
    return 0;
}
