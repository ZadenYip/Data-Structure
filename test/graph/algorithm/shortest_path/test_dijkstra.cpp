#include <stack>
#define ENABLE_TESTING
#include "graph/shortest_path/dijkstra.h"
#include "gtest/gtest.h"

namespace data_structures {
class DijkstraTest : public ::testing::Test {
   protected:
    data_structures::DirectedGraph* directed_graph;
    data_structures::Dijkstra* dijkstra;

    void SetUp() override {
        directed_graph = new data_structures::DirectedGraph(5);
        auto comparator = [](const data_structures::Edge& edge1,
                             const data_structures::Edge& edge2) -> bool {
            return edge1.GetWeight() > edge2.GetWeight();
        };
        directed_graph->AddEdge(0, 1, 2);
        directed_graph->AddEdge(0, 2, 5);
        directed_graph->AddEdge(0, 4, 1);
        directed_graph->AddEdge(1, 3, 5);
        directed_graph->AddEdge(2, 1, 3);
        directed_graph->AddEdge(4, 2, 7);
        dijkstra = new data_structures::Dijkstra(*directed_graph, comparator);
    }

    void TearDown() override {
        delete directed_graph;
        delete dijkstra;
    }
};

TEST_F(DijkstraTest, Source0Distance) {
    dijkstra->ExecuteAlgorithm(0);
    EXPECT_EQ(dijkstra->GetDistanceTo(0), 0);
    EXPECT_EQ(dijkstra->GetDistanceTo(1), 2);
    EXPECT_EQ(dijkstra->GetDistanceTo(2), 5);
    EXPECT_EQ(dijkstra->GetDistanceTo(3), 7);
    EXPECT_EQ(dijkstra->GetDistanceTo(4), 1);
}

TEST_F(DijkstraTest, Source0Path) {
    dijkstra->ExecuteAlgorithm(0);
    std::stack<Edge> path = dijkstra->GetPath(1);
    EXPECT_EQ(path.size(), 1);
    EXPECT_EQ(0, path.top().GetFrom());

    path = dijkstra->GetPath(2);
    EXPECT_EQ(path.size(), 1);
    EXPECT_EQ(0, path.top().GetFrom());

    path = dijkstra->GetPath(3);
    EXPECT_EQ(path.size(), 2);
    EXPECT_EQ(0, path.top().GetFrom());
    path.pop();
    EXPECT_EQ(1, path.top().GetFrom());

    path = dijkstra->GetPath(4);
    EXPECT_EQ(path.size(), 1);
    EXPECT_EQ(0, path.top().GetFrom());
}
}  // namespace data_structures