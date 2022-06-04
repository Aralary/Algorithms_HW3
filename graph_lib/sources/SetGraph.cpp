#include "SetGraph.h"

SetGraph::SetGraph(int v_count) : ht_gr(v_count) {

}

SetGraph::SetGraph(const IGraph &gr) : ht_gr(gr.VerticesCount()) {
    for (int i = 0; i < ht_gr.size(); ++i) {
        auto temp = gr.GetNextVertices(i);
        for (const auto &j: temp) {
            ht_gr[i].insert(j);
        }
    }
}

SetGraph::~SetGraph() {

}

void SetGraph::AddEdge(int from, int to) {
    ht_gr[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return ht_gr.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> next_v;
    for (const auto &i: ht_gr[vertex]) {
        next_v.push_back(i);
    }
    return next_v;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < ht_gr.size(); ++i) {
        if ((i != vertex) && (ht_gr[i].count(vertex) != 0)) {
            result.push_back(i);
        }
    }
    return result;
}
