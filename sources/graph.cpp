#include "graph.h"

WGraph::WGraph(int v_count) : data(v_count) {

}

void WGraph::AddEdge(int from, int to, int weight) {
    data[from].emplace(weight, to);
    data[to].emplace(weight, from);
}

int WGraph::VerticesCount() const {
    return data.size();
}

std::set<std::pair<int, int>> WGraph::GetNextVertices(int vertex) const {
    return data[vertex];
}

std::vector<int> WGraph::GetPrevVertices(int vertex) const {
    std::vector<int> res;
    for (int i = 0; i < data.size(); ++i) {
        for (const auto &p: data[i]) {
            if (p.first == vertex) {
                res.push_back(i);
            }
        }
    }
    return res;
}

int WGraph::min_path_length(int from, int to) const {
    std::vector<int> d(data.size()); // длины кратчайших путей в вершины по индексам
    std::vector<int> p(data.size()); // предыдущие узлы
    std::vector<bool> visited(data.size(), false);
    std::set<std::pair<int, int>> temp_ribs = GetNextVertices(from); // вес, куда
    for (const auto &i: temp_ribs) {
        d[i.second] = i.first;
        p[i.second] = from;
        visited[i.second] = true;
    }
    visited[from] = true;
    d[from] = 0;
    p[from] = -1;

    //to see the length of path from 'from' to each v before alg
//    std::cout << "from = " << from << " before" << std::endl;
//    for(const auto& i : d){
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;

    while (!temp_ribs.empty()) {
        auto temp_rib = *temp_ribs.begin();
        temp_ribs.erase(temp_rib);
        visited[temp_rib.second] = true;
        for (const auto &i: data[temp_rib.second]) {
            if (!visited[i.second]) {
                visited[i.second] = true;
                temp_ribs.insert(i);
                p[i.second] = temp_rib.second;
                d[i.second] = d[temp_rib.second] + i.first;
            } else {
                if (d[i.second] > (d[temp_rib.second] + i.first)) {
                    p[i.second] = temp_rib.second;
                    d[i.second] = (d[temp_rib.second] + i.first);
                }
            }
        }
    }

    //to see the length of path from 'from' to each v after alg
//    std::cout << "from = " << from << " after"<< std::endl;
//    for(const auto& i : d){
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
    return d[to];
}
