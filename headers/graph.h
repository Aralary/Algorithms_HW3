#include <vector>
#include <set>
#include <queue>
#include <iostream>

#ifndef ALGORITHMS_HW3_GRAPH_H
#define ALGORITHMS_HW3_GRAPH_H

class WGraph {
public:
    WGraph(int v_count);

    void AddEdge(int from, int to, int weight);

    int VerticesCount() const;

    std::set<std::pair<int, int>> GetNextVertices(int vertex) const;

    std::vector<int> GetPrevVertices(int vertex) const;

    int min_path_length(int from, int to) const;

private:
    std::vector<std::set<std::pair<int, int>>> data; // вектор множеств пар {вес, вершина куда ребро}; индексы вектора - вершины графа.
};

#endif //ALGORITHMS_HW3_GRAPH_H
