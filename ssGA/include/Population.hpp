#pragma once

#include <cstddef>
#include <vector>
#include <queue>
#include <optional>
#include <memory>
#include "Individual.hpp"
#include "fmt/core.h"


class Population {
public:
    Population(size_t n_individuals, size_t n_chromosomes) : n_chromosomes_(n_chromosomes) {
        for (auto i = 0; i < n_individuals; ++i) {
            individuals_.emplace_back(n_chromosomes);
        }
    }

    [[nodiscard]] Individual get_worst_performer() const {
        return individuals_[*worst_];
    }

    [[nodiscard]] Individual get_best_performer() const {
        return individuals_[*best_];
    }

    Individual binary_tournament() {
        std::vector<Individual> out;
        std::sample(individuals_.begin(), individuals_.end(), std::back_inserter(out),
                    2, std::mt19937{std::random_device{}()});
        return (out[0].fitness > out[1].fitness) ? out[0] : out[1];
    }

    void kill_and_replace_worst_performer(const Individual &new_individual) {
        individuals_.erase(individuals_.begin() + *worst_);
        individuals_.emplace_back(new_individual);
    }

    std::vector<Individual> &individuals() {
        return individuals_;
    }

    void print_statistics() const {
        fmt::print("Iter {}: Best: {}->{:.3f}  || Worst: {}->{:.3f}  || Avg_fitness: {:.3f}  || Best_genome: {}\n", iteration_, *best_,
                   individuals_[*best_].fitness, *worst_, individuals_[*worst_].fitness, average_fitness, get_best_performer().chromosomes_.get_genome());
    }

    void update_statistics() {
        average_fitness = 0;
        worst_ = std::nullopt;
        best_ = std::nullopt;
        for (auto i = 0; i < individuals_.size(); ++i) {
            if (!best_ || individuals_[i].fitness < individuals_[*best_].fitness) {
                best_ = i;
            }
            if (!worst_ || individuals_[i].fitness > individuals_[*worst_].fitness) {
                worst_ = i;
            }
            average_fitness += individuals_[i].fitness;
        }
        average_fitness /= individuals_.size();
        iteration_++;
    }

private:
    size_t iteration_{0};
    const size_t n_chromosomes_;
    std::optional<size_t> best_;
    std::optional<size_t> worst_;
    double average_fitness{0};
    std::vector<Individual> individuals_;
};
