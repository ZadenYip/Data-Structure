#include <gtest/gtest.h>

#include "graph/directed_graph.h"


class DirectedGraphTest : public ::testing::Test {
   protected:
    data_structures::DirectedGraph* directed_graph;
    ~DirectedGraphTest() override {}
    void SetUp() override {}
    void TearDown() override { delete directed_graph; }
};

TEST_F(DirectedGraphTest, AddEdge) {
    directed_graph = new data_structures::DirectedGraph(4);
    directed_graph->AddEdge(0, 1);
    directed_graph->AddEdge(0, 2);
    directed_graph->AddEdge(1, 2);
    directed_graph->AddEdge(2, 0);
    directed_graph->AddEdge(2, 3);
    directed_graph->AddEdge(3, 3);

    EXPECT_EQ(directed_graph->GetEdgeCount(), 6);
}

TEST_F(DirectedGraphTest, GetNeighbors) {
    directed_graph = new data_structures::DirectedGraph(4);
    directed_graph->AddEdge(0, 1);
    directed_graph->AddEdge(0, 2);
    directed_graph->AddEdge(1, 2);
    directed_graph->AddEdge(2, 0);
    directed_graph->AddEdge(2, 3);
    directed_graph->AddEdge(3, 3);

    std::vector<int> neighbors = directed_graph->GetNeighbors(0);
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(neighbors, expected);

    neighbors = directed_graph->GetNeighbors(1);
    expected = {2};
    EXPECT_EQ(neighbors, expected);

    neighbors = directed_graph->GetNeighbors(2);
    expected = {0, 3};
    EXPECT_EQ(neighbors, expected);

    neighbors = directed_graph->GetNeighbors(3);
    expected = {3};
    EXPECT_EQ(neighbors, expected);
}