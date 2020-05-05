#include "BruteForce.h"
#include <limits>
#include <algorithm>
std::pair<std::vector<int>, double> BruteForce::run() {
    std::vector<int> cities;
    for (int i = 2; i <= map.getSize(); i++){
        cities.push_back(i);
    }
    double minDistance = std::numeric_limits<double>::max();
    do {
        double currDistance = 0;
        int currCity = 1;
        for (unsigned int i = 0; i < cities.size(); i++) {
            currDistance += map.getDistance(currCity, cities[i]);
            currCity = cities[i];
        }
        currDistance += map.getDistance(currCity, 1);
        if(minDistance > currDistance) {
            optimalSolution = cities;
            minDistance = currDistance;
        }
    } while (next_permutation(cities.begin(), cities.end()));
    optimalSolution.insert(optimalSolution.begin(), 1);
    optimalSolution.push_back(1);
    return std::pair<std::vector<int>, double>(optimalSolution, minDistance);
}
BruteForce::BruteForce() {
    map.loadGraph();
}