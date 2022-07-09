//
// Created by esteve on 07/07/22.
//

#include "catch2/catch.hpp"
#include "Individual.hpp"

TEST_CASE("Check mutations can happen") {
    Individual individual(4);
    std::cout << individual.chromosomes_.get_genome_as_string() << std::endl;
    auto before_mutation = individual.chromosomes_;
    individual.chromosomes_.mutate(0.25);
    std::cout << individual.chromosomes_.get_genome_as_string() << std::endl;
    REQUIRE(before_mutation != individual.chromosomes_);
}