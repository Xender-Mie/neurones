#include "reseau.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

reseau CreerResNeur(int nb_couches, list nb_neurones, int nb_entrees) {
    //Initialisation:
    if (nb_couches == 0 || nb_neurones == NULL) {return NULL;}
    reseau res = NULL;

    //Création de la couche d'entrée:
    printf("Premiere couche:\n");
    res = ajout_tete_reseau(res, InitCouche(nb_neurones->valeur, nb_entrees));

    //Création des couches suivantes:
    for (int i = 1; i < nb_couches; i++) {
        if (nb_neurones->suivant == NULL) {
            printf("Erreur : Liste nb_neurones trop courte pour le nombre de couches spécifié.\n");
            exit(EXIT_FAILURE);
        }
        nb_entrees = nb_neurones->valeur;
        nb_neurones = nb_neurones->suivant;
        printf("Couche %d:\n",i+1);
        res = ajout_fin_reseau(res, InitCouche(nb_neurones->valeur, nb_entrees));
    }

    //On renvoi le réseau créé:
    return res;
}

reseau InitResNeur() {
    //Initialisation:
    int nb_couche, valeur;
    list nb_neurones=NULL;

    //Initialisation des couches de neurones:
    printf("Entrez le nombre de couches ce reseau:\n");
    scanf("%d",&nb_couche);
    //Initialisation du nombre de neurones par couche de neurones:
    for (int i=0;i<nb_couche;i++) {
        printf("Entrez le nombre de neurones dans la couche %d:",i+1);
        scanf("%d",&valeur);
        nb_neurones=ajout_fin(nb_neurones,valeur);
    }
    //Initialisation du nombre d'entrées du réseaux:
    printf("Entrez le nombre d entrees du reseau:\n");
    scanf("%d",&valeur);
    //Choix du nom du réseau (pour la liste de tous les réseaux):
    printf("Entrez le nom de votre reseau:\n");
    return CreerResNeur(nb_couche,nb_neurones,valeur);
}

reseau ajout_tete_reseau(reseau res, couche_neurones couche) {
    return NULL;
}

reseau ajout_tete_reseau(reseau res, couche_neurones couche) {
    //On créer un nouvel élément:
    reseau newel = (element_reseau*) malloc(sizeof(element_reseau));

    //On assigne la couche à cet élément:
    newel->couche = couche;

    //Du fait qu'on ajoute en tête l'élément suivant est le réseau:
    newel->suivant = res;

    //On renvoi le nouveau réseau:
    return newel;
}

reseau ajout_fin_reseau(reseau res, couche_neurones couche) {
    //On créer un nouvel élément:
    reseau newel = (element_reseau*) malloc(sizeof(element_reseau));

    //On assigne la couche à cet élément:
    newel->couche = couche;

    //Du fait qu'on ajoute en queu l'élément suivant est nécessairment nul:
    newel->suivant = NULL;

    //Si le réseau est vide il suffit de renvoyer sur l'élément créé:
    if (res == NULL) {
        return newel;
    }

    //Sinon on parcourt le réseau à l'aide d'un pointeur temporaire et on indique que le dernier élément de la liste est relié au nouvel élément:
    reseau temp = res;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = newel;

    //On renvoi le nouveau réseau:
    return res;
}
