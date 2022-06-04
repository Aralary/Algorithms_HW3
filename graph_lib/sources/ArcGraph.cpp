#include "ArcGraph.h"

ArcGraph::ArcGraph(int v_count) : size(v_count) {

}

ArcGraph::ArcGraph(const IGraph &gr) : size(gr.VerticesCount()) {
    for (int i = 0; i < gr.VerticesCount(); ++i) {
        auto item = gr.GetNextVertices(i);
        for (int j = 0; i < item.size(); ++j) {
            ribs.emplace_back(i, item[j]);
        }
    }
}

ArcGraph::~ArcGraph() {

}

void ArcGraph::AddEdge(int from, int to) {
    ribs.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return size;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> next_v;
    for (const auto &r: ribs) {
        if (r.first == vertex) {
            next_v.push_back(r.second);
        }
    }
    return next_v;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (const auto &r: ribs) {
        if ((r.first != vertex) && (r.second == vertex)) {
            result.push_back(r.first);
        }
    }
    return result;
}
