#include "layer_neurons.h"
#include <stdio.h>
#include <stdlib.h>

LayerNeurons InitLayer(int NbNeurons, int NbEntries) {
    //Initialization:
    if (NbNeurons == 0) {return NULL;}
    LayerNeurons head = NULL;
    LayerNeurons temp = NULL;
    list weights = NULL;
    int bias;
    int weightsj;

    for (int i = 0; i < NbNeurons; i++) {
        //Initialization of weight list for current neuron:
        weights = NULL;
        for (int j = 0; j < NbEntries; j++) {
            printf("Enter the weights %d associated to the neuron %d:\n", j+1, i+1);
            scanf("%d", &weightsj);
            weights=addTail(weights,weightsj);
        }

        //Reading of neuron bias:
        printf("Enter the bias of the neuron %d:\n", i + 1);
        scanf("%d", &bias);

        //Neurone initialization with weights and bias:
        neuron neur = InitNeur(NbEntries, weights, bias);

        //Creating a new layer element:
        LayerNeurons newel = (elementLayer*)malloc(sizeof(elementLayer));
        newel->neur = neur;
        newel->next = NULL;

        //Adding the neuron to the layer:
        if (head == NULL) {head = newel;} else {temp->next = newel;}
        temp = newel;
    }

    return head;
}

list OutLayer(LayerNeurons layer, list entries, int NbEntries) {
    //Initialization:
    if (layer == NULL || entries == NULL) {return NULL;}
    list output = NULL;

    //Compute the output:
    while (layer != NULL) {
        //Compute the output of the current neuron:
        int out = OutNeur(layer->neur, entries, NbEntries);

        //Ajoute la sortie à la tête de la liste:
        addHead(output,out);
        layer = layer->next;
    }
    return output;
}
