#pragma once

#include <random>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <utility>
#include <sstream>

class Chromosome {
public:
    explicit Chromosome(size_t n_genes);

    explicit Chromosome(std::vector<size_t> genes) {
        genes_ = std::move(genes);
    }

    friend bool operator==(const Chromosome &l, const Chromosome &r) {
        return l.genes_ == r.genes_;
    }

    friend bool operator!=(const Chromosome &l, const Chromosome &r) {
        return !(l == r);
    }

    void mutate(double probability) {
        for_each(genes_.begin(), genes_.end(), [&](size_t &gen) {
            std::uniform_int_distribution<> prob(0, 99);
            if (prob(generator) < probability * 100) {
                gen = generate_random_gene();
            }
        });
    }

    int generate_random_gene() {
        std::uniform_int_distribution<> distr(0, 24);
        int potential_gen{-1};
        do {
            potential_gen = distr(generator);
        } while (std::ranges::find(genes_, potential_gen) != genes_.end());
        return potential_gen;
    }

    void set_allele(size_t index, int value) {
        genes_[index] = value;
    }

    [[nodiscard]] size_t get_allele(size_t index) const {
        return genes_[index];
    }

    [[nodiscard]] size_t size() const {
        return genes_.size();
    }

    std::string get_genome_as_string() {
        std::stringstream ss;
        for_each(genes_.begin(), genes_.end(), [&](size_t allele) {
            ss << allele << ' ';
        });
        return ss.str();
    }

    [[nodiscard]] std::vector<size_t> get_genome() const {
        return genes_;
    }

private:
    std::vector<size_t> genes_;
    static std::mt19937 generator;


    void fill_with_random_genome(size_t size) {
        for (int n = 0; n < size; ++n) {
            genes_.emplace_back(generate_random_gene());
        }
    }
};
