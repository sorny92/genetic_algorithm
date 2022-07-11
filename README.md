## Steady State Genetic Algorithm
Steady state genetic algorithm implementation based on [ssGA: Steady State GA](https://neo.lcc.uma.es/software/ssga/index.php)

This program currently solves the single-HLP problem using this dataset: [Dataset](http://people.brunel.ac.uk/~mastjjb/jeb/orlib/files/phub4.txt)

More information of the problem here:
http://people.brunel.ac.uk/~mastjjb/jeb/orlib/phubinfo.html


## Dependencies
* A c++20 compatible compiler

## How to build
```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make main
```

## How to run
```bash
./main n_iter individuals genome_length prob_crossover prob_mutatation
```

## Example output
```bash
./main 20 25 4 1 1
20 25 4 1 1 
Iter 1: Best: 6->1297.657  || Worst: 4->2020.210  || Avg_fitness: 1452.981  || Best_genome: 13 20 24 3 
Iter 2: Best: 5->1297.657  || Worst: 11->1719.176  || Avg_fitness: 1426.964  || Best_genome: 13 20 24 3 
Iter 3: Best: 5->1297.657  || Worst: 2->1583.650  || Avg_fitness: 1411.371  || Best_genome: 13 20 24 3 
Iter 4: Best: 4->1297.657  || Worst: 2->1574.990  || Avg_fitness: 1404.972  || Best_genome: 13 20 24 3 
Iter 5: Best: 3->1297.657  || Worst: 24->1573.725  || Avg_fitness: 1404.921  || Best_genome: 13 20 24 3 
Iter 6: Best: 3->1297.657  || Worst: 5->1517.710  || Avg_fitness: 1398.020  || Best_genome: 13 20 24 3 
Iter 7: Best: 3->1297.657  || Worst: 14->1507.749  || Avg_fitness: 1392.360  || Best_genome: 13 20 24 3 
Iter 8: Best: 3->1297.657  || Worst: 24->1946.096  || Avg_fitness: 1409.894  || Best_genome: 13 20 24 3 
Iter 9: Best: 3->1297.657  || Worst: 4->1500.924  || Avg_fitness: 1388.105  || Best_genome: 13 20 24 3 
Iter 10: Best: 3->1297.657  || Worst: 9->1500.544  || Avg_fitness: 1383.441  || Best_genome: 13 20 24 3 
Iter 11: Best: 3->1297.657  || Worst: 7->1477.293  || Avg_fitness: 1381.895  || Best_genome: 13 20 24 3 
Iter 12: Best: 3->1297.657  || Worst: 24->1491.890  || Avg_fitness: 1382.479  || Best_genome: 13 20 24 3 
Iter 13: Best: 24->1269.274  || Worst: 15->1473.233  || Avg_fitness: 1373.575  || Best_genome: 0 4 7 17 
Iter 14: Best: 23->1269.274  || Worst: 22->1461.898  || Avg_fitness: 1369.627  || Best_genome: 0 4 7 17 
Iter 15: Best: 22->1269.274  || Worst: 8->1449.864  || Avg_fitness: 1367.556  || Best_genome: 0 4 7 17 
Iter 16: Best: 21->1269.274  || Worst: 4->1433.818  || Avg_fitness: 1365.575  || Best_genome: 0 4 7 17 
Iter 17: Best: 20->1269.274  || Worst: 15->1423.660  || Avg_fitness: 1364.234  || Best_genome: 0 4 7 17 
Iter 18: Best: 19->1269.274  || Worst: 21->1410.136  || Avg_fitness: 1362.956  || Best_genome: 0 4 7 17 
Iter 19: Best: 19->1269.274  || Worst: 24->1486.637  || Avg_fitness: 1366.016  || Best_genome: 0 4 7 17 
Iter 20: Best: 19->1269.274  || Worst: 24->1404.928  || Avg_fitness: 1362.747  || Best_genome: 0 4 7 17 
```
 
