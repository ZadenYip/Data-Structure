#include "sort.h"
/* 使用 FRIEND_TEST 宏声明友元测试 */
#ifdef ENABLE_TESTING
#include "gtest/gtest.h"
#define FRIEND_TEST_FUNCTION(test_name) \
    ;                                   \
    FRIEND_TEST(SortTest, test_name);
#else
#define FRIEND_TEST_FUNCTION(test_name) ;
#endif

namespace data_structures {
template <typename T>
class MergeSortRecursion : public BaseSort<T> {
   public:
    MergeSortRecursion(
        std::function<bool(const T&, const T&)> priority_comparator)
        : BaseSort<T>(priority_comparator) {}

   private:
    // 辅助数组
    // auxiliary array
    T* helper_array;
    FRIEND_TEST_FUNCTION(MergeSortMergeFunction);
    void merge_sort(T* data[], int low, int high) {
        if (low >= high) {
            return;
        }
        int middle = low + (high - low) / 2;
        merge_sort(data, low, middle);
        merge_sort(data, middle + 1, high);
        merge(data, low, middle, high);
    }

    void merge(T* data[], int low, int middle, int high) {
        for (int i = low; i <= high; i++) {
            helper_array[i] = *data[i];
        }

        int previous_sub = low;
        int latter_sub = middle + 1;
        for (int merge_index = low; merge_index <= high; merge_index++) {
            /* 左子数组已经全部放入 */
            /* left subarray has been put in */
            if (previous_sub > middle) {
                *data[merge_index] = helper_array[latter_sub];
                latter_sub++;
            }
            // 右子数组已经全部放入
            // right subarray has been put in
            else if (latter_sub > high) {
                *data[merge_index] = helper_array[previous_sub];
                previous_sub++;
            } else if (this->priority_comparator_(helper_array[previous_sub],
                                                  helper_array[latter_sub])) {
                *data[merge_index] = helper_array[latter_sub];
                latter_sub++;
            } else {
                *data[merge_index] = helper_array[latter_sub];
                previous_sub++;
            }
        }
    }
    void sort(T* data[], int length) override {
        helper_array = new T[length];
        merge_sort(data, 0, length - 1);
        delete[] helper_array;
    }
};

}  // namespace data_structures