#include "graph.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
std::string Graph::graphFile = "";
void Graph::loadGraph() {
    std::ifstream inFile(graphFile);
    if(!inFile) {
        std::cerr << " CANNOT OPEN FILE" << std::endl;
        exit(1);
    }
    std::string line;
    while(std::getline(inFile, line)) {
        if(line[line.length() - 1] == '\r') {
            line.pop_back();
        }
        std::string vertex, x, y;
        std::stringstream ss(line);

        std::getline(ss, vertex, '-');
        std::getline(ss, x, '-');
        std::getline(ss, y);
        vertex.erase(vertex.length()-1, 1);
        x.erase(x.length()-1, 1);
        x.erase(0, 1);
        y.erase(0, 1);
        int a = std::stoi(vertex);
        int b = std::stoi(x);
        int c = std::stoi(y);
        Node n;
        n.city = a;
        n.x = b;
        n.y = c;
        cities.push_back(n);
    }
    size = cities.size();
    matrix = new double*[size];
    for(int i = 0; i < size; i++) {
        matrix[i] = new double[size];
        for(int j = 0; j < size; j++) {
            if(i != j) {
                matrix[i][j] = sqrt(pow(cities[i].x - cities[j].x, 2) + pow(cities[i].y - cities[j].y, 2));
            } else {
                matrix[i][j] = -1;
            }
        }
    }
}
double Graph::getDistance(int a, int b) {
    if(a > 0 && b > 0) {
        double d = matrix[a-1][b-1];
        return d;
    } else {
        return -1;
    }
}
int Graph::getSize() {
    return size;
}
Graph::~Graph() {
    if(matrix != nullptr) {
        for(int i = 0; i < size; i++) {
            if(matrix[i] != nullptr) {
                delete[] matrix[i];
            }
        }
        delete[] matrix;
    }
}
void Graph::setFile(std::string f) {
    graphFile = f;
}
