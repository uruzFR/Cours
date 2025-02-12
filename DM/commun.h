#ifndef COMMUN_H
#define COMMUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int valider_ip(const char *ip_str, struct in_addr *ip);
int valider_masque(const char *masque_str, struct in_addr *masque);
void calculer_adresse_reseau(struct in_addr ip, struct in_addr masque, struct in_addr *reseau);
void calculer_adresse_broadcast(struct in_addr reseau, struct in_addr masque, struct in_addr *broadcast);
int calculer_cidr(struct in_addr masque);

#endif
