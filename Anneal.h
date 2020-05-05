#ifndef PA04_ANNEAL_H
#define PA04_ANNEAL_H

#include <vector>
#include "graph.h"
#include <tuple>
class Anneal {
public:
    Anneal();
    std::pair<std::vector<int>, double> anneal();
private:
    double calcTotalDist(std::vector<int>&);
    std::vector<int> getRandomNeighborTour(std::vector<int>);
    std::vector<int> optimalSolution;
    std::vector<int> currSolution;
    double bestDistance;
    int temperature;
    Graph map;
};


#endif //PA04_ANNEAL_H
