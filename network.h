#ifndef RESEAU_H
#define RESEAU_H
#include "couche_neurones.h"

typedef struct elem_reseau {
    couche_neurones couche;
    struct elem_reseau* suivant;
}element_reseau;

typedef element_reseau* reseau;

/**
 * Fonction qui permet de créer un réseau neuronale quivant un nombre de couche et d'entrées fixés.
 * @param nb_couches Le nombre de couche du réseau.
 * @param nb_neurones le nombre de neurones par couche.
 * @param nb_entrees Le nombre d'entrées du réseau.
 * @return
 */
reseau CreerResNeur(int nb_couches, list nb_neurones, int nb_entrees);

/**
 * Fonction qui permet d'initialiser un réseau neuronale.
 * @return
 */
reseau InitResNeur();

/**
 * Fonction qui permet de calculer la sortie d'un réseau neuronale sous forme de liste chaînée.
 * @param res Le réseaux dont on calcul la sortie.
 * @param entrees Liste des entrées du réseaux.
 * @return
 */
list OutResNeur(reseau res, list entrees);

/**
 * Fonction qui permet d'ajouter une couche en tête d'un réseau.
 * @param res Le réseau auquel on veut ajouter une couche.
 * @param couche La couche à ajouter.
 * @return
 */
reseau ajout_tete_reseau(reseau res, couche_neurones couche);

/**
 * Fonction qui permet d'ajouter une couche en queu à une réseau.
 * @param res Le réseau auquel on veut ajouter une couche.
 * @param couche La couche à ajouter.
 * @return
 */
reseau ajout_fin_reseau(reseau res, couche_neurones couche);
#endif //RESEAU_H
