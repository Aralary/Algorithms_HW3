#include "graph.h"

int main() {
    int v, ribs;
    std::cin >> v >> ribs;
    WGraph g(v);
    for (size_t i = 0; i < ribs; ++i) {
        int from, to, weight;
        std::cin >> from >> to >> weight;
    }
//    std::cout << "Enter from and to, to find min_path" << std::endl;
    int from, to;
    std::cin >> from >> to;
    std::cout << g.min_path_length(from, to);
}