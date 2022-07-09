//
// Created by esteve on 09/07/22.
//

#include "Algorithm.hpp"
#include "pHub/include/dataset.hpp"

int main(int argc, char *argv[]) {
    pHub problem(phub_data, 1);
    ssGA algorithm(problem, 25, 25, 0.5, 0.5);

    size_t n_iterations{15000};

    for(auto i=0; i < n_iterations; ++i){
        algorithm.fit_population();
        algorithm.print_statistics();
        algorithm.next_step();
    }

}