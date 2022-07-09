#pragma once

#include <random>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <utility>

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
            //TODO: This is not real random.
            std::uniform_int_distribution<> distr(0, 99);
            if (distr(generator) < probability) {
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
    std::mt19937 generator = std::mt19937{std::random_device{}()};

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
