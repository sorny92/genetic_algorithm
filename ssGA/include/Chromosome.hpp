//
// Created by esteve on 02/07/22.
//

#ifndef P_HUB_GENETIC_ALGORITHM_CHROMOSOME_H
#define P_HUB_GENETIC_ALGORITHM_CHROMOSOME_H

#include <random>
#include <bitset>

class Chromosome {
public:
    explicit Chromosome(size_t n_chromosomes);

    void set_allele(size_t index, bool value) {
        alleles_[index] = value;
    }

    [[nodiscard]] bool get_allele(size_t index) const {
        return alleles_[index];
    }

    [[nodiscard]] size_t size() const {
        return alleles_.size();
    }

private:
    std::vector<bool> alleles_;

    static std::vector<bool> random_bitset(size_t size, double p = 0.5) {
        std::vector<bool> bits;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::bernoulli_distribution d(p);

        for (int n = 0; n < size; ++n) {
            bits[n] = d(gen);
        }
        return bits;
    }
};

#endif //P_HUB_GENETIC_ALGORITHM_CHROMOSOME_H
