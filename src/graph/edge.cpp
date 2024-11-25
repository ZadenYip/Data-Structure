#include "graph/edge.h"

namespace data_structures {
Edge::Edge(int from, int to) : from(from), to(to) {}
Edge::Edge(int from, int to, double weight)
    : from(from), to(to), weight(weight) {}
int Edge::GetFrom() const { return from; }
int Edge::GetTo() const { return to; }
}  // namespace data_structures
