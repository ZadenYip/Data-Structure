#pragma once
#include <list>
#include <vector>

#include "graph/edge.h"

namespace data_structures {

class DirectedGraph {
   private:
    std::list<Edge> *adjacency_edge;
    int num_vertices_;
    int num_edges_;

   public:
    ~DirectedGraph();
    DirectedGraph(int num_vertices);
    int GetNumVertices() const;
    int GetEdgeCount() const;
    void AddEdge(int from, int to);
    std::vector<int> GetNeighbors(int vertex) const;
    bool HasEdge(int from, int to) const;
};
}  // namespace data_structures