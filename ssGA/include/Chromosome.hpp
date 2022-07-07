//
// Created by esteve on 02/07/22.
//

#ifndef P_HUB_GENETIC_ALGORITHM_CHROMOSOME_H
#define P_HUB_GENETIC_ALGORITHM_CHROMOSOME_H

#include <random>
#include <bitset>
#include <algorithm>
#include <iostream>

class Chromosome {
public:
    explicit Chromosome(size_t n_chromosomes);

    friend bool operator==(const Chromosome &l, const Chromosome &r) {
        return l.alleles_ == r.alleles_;
    }

    friend bool operator!=(const Chromosome &l, const Chromosome &r) {
        return !(l == r);
    }

    void mutate() {
        for_each(alleles_.begin(), alleles_.end(), [this](decltype(alleles_)::reference allele) {
            //TODO: This is not real random.
            auto random_number = (rand() % 100) / 100.0f;
            if (random_number < (1.0f / alleles_.size())) {
                allele = !allele;
            }
        });
    }

    void set_allele(size_t index, bool value) {
        alleles_[index] = value;
    }

    [[nodiscard]] bool get_allele(size_t index) const {
        return alleles_[index];
    }

    [[nodiscard]] size_t size() const {
        return alleles_.size();
    }

    void print() {
        for_each(alleles_.begin(), alleles_.end(), [&](bool allele) {
            std::cout << (allele ? '1' : '0');
        });
        std::cout << std::endl;
    }

private:
    std::vector<bool> alleles_;

    static std::vector<bool> random_bitset(size_t size, double p = 0.5) {
        std::vector<bool> bits(size);
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
