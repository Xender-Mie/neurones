#ifndef COUCHE_NEURONES_H
#define COUCHE_NEURONES_H
#include "list.h"
#include "neurone.h"

typedef struct elem_couche {
    neurone N;
    struct elem_couche* suivant;
} element_couche;

typedef element_couche* couche_neurones;

/**
 * Fonction qui permet de créer une couche et d'initialiser ses neurones.
 * @param nb_neurones Nombre de neurones présent dans la couche.
 * @param nb_entrees Nombre d'entrées des neurones.
 * @return
 */
couche_neurones InitCouche(int nb_neurones, int nb_entrees);

/**
 * Fonction qui permet de calculer la liste des sorties d'une couhe de neurones.
 * @param couche la couche dont on souhaite calculer les sorties.
 * @param entrees Liste d'entrées de la couche.
 * @param nb_entrees Nombre d'entrées dans la liste.
 * @return
 */
list Outcouche(couche_neurones couche, list entrees, int nb_entrees);

#endif //COUCHE_NEURONES_H
