#pragma once

#include <utility>

#include "Chromosome.hpp"

class Individual {
public:
    explicit Individual(size_t n_alelles) : chromosomes_(n_alelles) {

    }
    void set_genetic_code(const Chromosome& chromosome){
        chromosomes_ = chromosome;
    }

    Chromosome chromosomes_;
    double fitness_{0.0};

};
