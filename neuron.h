#ifndef NEURON_H
#define NEURON_H
#include "list.h"

typedef struct {
    list weights;
    int bias;
}neuron;

/**
 * Fonction that initialize a new neuron with given parameters.
 * @param NbParameters Number of entry that the neuron can take.
 * @param weight The weights associated to each entry.
 * @param bias The way du neurone.
 * @return The new neuron.
 */
neuron InitNeur(int NbParameters, list weight, int bias);

/**
 * Fonction that compute the output of a neuron in depend of a given list of entries.
 * @param neur Neuron that we compute the output.
 * @param entries Entries list.
 * @param NbEntries Entries number.
 * @return
 */
int OutNeur(neuron neur, list entries, int NbEntries);

#endif //NEURON_H
