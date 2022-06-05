#include "graph.h"

int main() {
    int v, ribs;
//    std::cout << "enter v count and ribs count " << std::endl;
    std::cin >> v >> ribs;
    Graph g(v);
//    std::cout << "enter ribs like 'from' 'to'" << std::endl;
    for (size_t i = 0; i < ribs; ++i) {
        int from, to;
        std::cin >> from >> to;
        g.AddEdge(from, to);
    }
//    std::cout << "enter 'from' and 'to' to find path count" << std::endl;
    int from, to;
    std::cin >> from >> to;
    std::cout << g.min_path_count(from, to);
}