#pragma once

#include <utility>
#include <vector>
#include <map>
#include <optional>
#include "Individual.hpp"
#include <execution>

class pHub {
public:
    explicit pHub(std::vector<std::vector<double>> dataset, double alpha = 1.0) : data_(std::move(dataset)),
                                                                                  n_nodes_(sqrt(dataset.size())),
                                                                                  alpha_(alpha) {
        for (auto i = 0; i < n_nodes_; ++i) {
            for (auto j = 0; j < n_nodes_; ++j) {
                flow_accum += w(i, j);
            }
        }
        for_each(std::execution::par_unseq, data_.begin(), data_.end(), [this](auto &v) {
            v[2] /= flow_accum;
        });
    }

    double calculate_fitness(const Individual &individual) {
        auto assigned_hubs = assign_hubs(individual);
        if (assigned_hubs.empty()) {
            return std::numeric_limits<double>::max();
        }
        std::vector<std::pair<size_t, size_t>> pairs;
        for (auto i = 0; i < n_nodes_; ++i) {
            for (auto j = i; j < n_nodes_; ++j) {
                pairs.emplace_back(i, j);
            }
        }

        auto accumulator{0.0};
        for_each(std::execution::seq, pairs.begin(), pairs.end(), [&](const auto &pair) {
            auto i = pair.first;
            auto j = pair.second;
            if (i != j) {
                auto in_hub = (assigned_hubs.find(i) == assigned_hubs.end()) ? i : assigned_hubs[i];
                auto out_hub = (assigned_hubs.find(j) == assigned_hubs.end()) ? j : assigned_hubs[j];

                auto inflow = w(i, j);

                auto in_cost = c(i, in_hub);
                auto hub2hub_cost = c(in_hub, out_hub);
                auto out_cost = c(out_hub, j);

                accumulator += inflow * (in_cost + alpha_ * hub2hub_cost + out_cost);
            }
        });
        return accumulator;
    }

    std::map<size_t, size_t> assign_hubs(const Individual &individual) {
        std::map<size_t, size_t> assigned_hubs;
        std::vector<size_t> hubs_indexes = individual.chromosomes_.get_genome();
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
            if (lowest_hub_idx) {
                assigned_hubs.emplace(node_idx, *lowest_hub_idx);
            }
        }
        return assigned_hubs;
    }

    double w(size_t start, size_t end) {
        return get_row(start, end)[2];
    }

    double c(size_t start, size_t end) {
        return get_row(start, end)[3];
    }

private:
    const size_t n_nodes_;
    double flow_accum;
    const double alpha_;

    std::vector<std::vector<double>> data_{};

    const std::vector<double> &get_row(size_t start, size_t end) {
        return data_[(start * n_nodes_) + end];
    }

};
