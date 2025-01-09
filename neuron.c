#include "neuron.h"
#include <stdio.h>
#include <stdlib.h>

neuron InitNeur(int NbParameters, list weights, int bias) {
    //Initialization:
    neuron newel;
    newel.bias = bias;
    newel.weights = NULL;

    //Creation of the weights list:
    element* temp = NULL;
    for (int i = 0; i < NbParameters; i++) {
        if (poids == NULL) {
            printf("ERROR: Insufficient weight count.\n");
            exit(EXIT_FAILURE);
        }

        //Allocate a new item for the list:
        element* newel_elem = (element*)malloc(sizeof(element));
        newel_elem->value = poids->value;
        newel_elem->next = NULL;

        if (newel.weights == NULL) {
            newel.weights = newel_elem;
        } else {
            temp->next = newel_elem;
        }
        temp = newel_elem;
        poids = weights->next;
    }
    return newel;
}

int OutNeur(neuron neur, list entries, int NbEntries) {
    //Initialization:
    int sum = 0;
    element* currentWeights = neur.weights;

    //Calculation of weighted sum:
    for (int i = 0; i < NbEntries; i++) {
        if (currentWeights == NULL) {
            printf("ERROR: Insufficient weight for this entry.\n");
            return -1;
        }
        if (entries == NULL) {
            printf("ERREOR: Insufficient entries count.\n");
            return -1;
        }

        sum += entries->value * currentWeights->value;
        entries = entries->next;
        currentWeights = currentWeights->next;
    }

    //Activation function:
    if (sum >= n.bias) {return 1;} else {return 0;}
}
