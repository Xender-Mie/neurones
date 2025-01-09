#ifndef LAYER_NEURONS_H
#define LAYER_NEURONS_H
#include "list.h"
#include "neuron.h"

typedef struct elemLayer {
    neuron neur;
    struct elemLayer* next;
} elementLayer;

typedef elementLayer* LayerNeurons;

/**
 * Function that creates a layer and initializes its neurons.
 * @param NbNeurons Number of neurons present in the layer.
 * @param NbEntries Number of neurons input.
 * @return
 */
LayerNeurons InitLayer(int NbNeurons, int NbEntries);

/**
 * Function that allows to calculate the list of outputs of a neurone’s skin.
 * @param layer The layer for which outputs are to be calculated.
 * @param entries List of entries of the layer.
 * @param NbEntries Number of entries of the layer.
 * @return
 */
list OutLayer(LayerNeurons layer, list entries, int NbEntries);

#endif //LAYER_NEURONS_H
