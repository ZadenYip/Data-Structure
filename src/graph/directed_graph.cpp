#include "graph/directed_graph.h"

namespace data_structures {
DirectedGraph::DirectedGraph(int num_vertices)
    : num_vertices_(num_vertices), num_edges_(0) {
    adjacency_edge = new std::list<Edge>[num_vertices];
}

DirectedGraph::~DirectedGraph() { delete[] adjacency_edge; }

int DirectedGraph::GetNumVertices() const { return num_vertices_; }

int DirectedGraph::GetEdgeCount() const { return num_edges_; }

std::vector<int> DirectedGraph::GetNeighbors(int vertex) const {
    std::vector<int> neighbors;
    for (Edge edge : adjacency_edge[vertex]) {
        neighbors.push_back(edge.GetTo());
    }
    return neighbors;
}

void DirectedGraph::AddEdge(int from, int to) {
    adjacency_edge[from].push_back(Edge(from, to));
    num_edges_++;
}

bool DirectedGraph::HasEdge(int from, int to) const {
    for (Edge edge : adjacency_edge[from]) {
        if (edge.GetTo() == to) {
            return true;
        }
    }
    return false;
}
}  // namespace data_structures
