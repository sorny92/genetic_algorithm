//
// Created by esteve on 07/07/22.
//

#include "catch2/catch.hpp"

#include "phub.hpp"
#include <dataset.hpp>

const std::vector<std::vector<double>> mock_data = {{0, 0, 0,    0},
                                                    {0, 1, 6469, 576.9631},
                                                    {0, 2, 300,  946.4954},
                                                    {1, 0, 6469, 576.9631},
                                                    {1, 1, 0,    0.0},
                                                    {1, 2, 7629, 800.0},
                                                    {2, 0, 300,  946.4954},
                                                    {2, 1, 7629, 800.0},
                                                    {2, 2, 0,    0.0}};

TEST_CASE("Getting values from dataset") {
    pHub problem(mock_data);
    REQUIRE(problem.w(0, 1) == map[1][2]);
    REQUIRE(problem.c(0, 1) == map[1][3]);

    REQUIRE(problem.w(1, 1) == map[26][2]);
    REQUIRE(problem.c(1, 1) == map[26][3]);
}

TEST_CASE("Hub assign test") {
    Individual i(25);
    i.chromosomes_.print();
    pHub problem(map);
    problem.assign_hubs(i);
    auto connections = problem.get_assigned_hubs();
    for (auto c: connections) {
        std::cout << c.first << ' ' << c.second << std::endl;
    }
}


TEST_CASE("Fitness function") {
    Individual i(3);
    i.chromosomes_.print();
    pHub problem(mock_data);
    problem.assign_hubs(i);
    auto connections = problem.get_assigned_hubs();
    for (auto c: connections) {
        std::cout << c.first << ' ' << c.second << std::endl;
    }
    std::cout << problem.calculate_fitness(i) << std::endl;

}

TEST_CASE("Maximum fitness") {

    Individual i(3);
    i.set_genetic_code(Chromosome({false, false, false}));
    i.chromosomes_.print();
    pHub problem(mock_data);
    problem.assign_hubs(i);
    auto connections = problem.get_assigned_hubs();
    for (auto c: connections) {
        std::cout << c.first << ' ' << c.second << std::endl;
    }
    auto fitness = problem.calculate_fitness(i);
    std::cout << fitness << std::endl;
    REQUIRE(fitness == std::numeric_limits<double>::max());
}