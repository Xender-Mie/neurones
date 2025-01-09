#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list  addHead(list l, int value) {
    //We creat a new element:
    list newel = (element*) malloc(sizeof(element));
    newel->value=value;

    //The address of the following element is assigned to the new element:
    newel->next=l;

    //We return the new list:
    return newel;
}

list  addTail(list l, int valeur) {
    //We creat a new element:
    list newel = (element*) malloc(sizeof(element));

    //We assign the value of the new element:
    newel->value=value;

    //The address of the following item is declared as null:
    newel->next=NULL;

    //If the list is empty, just return the created item:
    if (l==NULL) {
        return newel;
    } else { //Otherwise, we run the list using a temporary pointer and indicate that the last item in the list is linked to the new item:
        list temp=l;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=newel;
        return l;
    }

    //We return the new list:
    return l;
}

list  deleteHead(list l) {
    if(l!=NULL) {
        //If the list is not empty, we prepare to return the address of the element in 2nd position:
        list temp=l->next;
        //We release the first element:
        free(l);
        //Returns the new start of the list:
        return temp;
    } else {
        return NULL;
    }
}

list  deleteTail(list l) {
    //Go to the end of the list:
    list temp=l;
    while (temp->next!=NULL) {
        temp=temp->next;
    }

    //We free the memory space containing the tail:
    free(l);

    //The address of the new location is assigned:
    temp->next=NULL;

    //Returns the new list:
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

int countElement(list l) {
    //If the list is empty we inform the user:
    if (l == NULL) {
        printf("The list is empty.\n");
        return;
    }

    //Otherwise we browse a temporary list to not change the original list:
    list temp=l;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
}
