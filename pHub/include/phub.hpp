//
// Created by esteve on 07/07/22.
//

#ifndef P_HUB_GENETIC_ALGORITHM_PHUB_HPP
#define P_HUB_GENETIC_ALGORITHM_PHUB_HPP

#include <vector>
#include <map>
#include "Individual.hpp"
#include "dataset.hpp"

class pHub {
public:
    double calculate_fitness(const Individual &individual) {
        auto accumulator{0.0f};
        for (auto i = 0; i < nodes; ++i) {
            for (auto j = 0; j < nodes; ++j) {
                if(i==j) {
                    continue;
                }

            }
        }
        return 0;
    }

    void assign_hubs(const Individual &individual){
        std::map<size_t, std::vector<size_t>> assigned;
        for(auto i=0;i < individual.chromosomes_.size(); i++) {
            if(individual.chromosomes_.get_allele(i)){
                std::vector<std::vector<double>> nodes_connected(map.begin() + i*nodes, map.begin() + i*nodes + 25);
            }
        }

    }

    static double w(size_t start, size_t end) {
        return get_row(start, end)[2];
    }

    static double c(size_t start, size_t end) {
        return get_row(start, end)[3];
    }

private:
    static constexpr auto nodes = 25;

    static const std::vector<double> &get_row(size_t start, size_t end) {
        return map[(start - 1) * nodes + (end - 1)];
    }

};

#endif //P_HUB_GENETIC_ALGORITHM_PHUB_HPP
