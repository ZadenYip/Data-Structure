#pragma once
namespace data_structures {
class Edge {
   private:
    int from_;
    int to_;
    double weight_;

   public:
    Edge();
    Edge(int from, int to, double weight);
    Edge(int from, int to);
    int GetFrom() const;
    int GetTo() const;
    double GetWeight() const;
    void SetWeight(double weight);
    Edge& operator=(const Edge& edge);
};
}  // namespace data_structures