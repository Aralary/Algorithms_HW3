//
// Created by aralary on 6/5/22.
//
#include <vector>
#include <iostream>
#include <queue>

#ifndef ALGORITHMS_HW3_GRAPH_H
#define ALGORITHMS_HW3_GRAPH_H

class Graph {
public:
    Graph(int v_count);

// Добавление ребра от from к to.
    void AddEdge(int from, int to);

    int VerticesCount() const;

    std::vector<int> GetNextVertices(int vertex) const;

    std::vector<int> GetPrevVertices(int vertex) const;

    int min_path_count(int from, int to) const;
//    void print_data() {
//        for (int i = 0; i < list_gr.size(); ++i) {
//            std::cout << i << " v has next vertexes : ";
//            for (const auto &next_v: list_gr[i]) {
//                std::cout << next_v << " ";
//            }
//            std::cout << std::endl;
//        }
//    }

private:
    std::vector<std::vector<int>> list_gr;
};

#endif //ALGORITHMS_HW3_GRAPH_H
