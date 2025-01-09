#include "network.h"
#include <stdio.h>
#include <stdlib.h>

neurone InitNeur(int nb_parametres, list poids, int biais) {
    //Initialisation:
    neurone newel;
    newel.biais = biais;
    newel.poids = NULL;

    //Création de la liste de poids:
    element* temp = NULL;
    for (int i = 0; i < nb_parametres; i++) {
        if (poids == NULL) {
            printf("ERREUR: Nombre de poids insuffisant.\n");
            exit(EXIT_FAILURE);
        }

        //Allouer un nouvel élément pour la liste:
        element* newel_elem = (element*)malloc(sizeof(element));
        newel_elem->valeur = poids->valeur;
        newel_elem->suivant = NULL;

        if (newel.poids == NULL) {
            newel.poids = newel_elem;
        } else {
            temp->suivant = newel_elem;
        }
        temp = newel_elem;
        poids = poids->suivant;
    }
    return newel;
}

int Outneurone(neurone n, list entrees, int nb_entrees) {
    //Initialisation:
    int somme = 0;
    element* poids_courant = n.poids;

    //Calcul de la somme pondérée:
    for (int i = 0; i < nb_entrees; i++) {
        if (poids_courant == NULL) {
            printf("ERREUR: Nombre de poids insuffisant pour cette entrée.\n");
            return -1;
        }
        if (entrees == NULL) {
            printf("ERREUR: Nombre d'entrees insuffisant.\n");
            return -1;
        }

        somme += entrees->valeur * poids_courant->valeur;
        entrees = entrees->suivant;
        poids_courant = poids_courant->suivant;
    }

    //Fonction d'activation:
    if (somme >= n.biais) {return 1;} else {return 0;}
}
