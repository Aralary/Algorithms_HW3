#include "Graph.h"
#include <set>

#ifndef ALGORITHMS_HW3_ARCGRAPH_H
#define ALGORITHMS_HW3_ARCGRAPH_H

struct ArcGraph : public IGraph {
public:
    ArcGraph(int v_count);

    ArcGraph(const IGraph &gr);

    ~ArcGraph() override;

// Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> ribs; //from -> to
    int size = 0;
};

#endif //ALGORITHMS_HW3_ARCGRAPH_H
