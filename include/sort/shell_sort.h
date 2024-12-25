#pragma once
#include <functional>

#include "sort/sort.h"

namespace data_structures {
template <typename T>
class ShellSort : public BaseSort<T> {
   public:
    ShellSort(std::function<bool(const T&, const T&)> priority_comparator)
        : BaseSort<T>(priority_comparator) {}
    void sort(T* data[], int length) override {
        int h = 1;
        while (h < length / 3) {
            // h = 1, 4, 13, 40, 121, 364, 1093, ...
            h = 3 * h + 1; 
        }
        while (h >= 1) {
            for (int i = h; i < length; i++) {
                for (int j = i; j >= h && this->priority_comparator_(*data[j - h], *data[j]); j -= h) {
                    std::swap(data[j], data[j - h]);
                }
            }
            h = h / 3;
        }
    }
};
}  // namespace data_structures