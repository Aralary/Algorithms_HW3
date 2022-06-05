#include "graph.h"

Graph::Graph(int v_count) : list_gr(v_count) {

}

void Graph::AddEdge(int from, int to) {
    list_gr[from].push_back(to);
    list_gr[to].push_back(from);
}

int Graph::VerticesCount() const {
    return list_gr.size();
}

std::vector<int> Graph::GetNextVertices(int vertex) const {
    return list_gr[vertex];
}

std::vector<int> Graph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < list_gr.size(); ++i) {
        if (i == vertex) {
            continue;
        } else {
            for (int j = 0; j < list_gr[i].size(); ++j) {
                if (list_gr[i][j] == vertex) {
                    result.push_back(i);
                }
            }
        }
    }
    return result;
}

int Graph::min_path_count(int from, int to) const {
    std::vector<bool> visited(list_gr.size(), false);
    std::queue<int> q;
    std::vector<int> d(list_gr.size()); // длины путей из начальной в остальные
    std::vector<int> p(list_gr.size()); // перыдущие вершины для индексных
    std::vector<int> k(list_gr.size(),0); // количество мин путей
    d[from] = 0;
    p[from] = -1;
    k[from] = 1;
    q.push(from);
    visited[from] = true;
    while (!q.empty()) {
        int temp_v = q.front();
        q.pop();
        for (const auto &v: list_gr[temp_v]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                p[v] = temp_v; // прерыдущая вершина
                d[v] = d[temp_v] + 1; // длина пути до этой
                k[v] = k[temp_v];
            } else {
                if(d[v] > d[temp_v] + 1){
                    p[v] = temp_v; // прерыдущая вершина
                    d[v] = d[temp_v] + 1; // длина пути до этой
                    k[v] = k[temp_v];
                }
                if(d[v] == d[temp_v] + 1){
                    k[v] += k[temp_v];
                }
            }
        }
    }
    return k[to];
}
