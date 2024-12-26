#pragma once
#include <queue>
#include <stack>
#include <vector>

#include "graph/directed_graph.h"

namespace data_structures {
class Dijkstra {
   private:
    const DirectedGraph &graph_;
    int source_;
    Edge *edge_to_last_;
    std::priority_queue<Edge, std::vector<Edge>,
                        bool (*)(const Edge &, const Edge &)>
        min_path_queue_;
    double *distance_to;
    void Reset();

   public:
    Dijkstra(const DirectedGraph &graph,
             bool (*comparator)(const Edge &, const Edge &));
    ~Dijkstra();
    void ExecuteAlgorithm(int source);
    void Visit(int vertex);
    void Relax(Edge edge);
    double GetDistanceTo(int v);
    std::stack<Edge> GetPath(int vertex);
    void PrintPath(int v);
    bool IsClosed(int v);
    bool HasPathTo(int v);
};
}  // namespace data_structures