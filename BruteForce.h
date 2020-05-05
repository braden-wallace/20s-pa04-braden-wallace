#ifndef PA04_BRUTEFORCE_H
#define PA04_BRUTEFORCE_H

#include "graph.h"
#include <vector>
#include <tuple>
class BruteForce {
public:
    BruteForce();
    std::pair<std::vector<int>, double> run();
private:
    Graph map;
    std::vector<int> optimalSolution = { };
};


#endif //PA04_BRUTEFORCE_H
