#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list ajout_tete(list l, int valeur) {
    //On créer un nouvel élément:
    list newel = (element*) malloc(sizeof(element));

    //On créer un nouvel élément:
    newel->valeur=valeur;

    //On assigne l'adresse de l'élément suivant au nouvel élément:
    newel->suivant=l;

    //On retourne la nouvelle liste:
    return newel;
}

list ajout_fin(list l, int valeur) {
    //On créer un nouvel élément:
    list newel = (element*) malloc(sizeof(element));

    //On assigne la valeur du nouvel élément:
    newel->valeur=valeur;

    //On déclare l'adresse de l'élément suivant comme nul:
    newel->suivant=NULL;

    //Si la liste est vide il suffit de renvoyer l'élément créé:
    if (l==NULL) {
        return newel;
    } else { //Sinon on parcourt la liste à l'aide d'un pointeur temporaire et on indique que le dernier élément de la liste est relié au nouvel élément
        list temp=l;
        while (temp->suivant!=NULL) {
            temp=temp->suivant;
        }
        temp->suivant=newel;
        return l;
    }

    //On retourne la nouvelle liste:
    return l;
}

list supp_tete(list l) {
    if(l!=NULL) {
        //Si la liste est non vide on se prépare à renvoyer l'adresse de l'élément en 2ème position:
        list aRenvoyer=l->suivant;
        //On libère le premier élément:
        free(l);
        //On retourne le nouveau début de la liste:
        return aRenvoyer;
    } else {
        return NULL;
    }
}

list supp_fin(list l) {
    //On accède à la fin de la liste:
    list temp=l;
    while (temp->suivant!=NULL) {
        temp=temp->suivant;
    }

    //On libère l'espace mémoire contenant la queu:
    free(l);

    //On assigne l'adresse de la nouvelle queu:
    temp->suivant=NULL;

    //On retourne la nouvelle liste:
    return temp;
}

int compter_elements(list l) {
    int compteur = 0;
    //On n'utilise une liste temporaire pour ne pas modifier la liste.
    list temp=l;
    //Tant que la liste n'est pas vide on la parcours en incrémentant le compteur.
    while (temp != NULL) {
        compteur++;
        temp = temp->suivant;
    }
    return compteur;
}

void afficher_liste(list l) {
    //Si la liste est vide alors on en informe l'utilisateur:
    if (l == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    //Sinon on parcour une liste temporaire pour ne pas modifier la liste d'origine:
    list temp=l;
    while (temp != NULL) {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    }
}