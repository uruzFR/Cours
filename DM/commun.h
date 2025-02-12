#ifndef COMMUN_H
#define COMMUN_H

#include <stdint.h>

// Fonction pour saisir et valider une adresse IP
int saisir_adresse_ip(uint32_t *ip);

// Fonction pour vérifier un masque de sous-réseau
int valider_masque_sous_reseau(uint32_t mask);

// Fonction pour calculer l'adresse de réseau
uint32_t calculer_adresse_reseau(uint32_t ip, uint32_t masque);

// Fonction pour calculer l'adresse de broadcast
uint32_t calculer_adresse_broadcast(uint32_t adresse_reseau, uint32_t masque);

// Fonction pour calculer la première adresse hôte
uint32_t calculer_premier_hote(uint32_t adresse_reseau);

// Fonction pour calculer la dernière adresse hôte
uint32_t calculer_dernier_hote(uint32_t adresse_broadcast);

// Fonction pour afficher une adresse IP au format x.x.x.x
void afficher_adresse_ip(uint32_t ip);

// Fonction pour calculer le nombre total d'hôtes
uint32_t calculer_nombre_hot(uint32_t adresse_reseau, uint32_t adresse_broadcast);

#endif
