#include "graph/shortest_path/dijkstra.h"

#include <iostream>
#include <stack>

namespace data_structures {
Dijkstra::Dijkstra(const DirectedGraph& graph,
                   bool (*comparator)(const Edge&, const Edge&))
    : graph_(graph), min_path_queue_(comparator) {
    int num_vertices = graph.GetNumVertices();
    edge_to_last_ = new Edge[num_vertices];
    distance_to = new double[num_vertices];
}

void Dijkstra::ExecuteAlgorithm(int source) {
    source_ = source;
    Reset();
    distance_to[source] = 0;
    Visit(source);
    while (!min_path_queue_.empty()) {
        Edge edge = min_path_queue_.top();
        min_path_queue_.pop();
        int to = edge.GetTo();
        if (!IsClosed(to)) {
            Visit(to);
            Relax(edge);
        }
    }
}

void Dijkstra::Reset() {
    edge_to_last_[source_] = Edge(-1, -1, -1);
    for (int vertex = 0; vertex < graph_.GetNumVertices(); vertex++) {
        distance_to[vertex] = std::numeric_limits<double>().max();
    }
}

Dijkstra::~Dijkstra() {
    delete[] edge_to_last_;
    delete[] distance_to;
}

bool Dijkstra::IsClosed(int v) {
    return distance_to[v] != std::numeric_limits<double>().max();
}

bool Dijkstra::HasPathTo(int v) {
    return distance_to[v] < std::numeric_limits<double>().max();
}

void Dijkstra::Visit(int vertex) {
    for (Edge edge : graph_.GetNeighborsEdges(vertex)) {
        min_path_queue_.push(edge);
    }
}

void Dijkstra::Relax(Edge edge) {
    int from = edge.GetFrom();
    int to = edge.GetTo();
    if (distance_to[to] > distance_to[from] + edge.GetWeight()) {
        distance_to[to] = distance_to[from] + edge.GetWeight();
        edge_to_last_[to] = edge;
    }
}

double Dijkstra::GetDistanceTo(int v) { return distance_to[v]; }

std::stack<Edge> Dijkstra::GetPath(int target) {
    std::stack<Edge> path;
    for (int vertex = target; vertex != source_;
         vertex = edge_to_last_[vertex].GetFrom()) {
        path.push(edge_to_last_[vertex]);
    }
    return path;
}

void Dijkstra::PrintPath(int target) {
    std::stack<Edge> path = GetPath(target);
    while (!path.empty()) {
        std::cout << path.top().GetFrom() << " -> " << path.top().GetTo()
                  << " ";
        path.pop();
    }
    std::cout << std::endl;
}
}  // namespace data_structures