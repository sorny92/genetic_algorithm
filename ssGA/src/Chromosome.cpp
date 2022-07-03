//
// Created by esteve on 03/07/22.
//

#include "Chromosome.hpp"


Chromosome::Chromosome(size_t n_chromosomes) {
    alleles_ = random_bitset(n_chromosomes);
}