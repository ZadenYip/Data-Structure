#pragma once
#include "sort.h"

namespace data_structures {

template <typename T>
class SelectSort : public BaseSort<T> {
   public:
    /**
     * @param priority_comparator 后者的优先级大于前者时返回true
     *                            return true means the latter has higher priority
     */
    SelectSort(std::function<bool(const T&, const T&)> priority_comparator)
        : BaseSort<T>(priority_comparator) {}
    void sort(T* data, int length) override {
        for (int i = 0; i < length; i++) {
            int min_index = i;
            for (int j = i; j < length; j++) {
                if (this->priority_comparator_(data[min_index], data[j])) {
                    min_index = j;
                }
            }
            this->swap(data[i], data[min_index]);
        }
    }
    ~SelectSort() {}
};
}  // namespace data_structures