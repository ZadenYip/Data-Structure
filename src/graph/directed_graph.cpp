#include "graph/directed_graph.h"

#include <vector>

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

std::vector<Edge> DirectedGraph::GetNeighborsEdges(int vertex) const {
    std::vector<Edge> edges;
    for (Edge edge : adjacency_edge[vertex]) {
        edges.push_back(edge);
    }
    return edges;
}

void DirectedGraph::AddEdge(int from, int to) { AddEdge(from, to, -1.0); }

void DirectedGraph::AddEdge(int from, int to, double weight) {
    adjacency_edge[from].push_back(Edge(from, to, weight));
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
