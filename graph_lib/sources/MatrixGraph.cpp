#include "MatrixGraph.h"

void MatrixGraph::AddEdge(int from, int to) {
    m_gr[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return m_gr.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> next_vers;
    for (int i = 0; i < m_gr.size(); ++i) {
        if (m_gr[vertex][i]) {
            next_vers.push_back(i);
        }
    }
    return next_vers;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < m_gr.size(); ++i) {
        if ((i != vertex) && m_gr[i][vertex]) {
            result.push_back(i);
        }
    }
    return result;
}

MatrixGraph::MatrixGraph(int v_count) : m_gr(v_count) {
    for (int i = 0; i < v_count; ++i) {
        m_gr[i] = std::vector<bool>(v_count);
    }
}

MatrixGraph::MatrixGraph(const IGraph &gr) : m_gr(gr.VerticesCount()) {
    for (int i = 0; i < gr.VerticesCount(); ++i) {
        auto temp = gr.GetNextVertices(i);
        m_gr[i] = std::vector<bool>(gr.VerticesCount());
        for (int j = 0; j < temp.size(); ++j) {
            m_gr[i][temp[j]] = true;
        }
    }
}

MatrixGraph::~MatrixGraph() {

}
