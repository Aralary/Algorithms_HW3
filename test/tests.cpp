#include <gtest/gtest.h>
#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"
#include <set>

template<typename T>
std::set<T> get_set(const std::vector<T> &vec){
    std::set<T> res;
    for(const auto& i : vec){
        res.insert(i);
    }
    return res;
}

TEST(ListGraph, methods) {
    ListGraph gr(6);
    gr.AddEdge(0, 1);
    gr.AddEdge(0, 4);
    gr.AddEdge(0, 3);
    gr.AddEdge(2, 1);
    gr.AddEdge(3, 1);
    gr.AddEdge(3, 4);
    gr.AddEdge(4, 2);
    gr.AddEdge(4, 3);
    gr.AddEdge(5, 3);
    EXPECT_EQ(gr.VerticesCount(), 6);
    EXPECT_EQ(gr.GetNextVertices(4), std::vector<int>({2, 3}));
    EXPECT_EQ(gr.GetNextVertices(1), std::vector<int>());
    EXPECT_EQ(gr.GetPrevVertices(3), std::vector<int>({0, 4, 5}));
}

TEST(MatrixGraph, methods) {
    MatrixGraph gr(6);
    gr.AddEdge(0, 1);
    gr.AddEdge(0, 4);
    gr.AddEdge(0, 3);
    gr.AddEdge(2, 1);
    gr.AddEdge(3, 1);
    gr.AddEdge(3, 4);
    gr.AddEdge(4, 2);
    gr.AddEdge(4, 3);
    gr.AddEdge(5, 3);
    EXPECT_EQ(gr.VerticesCount(), 6);
    EXPECT_EQ(gr.GetNextVertices(4), std::vector<int>({2, 3}));
    EXPECT_EQ(gr.GetNextVertices(1), std::vector<int>());
    EXPECT_EQ(gr.GetPrevVertices(3), std::vector<int>({0, 4, 5}));
}

TEST(SetGraph, methods) {
    SetGraph gr(6);
    gr.AddEdge(0, 1);
    gr.AddEdge(0, 4);
    gr.AddEdge(0, 3);
    gr.AddEdge(2, 1);
    gr.AddEdge(3, 1);
    gr.AddEdge(3, 4);
    gr.AddEdge(4, 2);
    gr.AddEdge(4, 3);
    gr.AddEdge(5, 3);
    EXPECT_EQ(gr.VerticesCount(), 6);
    EXPECT_EQ(gr.GetNextVertices(4), std::vector<int>({3, 2}));
    EXPECT_EQ(gr.GetNextVertices(1), std::vector<int>());
    EXPECT_EQ(gr.GetPrevVertices(3), std::vector<int>({0, 4, 5}));
}

TEST(ArcGraph, methods) {
    ArcGraph gr(6);
    gr.AddEdge(0, 1);
    gr.AddEdge(0, 4);
    gr.AddEdge(0, 3);
    gr.AddEdge(2, 1);
    gr.AddEdge(3, 1);
    gr.AddEdge(3, 4);
    gr.AddEdge(4, 2);
    gr.AddEdge(4, 3);
    gr.AddEdge(5, 3);
    EXPECT_EQ(gr.VerticesCount(), 6);
    EXPECT_EQ(gr.GetNextVertices(4), std::vector<int>({2, 3}));
    EXPECT_EQ(gr.GetNextVertices(1), std::vector<int>());
    EXPECT_EQ(gr.GetPrevVertices(3), std::vector<int>({0, 4, 5}));
}

TEST(Graphs, copy_constructors) {
    ListGraph gr(6);
    gr.AddEdge(0, 1);
    gr.AddEdge(0, 4);
    gr.AddEdge(0, 3);
    gr.AddEdge(2, 1);
    gr.AddEdge(3, 1);
    gr.AddEdge(3, 4);
    gr.AddEdge(4, 2);
    gr.AddEdge(4, 3);
    gr.AddEdge(5, 3);

    MatrixGraph m_gr(gr);
    EXPECT_EQ(get_set(m_gr.GetNextVertices(1)), get_set(gr.GetNextVertices(1)));
    EXPECT_EQ(get_set(m_gr.GetNextVertices(4)), get_set(gr.GetNextVertices(4)));
    EXPECT_EQ(get_set(m_gr.GetNextVertices(0)), get_set(gr.GetNextVertices(0)));
    EXPECT_EQ(get_set(m_gr.GetPrevVertices(1)), get_set(gr.GetPrevVertices(1)));

    ArcGraph arcGraph(m_gr);
    EXPECT_EQ(get_set(m_gr.GetNextVertices(1)), get_set(arcGraph.GetNextVertices(1)));
    EXPECT_EQ(get_set(m_gr.GetNextVertices(4)), get_set(arcGraph.GetNextVertices(4)));
    EXPECT_EQ(get_set(m_gr.GetNextVertices(0)), get_set(arcGraph.GetNextVertices(0)));
    EXPECT_EQ(get_set(m_gr.GetPrevVertices(1)), get_set(arcGraph.GetPrevVertices(1)));

    SetGraph s_gr(arcGraph);
    EXPECT_EQ(get_set(s_gr.GetNextVertices(1)), get_set(arcGraph.GetNextVertices(1)));
    EXPECT_EQ(get_set(s_gr.GetNextVertices(4)), get_set(arcGraph.GetNextVertices(4)));
    EXPECT_EQ(get_set(s_gr.GetNextVertices(0)), get_set(arcGraph.GetNextVertices(0)));
    EXPECT_EQ(get_set(s_gr.GetPrevVertices(1)), get_set(arcGraph.GetPrevVertices(1)));
}