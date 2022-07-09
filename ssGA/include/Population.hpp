#pragma once

#include <cstddef>
#include <vector>
#include <queue>
#include "Individual.hpp"

auto cmp = [](const Individual &left, const Individual &right) { return (left.fitness_) < (right.fitness_); };

class Population {
public:
    Population(size_t n_individuals, size_t n_chromosomes) : individuals_(n_individuals, Individual(n_chromosomes)),
                                                             n_chromosomes_(n_chromosomes) {
    }

    [[nodiscard]] size_t get_worst_performer() const {
        return worst_;
    }

    [[nodiscard]] size_t get_best_performer() const {
        return best_;
    }

    void kill_and_replace_worst_performer() {
        auto index = get_worst_performer();
        individuals_[index] = Individual(n_chromosomes_);
    }

private:
    const size_t n_chromosomes_;
    size_t best_{0};
    size_t worst_{0};
    std::vector<Individual> individuals_;
};
