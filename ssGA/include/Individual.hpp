//
// Created by esteve on 02/07/22.
//

#ifndef P_HUB_GENETIC_ALGORITHM_INDIVIDUAL_H
#define P_HUB_GENETIC_ALGORITHM_INDIVIDUAL_H

#include "Chromosome.hpp"

class Individual {
public:
    explicit Individual(size_t n_alelles) : chromosomes_(n_alelles) {

    }

    Chromosome chromosomes_;
    double fitness_{0.0};

};

#endif //P_HUB_GENETIC_ALGORITHM_INDIVIDUAL_H
