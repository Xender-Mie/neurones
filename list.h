#ifndef LIST_H
#define LIST_H

typedef struct elem {
    int valeur;
    struct elem* suivant;
}element;

typedef element* list;

/**
 * Fonction qui permet d'ajouter un nouvel élément en tête de liste.
 * @param l La liste que l'on souhaite modifier.
 * @param valeur La valeur à rejouter.
 * @return La liste modifiée.
 */
list  ajout_tete(list l, int valeur);

/**
 * Fonction qui permet d'ajouter un élément en queu de liste.
 * @param l La liste que l'on souhaite modifier.
 * @param valeur La valeur à ajouter.
 * @return La liste modifiée.
 */
list  ajout_fin(list l, int valeur);

/**
 * Fonction qui permet de supprimer l'élément en tête d'une liste.
 * @param l La liste que l'on souhaite modifier.
 * @return La liste modifiée.
 */
list  supp_tete(list l);

/**
 * Fonction qui permet de supperimer un élément en queu d'une liste.
 * @param l La liste que l'on souhaite modifier.
 * @return La liste modifiée.
 */
list  supp_fin(list l);

/**
 * Fonction qui permet de compter le nombre d'éléments d'une liste chainée.
 * @param l La liste que l'on souhaite compter.
 * @return Le nombre d'élément de la liste.
 */
int compter_elements(list l);

/**
 * Procédure permettant d'afficher une liste.
 * @param l La à afficher.
 */
void afficher_liste(list l);

#endif //LIST_H