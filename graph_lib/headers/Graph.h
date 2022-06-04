#pragma once

#include <vector>
#include <iostream>

#ifndef ALGORITHMS_HW3_GRAPH_H
#define ALGORITHMS_HW3_GRAPH_H

struct IGraph {

    virtual ~IGraph() {}

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;

    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif //ALGORITHMS_HW3_GRAPH_H
