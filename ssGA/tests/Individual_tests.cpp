//
// Created by esteve on 07/07/22.
//

#include "catch2/catch.hpp"
#include "Individual.hpp"

TEST_CASE("Check mutations can happen") {
    Individual individual(4);
    individual.chromosomes_.print();
    auto before_mutation = individual.chromosomes_;
    individual.chromosomes_.mutate(0.5);
    individual.chromosomes_.print();
    REQUIRE(before_mutation != individual.chromosomes_);
}