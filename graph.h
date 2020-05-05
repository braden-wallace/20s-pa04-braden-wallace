#ifndef PA04_GRAPH_H
#define PA04_GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <map>
class Graph {
public:
    struct Node {
        int city;
        int x;
        int y;
    };
    double getDistance(int, int);
    int getSize();
    void loadGraph();
    static std::string graphFile;
    ~Graph();
    static void setFile(std::string);
private:
    std::vector<Node> cities = { };
    double** matrix = nullptr;
    int size = 0;
};

#endif //PA04_GRAPH_H
