#include "ListGraph.h"

ListGraph::ListGraph(int v_count) : list_gr(v_count) {}

ListGraph::ListGraph(const IGraph &gr) : list_gr(gr.VerticesCount()) {
    for (int i = 0; i < gr.VerticesCount(); ++i) {
        list_gr[i] = gr.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(int from, int to) {
    list_gr[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return list_gr.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return list_gr[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < list_gr.size(); ++i) {
        if (i == vertex) {
            continue;
        } else {
            for (int j = 0; j < list_gr[i].size(); ++i) {
                if (list_gr[i][j] == vertex) {
                    result.push_back(i);
                }
            }
        }
    }
    return result;
}

ListGraph::~ListGraph() {

}
