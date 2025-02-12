#ifndef COMMUN_H
#define COMMUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Vérifie si une adresse IP est valide et la convertit en structure in_addr
int valider_ip(const char *ip_str, struct in_addr *ip);

// Vérifie si un masque de sous-réseau est valide et le convertit en structure in_addr
int valider_masque(const char *masque_str, struct in_addr *masque);

// Calcule l'adresse réseau à partir de l'adresse IP et du masque
void calculer_adresse_reseau(struct in_addr ip, struct in_addr masque, struct in_addr *reseau);

// Calcule l'adresse de broadcast à partir de l'adresse réseau et du masque
void calculer_adresse_broadcast(struct in_addr reseau, struct in_addr masque, struct in_addr *broadcast);

// Calcule le préfixe CIDR à partir du masque de sous-réseau
int calculer_cidr(struct in_addr masque);

#endif // COMMUN_H
