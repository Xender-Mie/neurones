#include "couche_neurones.h"
#include <stdio.h>
#include <stdlib.h>

couche_neurones InitCouche(int nb_neurones, int nb_entrees) {
    //Initialisation:
    if (nb_neurones == 0) {return NULL;}
    couche_neurones tete = NULL;
    couche_neurones temp = NULL;
    list poids = NULL;
    int biais;
    int poidsj;

    for (int i = 0; i < nb_neurones; i++) {
        //Initialisation de la liste des poids pour le neurone courant:
        poids = NULL;
        for (int j = 0; j < nb_entrees; j++) {
            printf("Entrez le poids %d associe au neurone %d:\n", j+1, i+1);
            scanf("%d", &poidsj);
            poids=ajout_fin(poids,poidsj);
        }

        //Lecture du biais du neurone:
        printf("Quel est le biais du neurone %d?\n", i + 1);
        scanf("%d", &biais);

        //Initialisation du neurone avec les poids et le biais:
        neurone n = InitNeur(nb_entrees, poids, biais);

        //Création d'un nouvel élément de la couche:
        couche_neurones newel = (element_couche*)malloc(sizeof(element_couche));
        newel->N = n;
        newel->suivant = NULL;

        //Ajout du neurone à la couche:
        if (tete == NULL) {tete = newel;} else {temp->suivant = newel;}
        temp = newel;
    }

    return tete;
}

list Outcouche(couche_neurones couche, list entrees, int nb_entrees) {
    //Initialisation:
    if (couche == NULL || entrees == NULL) {return NULL;}
    list sorties = NULL;

    //Calcul des sorties:
    while (couche != NULL) {
        //Calcule la sortie du neurone courant:
        int sortie = Outneurone(couche->N, entrees, nb_entrees);

        //Ajoute la sortie à la tête de la liste:
        ajout_tete(sorties,sortie);
        couche = couche->suivant;
    }
    return sorties;
}