#include "Graph.h"

#ifndef ALGORITHMS_HW3_MATRIXGRAPH_H
#define ALGORITHMS_HW3_MATRIXGRAPH_H

struct MatrixGraph : public IGraph {
public:
    MatrixGraph(const IGraph &gr);

    MatrixGraph(int v_count);

    ~MatrixGraph() override;

// Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

    void print() const {
        for (size_t i = 0; i < m_gr.size(); ++i) {
            for (size_t j = 0; j < m_gr[i].size(); ++j) {
                std::cout << m_gr[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<bool>> m_gr;
};

#endif //ALGORITHMS_HW3_MATRIXGRAPH_H
