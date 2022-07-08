//
// Created by esteve on 07/07/22.
//

#ifndef P_HUB_GENETIC_ALGORITHM_PHUB_HPP
#define P_HUB_GENETIC_ALGORITHM_PHUB_HPP

#include <utility>
#include <vector>
#include <map>
#include <optional>
#include "Individual.hpp"

class pHub {
public:
    explicit pHub(std::vector<std::vector<double>> dataset) : data_(std::move(dataset)),
                                                              n_nodes_(sqrt(dataset.size())) {}

    double calculate_fitness(const Individual &individual) {
        auto accumulator{0.0f};
        for (auto i = 0; i < n_nodes_; ++i) {
            for (auto j = 0; j < n_nodes_; ++j) {
                if (i == j) {
                    continue;
                }

            }
        }
        return 0;
    }

    std::map<size_t, size_t> assign_hubs(const Individual &individual) {
        std::map<size_t, size_t> assigned;
        std::vector<size_t> hubs_indexes;
        for (auto i = 0; i < individual.chromosomes_.size(); i++) {
            if (individual.chromosomes_.get_allele(i)) {
                hubs_indexes.emplace_back(i);
            }
        }
        for (auto node_idx = 0; node_idx < n_nodes_; ++node_idx) {
            auto lowest_cost = std::numeric_limits<double>::max();
            auto lowest_hub_idx = std::optional<size_t>();
            if (std::find(hubs_indexes.begin(), hubs_indexes.end(), node_idx) != hubs_indexes.end()) {
                continue;
            }
            for (auto h_idx: hubs_indexes) {
                auto cost = c(node_idx, h_idx);
                if (cost < lowest_cost) {
                    lowest_cost = cost;
                    lowest_hub_idx = h_idx;
                }
            }
            assigned.emplace(node_idx, *lowest_hub_idx);
        }
        return assigned;
    }

    double w(size_t start, size_t end) {
        return get_row(start, end)[2];
    }

    double c(size_t start, size_t end) {
        return get_row(start, end)[3];
    }

private:
    const size_t n_nodes_;
    std::vector<std::vector<double>> data_{};

    const std::vector<double> &get_row(size_t start, size_t end) {
        return data_[(start * n_nodes_) + end];
    }

};

#endif //P_HUB_GENETIC_ALGORITHM_PHUB_HPP
