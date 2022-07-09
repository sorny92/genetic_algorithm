//
// Created by esteve on 09/07/22.
//

#include "Algorithm.hpp"
#include "pHub/include/dataset.hpp"

int main(int argc, char *argv[]) {
    // args: n_iter individuals gnome_length prob_cross prob_muta
    for(auto i=1;i<argc; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    pHub problem(phub_data, 1);
    ssGA algorithm(problem, atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]));

    size_t n_iterations{static_cast<size_t>(atoi(argv[1]))};

    for(auto i=0; i < n_iterations; ++i){
        algorithm.fit_population();
        algorithm.print_statistics();
        algorithm.next_step();
    }

}