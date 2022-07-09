#pragma once

#include <random>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <utility>
#include <sstream>

class Chromosome {
public:
    explicit Chromosome(size_t n_chromosomes);

    explicit Chromosome(std::vector<bool> alleles) {
        alleles_ = std::move(alleles);
    }

    friend bool operator==(const Chromosome &l, const Chromosome &r) {
        return l.alleles_ == r.alleles_;
    }

    friend bool operator!=(const Chromosome &l, const Chromosome &r) {
        return !(l == r);
    }

    void mutate(double probability) {
        for_each(alleles_.begin(), alleles_.end(), [&](decltype(alleles_)::reference allele) {
            std::uniform_int_distribution<> distr(0, 99);
            if (distr(generator) < probability*100) {
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

    std::string get_genome() {
        std::stringstream ss;
        for_each(alleles_.begin(), alleles_.end(), [&](bool allele) {
            ss << (allele ? '1' : '0');
        });
        return ss.str();
    }

private:
    std::vector<bool> alleles_;
    static std::mt19937 generator;



    static std::vector<bool> random_bitset(size_t size, double p = 0.5) {
        std::vector<bool> bits(size);
        std::bernoulli_distribution d(p);

        for (int n = 0; n < size; ++n) {
            bits[n] = d(generator);
        }
        return bits;
    }
};
