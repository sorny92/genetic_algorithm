//
// Created by esteve on 03/07/22.
//

#include "Chromosome.hpp"

std::mt19937 Chromosome::generator = std::mt19937{std::random_device{}()};

Chromosome::Chromosome(size_t n_chromosomes) {
    fill_with_random_genome(n_chromosomes);
}