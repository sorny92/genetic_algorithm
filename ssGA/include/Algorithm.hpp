#pragma once

#include <utility>

#include "Individual.hpp"
#include "Population.hpp"
#include "../../pHub/include/phub.hpp"

class ssGA {
public:
    ssGA(pHub problem, size_t individuals, size_t genoma_length, double probability_crossover,
         double probability_mutation) : population(individuals, genoma_length),
                                        problem_(std::move(problem)),
                                        probability_crossover_(probability_crossover),
                                        probability_mutation_(probability_mutation) {
    }

    void fit_population(){
        for(auto& i: population.individuals()){
            i.fitness = problem_.calculate_fitness(i);
            //fmt::print("Fitness: {:.3f}\t - ", i.fitness);
            //i.chromosomes_.print();
        }
        population.update_statistics();
    }

    void print_statistics() const {
        population.print_statistics();
    }

    void next_step() {
        auto new_individual = single_point_crossover(population.binary_tournament(), population.binary_tournament());
        new_individual.chromosomes_.mutate(probability_mutation_);
        population.kill_and_replace_worst_performer(new_individual);
    }

private:
    Population population;
    pHub problem_;
    double probability_crossover_;
    double probability_mutation_;
    std::mt19937 generator = std::mt19937{std::random_device{}()};


    Individual single_point_crossover(const Individual &i1, const Individual &i2) {
        {
            std::uniform_int_distribution<> distr(0, 99);
            if (distr(generator) > probability_crossover_ * 100) {
                return (distr(generator) < 50) ? i1 : i2;
            }
        }

        std::uniform_int_distribution<> distr(0, i1.chromosomes_.size() - 1);
        auto position_crosover = distr(generator);
        auto out = Individual(i1);
        for (auto i = position_crosover; i < out.chromosomes_.size(); ++i) {
            out.chromosomes_.set_allele(i, i2.chromosomes_.get_allele(i));
        }
        return out;
    }
};