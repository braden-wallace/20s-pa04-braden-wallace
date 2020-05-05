#include <iostream>
#include "Anneal.h"
#include "BruteForce.h"
#include "graph.h"
#include <chrono>
#include <fstream>

int main() {
    int totalTime = 0;
    std::vector<std::string> names = {"data/input1.txt", "data/input2.txt", "data/input3.txt", "data/input4.txt", "data/input5.txt", "data/input6.txt", "data/input7.txt" };
    std::ofstream pout("output/PathOutput.txt");
    std::ofstream tout("output/TimingOutput.txt");
    tout << "Simulated Annealing Time," << "Brute Force Time," << "# cities" << '\n';
    std::vector<std::pair<std::vector<int>, double>> annealRes = { };//first in pair is path and second is weight
    std::vector<std::pair<std::vector<int>, double>> bruteRes = { };//first in pair is path and second is weight
    unsigned int index = 0;
    while(index < names.size()) {
        Graph::graphFile = names[index];
        Anneal a;
        auto start1 = std::chrono::high_resolution_clock::now();
        auto res1 = a.anneal();
        auto stop1 = std::chrono::high_resolution_clock::now();
        annealRes.push_back(res1);
        auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
        tout << duration1.count() << ',';
        totalTime += duration1.count();
        if (index <= 4){
            BruteForce b;
            auto start2 = std::chrono::high_resolution_clock::now();
            auto res2 = b.run();
            auto stop2 = std::chrono::high_resolution_clock::now();
            bruteRes.push_back(res2);
            auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
            tout << duration2.count() << ',';
            totalTime += duration2.count();
        } else {
            tout << ',';
        }
        tout << (res1.first.size() - 1);
        tout << '\n';
        index++;
    }
    pout << "Simulate Annealing Paths:" << '\n';
    for(unsigned int i = 0; i < annealRes.size(); i++) {
        pout << "\tWeight: " << annealRes[i].second << "; Path: ";
        for(unsigned int j = 0; j < annealRes[i].first.size(); j++) {
            pout << annealRes[i].first[j] << " ";
        }
        pout << '\n';
    }
    pout << "Brute Force Paths:" << '\n';
    for(unsigned int i = 0; i < bruteRes.size(); i++) {
        pout << "\tWeight: " << bruteRes[i].second << "; Path: ";
        for(unsigned int j = 0; j < bruteRes[i].first.size(); j++) {
            pout << bruteRes[i].first[j] << " ";
        }
        pout << '\n';
    }
    tout.close();
    pout.close();
    std::cout << "Total Execution Time is: " << totalTime << " microseconds"<< std::endl;

    return 0;
}

