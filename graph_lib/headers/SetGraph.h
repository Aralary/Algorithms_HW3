#include "Graph.h"
#include <unordered_set>

#ifndef ALGORITHMS_HW3_SETGRAPH_H
#define ALGORITHMS_HW3_SETGRAPH_H

struct SetGraph : public IGraph {
public:
    SetGraph(int v_count);

    SetGraph(const IGraph &gr);

    ~SetGraph() override;

// Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

//    void print_data() {
//        for (int i = 0; i < ht_gr.size(); ++i) {
//            std::cout << i << " v has next vertexes : ";
//            for (const auto &next_v: ht_gr[i]) {
//                std::cout << next_v << " ";
//            }
//            std::cout << std::endl;
//        }
//    }

private:
    std::vector<std::unordered_set<int>> ht_gr;
};

#endif //ALGORITHMS_HW3_SETGRAPH_H
