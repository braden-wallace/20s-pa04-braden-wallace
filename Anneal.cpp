#include "Anneal.h"
#include <random>
#include <algorithm>
std::vector<int> Anneal::getRandomNeighborTour(std::vector<int> curr) {
    std::vector<std::vector<int>> temp;
    for (unsigned int i =1 ; i < curr.size()-1; i++){
        for(unsigned int j =1; j < curr.size()-1; j++){
            if(i != j) {
                std::vector<int> t = (curr);
                std::swap(t[i], t[j]);
                temp.push_back(t);
            }
        }
    }
    int p = rand() % temp.size();
    return temp[p];
}
std::pair<std::vector<int>, double> Anneal::anneal() {
    srand((unsigned)time(NULL));
    std::vector<int> starting;
    std::srand(time(NULL));
    auto rng = std::default_random_engine { };
    std::vector<int> temp;
    for(int j = 2; j <= map.getSize(); j++){
        temp.push_back(j);
    }
    std::shuffle(std::begin(temp), std::end(temp), rng);
    temp.insert(temp.begin(), 1);
    temp.push_back(1);

    currSolution = temp;
    temperature = 10000;

    int currentTemp = temperature;
    double currentEnergy = calcTotalDist(currSolution);
    int counter = 0;
    optimalSolution = currSolution;
    bestDistance = currentEnergy;
    while(currentTemp > 0 && bestDistance != (map.getSize() - 1)) {
        std::vector<int> temp = getRandomNeighborTour(currSolution);
        double newEnergy = calcTotalDist(temp);
        double randomProb = ((double)rand() / (double)RAND_MAX);
        double eulerProb = std::exp((currentEnergy - newEnergy) / currentTemp);
        if(newEnergy < currentEnergy || eulerProb - randomProb > 0) {
            currSolution = temp;
            if(newEnergy < bestDistance) {
                optimalSolution = currSolution;
                bestDistance = newEnergy;
            }
            currentEnergy = newEnergy;
        }
        counter++;
        if(counter % 100 == 0){
            currentTemp *= .999;
        }
    }
    return std::pair<std::vector<int>, double>(optimalSolution, calcTotalDist(optimalSolution));
}
double Anneal::calcTotalDist(std::vector<int>& curr) {
    double dist = 0;
    for(unsigned int i = 0; i < curr.size() - 1; i++) {
        dist += map.getDistance(curr[i], curr[i + 1]);
    }
    return dist;
}
Anneal::Anneal() {
    map.loadGraph();
}