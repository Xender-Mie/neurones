#ifndef NETWORK_H
#define NETWORK_H
#include "layer_neurons.h"

typedef struct elemNet {
    LayerNeurons layer;
    struct elemNet* next;
}elementNetwork;

typedef elementNetwork* network;

/**
 * Function that creates a neural network with a fixed number of layers and inputs.
 * @param NbLayer The number of layer in the network.
 * @param NbNeurons The number of neurons per layer.
 * @param NbEntries The number of entries of the network.
 * @return
 */
network CreatNetwork(int NbLayer, list NbNeurons, int NbEntries);

/**
 * Function that initializes a neural network.
 * @return
 */
network InitNetwork();

/**
 * Function that calculates the output of a neural network in the form of a chained list.
 * @param net The network from which the output is calculated.
 * @param entries List of the entries of the network.
 * @return
 */
list OutNetwork(network net, list entries);

/**
 * Function that adds a layer at the top of a network.
 * @param net The network to which you want to add a layer.
 * @param layer The layer to add.
 * @return
 */
network addHeadNet(network net, LayerNeurons layer);

/**
 * Function that adds a layer at the end of a network.
 * @param net The network to which you want to add a layer.
 * @param layer The layer to add.
 * @return
 */
network addTailNet(network net, LayerNeurons layer);
#endif //NETWORK_H
