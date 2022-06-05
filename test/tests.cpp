#include "graph.h"
#include <gtest/gtest.h>

TEST(Graph, min_path_count) {
    Graph g1(4);
    g1.AddEdge(0, 1);
    g1.AddEdge(0, 2);
    g1.AddEdge(1, 2);
    g1.AddEdge(1, 3);
    g1.AddEdge(2, 3);
    EXPECT_EQ(g1.min_path_count(0, 3), 2);

    Graph g2(8);
    g2.AddEdge(0, 1);
    g2.AddEdge(0, 4);
    g2.AddEdge(1, 2);
    g2.AddEdge(1, 5);
    g2.AddEdge(2, 3);
    g2.AddEdge(2, 5);
    g2.AddEdge(2, 6);
    g2.AddEdge(2, 7);
    g2.AddEdge(4, 5);
    g2.AddEdge(5, 6);
    g2.AddEdge(6, 7);
    EXPECT_EQ(g2.min_path_count(0, 5), 2);
    EXPECT_EQ(g2.min_path_count(5, 0), 2);
    EXPECT_EQ(g2.min_path_count(0, 6), 3);
    EXPECT_EQ(g2.min_path_count(0, 7), 1);

    EXPECT_EQ(g2.min_path_count(4, 1), 2);
    EXPECT_EQ(g2.min_path_count(4, 2), 1);
    EXPECT_EQ(g2.min_path_count(4, 3), 1);

    Graph g3(8);
    g3.AddEdge(0, 1);
    g3.AddEdge(0, 4);
    g3.AddEdge(1, 2);
    g3.AddEdge(1, 5);
    g3.AddEdge(2, 3);
//    g3.AddEdge(2, 5);
    g3.AddEdge(2, 6);
    g3.AddEdge(2, 7);
    g3.AddEdge(4, 5);
    g3.AddEdge(5, 6);
    g3.AddEdge(6, 7);

    EXPECT_EQ(g3.min_path_count(4, 1), 2);
    EXPECT_EQ(g3.min_path_count(4, 2), 3);
    EXPECT_EQ(g3.min_path_count(4, 3), 3);
}