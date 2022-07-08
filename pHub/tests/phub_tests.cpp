//
// Created by esteve on 07/07/22.
//

#include "catch2/catch.hpp"

#include "phub.hpp"
#include <dataset.hpp>

TEST_CASE("Getting values from dataset") {
    const std::vector<std::vector<double>> map = {{0, 0, 0, 0},
                                                  {0, 1, 6469, 576.9631},
                                                  {0, 2, 7629, 946.4954},
                                                  {1, 0, 6469, 576.9631},
                                                  {1, 1, 0   , 0.0},
                                                  {1, 2, 7629, 800.0},
                                                  {2, 0, 7629, 946.4954},
                                                  {2, 1, 7629, 800.0},
                                                  {2, 2, 0   , 0.0}};
    pHub problem(map);
    REQUIRE(problem.w(0, 1) == map[1][2]);
    REQUIRE(problem.c(0, 1) == map[1][3]);

    REQUIRE(problem.w(1, 1) == map[26][2]);
    REQUIRE(problem.c(1, 1) == map[26][3]);
}

TEST_CASE("Hub assign test") {
    const std::vector<std::vector<double>> mock_data = {{0, 0, 0, 0},
                                                  {0, 1, 6469, 576.9631},
                                                  {0, 2, 7629, 946.4954},
                                                  {1, 0, 6469, 576.9631},
                                                  {1, 1, 0   , 0.0},
                                                  {1, 2, 7629, 800.0},
                                                  {2, 0, 7629, 946.4954},
                                                  {2, 1, 7629, 800.0},
                                                  {2, 2, 0   , 0.0}};
    Individual i(25);
    i.chromosomes_.print();
    pHub problem(map);
    auto connections = problem.assign_hubs(i);
    for(auto c : connections){
        std::cout << c.first << ' ' << c.second << std::endl;
    }

}