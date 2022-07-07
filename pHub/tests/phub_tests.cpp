//
// Created by esteve on 07/07/22.
//

#include "catch2/catch.hpp"

#include "phub.hpp"
#include "dataset.hpp"

TEST_CASE("Getting values from dataset") {
    pHub problem;
    REQUIRE(problem.w(1,1)==map[0][2]);
    REQUIRE(problem.c(1,1)==map[0][3]);

    REQUIRE(problem.w(25,1)==map[600][2]);
    REQUIRE(problem.c(25,1)==map[600][3]);

}