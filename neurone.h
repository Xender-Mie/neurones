#ifndef NEURONE_H
#define NEURONE_H
#include "list.h"

typedef struct {
    list poids;
    int biais;
}neurone;

/**
 * Fonction qui permet d'initialiser une neurone en fonction de paramètres données.
 * @param nb_parametres Nombre d'entrées que peut prendre le neurone.
 * @param poids Le poid associé à chaque entrées.
 * @param biais Le biais du neurone.
 * @return Le nouveau neurone.
 */
neurone InitNeur(int nb_parametres, list poids, int biais);

/**
 * Fonction qui permet de calculer la sortie d'un neurone en fonction d'une liste d'entrées.
 * @param n Neurone dont on vas calculer la sortie.
 * @param entrees Liste d'entrées.
 * @param nb_entrees Nombre d'entrées.
 * @return
 */
int Outneurone(neurone n, list entrees, int nb_entrees);

#endif //NEURONE_H
