#include "graph.h"
#include <gtest/gtest.h>

TEST(WGraph, dijkstra) {
    WGraph g1(6);
    g1.AddEdge(0, 3, 1);
    g1.AddEdge(0, 4, 2);
    g1.AddEdge(1, 2, 7);
    g1.AddEdge(1, 3, 2);
    g1.AddEdge(1, 4, 3);
    g1.AddEdge(1, 5, 3);
    g1.AddEdge(2, 5, 3);
    g1.AddEdge(3, 4, 4);
    g1.AddEdge(3, 5, 6);
    EXPECT_EQ(g1.min_path_length(0, 2), 9);
    EXPECT_EQ(g1.min_path_length(3, 5), 5);
    EXPECT_EQ(g1.min_path_length(3, 4), 3);

    WGraph g2(7);
    g2.AddEdge(0, 2, 2);
    g2.AddEdge(0, 4, 3);
    g2.AddEdge(0, 5, 5);
    g2.AddEdge(0, 6, 2);
    g2.AddEdge(1, 2, 1);
    g2.AddEdge(1, 3, 1);
    g2.AddEdge(1, 6, 6);
    g2.AddEdge(2, 3, 3);
    g2.AddEdge(3, 4, 3);
    g2.AddEdge(4, 5, 4);
    g2.AddEdge(4, 6, 4);
    EXPECT_EQ(g2.min_path_length(2, 4), 5);
    EXPECT_EQ(g2.min_path_length(6, 3), 6);
    EXPECT_EQ(g2.min_path_length(0, 1), 3);
    EXPECT_EQ(g2.min_path_length(5, 6), 7);
    EXPECT_EQ(g2.min_path_length(6, 2), 4);
    EXPECT_EQ(g2.min_path_length(6, 1), 5);
    EXPECT_EQ(g2.min_path_length(6, 3), 6);
}