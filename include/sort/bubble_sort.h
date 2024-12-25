#include "sort/sort.h"

namespace data_structures {
template <typename T>
class BubbleSort : public BaseSort<T> {
   public:
    BubbleSort(std::function<bool(const T&, const T&)> priority_comparator)
        : BaseSort<T>(priority_comparator) {}

    void sort(T* data[], int length) override {
        for (int sorting_length = length; sorting_length > 0; sorting_length--) {
            for (int i = 0; i < sorting_length - 1; i++) {
                if (this->priority_comparator_(*data[i], *data[i + 1])) {
                    std::swap(data[i], data[i + 1]);
                }
            }
        }
    }
};
}  // namespace data_structures