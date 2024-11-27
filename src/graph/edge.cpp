#include "graph/edge.h"

namespace data_structures {
Edge::Edge() {
    from_ = -1;
    to_ = -1;
    weight_ = -1;
}
Edge::Edge(int from, int to) : from_(from), to_(to) {}
Edge::Edge(int from, int to, double weight)
    : from_(from), to_(to), weight_(weight) {}

Edge& Edge::operator=(const Edge& edge) {
    from_ = edge.from_;
    to_ = edge.to_;
    weight_ = edge.weight_;
    return *this;
}
int Edge::GetFrom() const { return from_; }
int Edge::GetTo() const { return to_; }
void Edge::SetWeight(double weight) { this->weight_ = weight; }
double Edge::GetWeight() const { return weight_; }
}  // namespace data_structures
