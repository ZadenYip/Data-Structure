#include "sort.h"

namespace data_structures {

template <typename T>
class InsertSort : public BaseSort<T> {
   public:
    /**
     * @param priority_comparator 后者的优先级大于前者时返回true
     *                            return true means the latter has higher
     * priority
     */
    InsertSort(std::function<bool(const T&, const T&)> priority_comparator)
        : BaseSort<T>(priority_comparator) {}
    void sort(T* data, int length) override {
        for (int solving = 1; solving < length; solving++) {
            T key = data[solving];
            for (int insert = solving; insert > 0 && this->priority_comparator_(data[insert - 1], data[insert]); insert--) {
                this->swap(data[insert], data[insert - 1]);
            }
        }
    }
    ~InsertSort() {}
};

}  // namespace data_structures