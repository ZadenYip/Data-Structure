#pragma once
#include <functional>
namespace data_structures {

template <typename T>
class BaseSort {
   public:
    /**
     * @param priority_compartor 比较器，返回true表示后者优先级高
     *                           comparator, return true means the latter has higher priority
     */
    BaseSort(std::function<bool(const T&, const T&)> priority_compartor)
        : priority_comparator_(priority_compartor) {}

    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
    virtual void sort(T* data, int length) = 0;
    virtual ~BaseSort() {}

   protected:
    std::function<bool(const T&, const T&)> priority_comparator_;
};

template <typename T>
void swap(T& a, T& b);

}  // namespace data_structures