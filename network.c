#include "network.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

network CreatNetwork(int NbLayer, list NbNeurons, int NbEntries) {
    //Initialization:
    if (NbLayer == 0 || NbNeurons == NULL) {return NULL;}
    network net = NULL;

    //Creation of the entry layer:
    printf("First layer:\n");
    net = addHeadNet(net, InitLayer(NbNeurons->value, NbEntries));

    //Creation of the next layers:
    for (int i = 1; i < NbLayer; i++) {
        if (NbNeurons->next == NULL) {
            printf("ERROR: The neuron list ist too short for the number specified by the layer.\n");
            exit(EXIT_FAILURE);
        }
        NbEntries = NbNeurons->value;
        NbNeurons = NbNeurons->next;
        printf("Layer %d:\n",i+1);
        net = addTailNet(net, InitLayer(NbNeurons->value, NbEntries));
    }

    //Return the created network:
    return net;
}

network InitNetwork() {
    //Initialization:
    int NbLayer, value;
    list NbNeurons=NULL;

    //Initialization of the neural layers:
    printf("Enter the numbrr of layer of the network:\n");
    scanf("%d",&nb_couche);
    //Initialisation du nom de neurones par couche de neurones:
    for (int i=0;i<NbLayer;i++) {
        printf("Enter the number of neurons in the layer %d:",i+1);
        scanf("%d",&value);
        NbNeurons=addHead(NbNeurons,value);
    }
    //Initialization of the number of network entries:
    printf("Enter the number of entries of the network:\n");
    scanf("%d",&value);
    //Choice of network name (for list of all networks):
    printf("Enter the name of the new network:\n");
    return CreatNetwork(NbLayer,NbNeurons,value);
}

list OutNetwork(network net, list entries) {
    return NULL;
}

network addHeadNet(network net, LayerNeurons layer) {
    //We creat a new element:
    network newel = (elementNetwork*) malloc(sizeof(elementNetwork));

    //We assign the layer to this element:
    newel->layer = layer;

    //Because we add in the top the following element is the network:
    newel->next = next;

    //Return the new network:
    return newel;
}

network addTailNet(network net, LayerNeurons layer) {
    //We creat a new element:
    network newel = (elementNetwork*) malloc(sizeof(elementNetwork));

    //We assign the layer to this element:
    newel->layer = layer;

    //Because the following is added to be necessarily nil:
    newel->next = NULL;

    //If the network is empty just return on the created element:
    if (net == NULL) {
        return newel;
    }

    //Otherwise, the network is scanned with a temporary pointer and the last item in the list is linked to the new item:
    network temp = net;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newel;

    //Return the new network:
    return net;
}
