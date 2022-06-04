#include "Graph.h"

#ifndef ALGORITHMS_HW3_LISTGRAPH_H
#define ALGORITHMS_HW3_LISTGRAPH_H

struct ListGraph : public IGraph {
public:
    ListGraph(int v_count);

    ListGraph(const IGraph &gr);

    ~ListGraph() override;

// Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

    void print_data() {
        for (int i = 0; i < list_gr.size(); ++i) {
            std::cout << i << " v has next vertexes : ";
            for (const auto &next_v: list_gr[i]) {
                std::cout << next_v << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<int>> list_gr;
};

#endif //ALGORITHMS_HW3_LISTGRAPH_H
