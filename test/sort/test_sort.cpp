#define ENABLE_TESTING
#include <gtest/gtest.h>

#include <functional>
#include <iostream>
#include <vector>

#include "sort/bubble_sort.h"
#include "sort/insert_sort.h"
#include "sort/merge_sort_recursion.h"
#include "sort/select_sort.h"
#include "sort/shell_sort.h"

namespace data_structures {
class WrapperData {
   public:
    int* data;
    int length_;
    ~WrapperData() { delete[] data; }
    WrapperData() : data(nullptr), length_(0) {}

    WrapperData(int data[], int length) : length_(length) {
        this->data = new int[length];
        for (int i = 0; i < length; i++) {
            this->data[i] = data[i];
        }
    }
    WrapperData(const WrapperData& wrapper) {
        length_ = wrapper.length_;
        data = new int[length_];
        for (int i = 0; i < length_; i++) {
            data[i] = wrapper.data[i];
        }
    }
};

class SortTest : public ::testing::Test {
   protected:
    std::vector<WrapperData> test_data_set_;
    SortTest() {}
    ~SortTest() override {}
    void Print(int* data[], int length) {
        for (int i = 0; i < length; i++) {
            std::cout << *data[i] << " ";
        }
        std::cout << std::endl;
    }
    void TestSort(BaseSort<int>& algorithrm) {
        for (const WrapperData wrapper : test_data_set_) {
            int* pointer_array[wrapper.length_];
            ConvertArrayToPointer(wrapper.data, pointer_array, wrapper.length_);
            // 打印排序前的数组
            std::cout << "Before sorting: ";
            Print(pointer_array, wrapper.length_);
            algorithrm.sort(pointer_array, wrapper.length_);
            bool actual = IsSorted(pointer_array, wrapper.length_);
            // 打印排序后的数组
            std::cout << "After sorting: ";
            Print(pointer_array, wrapper.length_);
            std::cout << std::endl;
            EXPECT_EQ(actual, true);
            for (int* pointer : pointer_array) {
                delete pointer;
            }
        }
    }
    /**
     * @brief 判断数组是否有序 从小到大
     *
     * @param data - 排序完成的数组
     * @param length - 数组长度
     * @return true - 有序
     * @return false - 无序
     */
    bool IsSorted(int* data[], int length) {
        for (int i = 0; i < length - 1; i++) {
            if (*data[i] > *data[i + 1]) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief 复制一份数组，将数组的每个元素的地址存入指针数组
     *        Copy an array, store the address of each element of the array in
     * the pointer array
     *
     * @param data - 数组
     *               array
     * @param data_pointer - 指针数组
     *                       pointer array
     * @param length - 数组长度
     *                 array length
     */
    void ConvertArrayToPointer(int data[], int* data_pointer[], int length) {
        for (int i = 0; i < length; i++) {
            data_pointer[i] = new int(data[i]);
        }
    }

    void SetUp() override {
        int length = 5;
        int data[] = {3, 2, 1, 5, 4};
        test_data_set_.push_back(WrapperData(data, length));

        length = 10;
        int data2[] = {3, 2, 1, 5, 4, 9, 8, 7, 6, 0};
        test_data_set_.push_back(WrapperData(data2, length));

        length = 10;
        int data3[] = {12, 24, 83, 41, 42, 66, 79, 80, 81, 24};
        test_data_set_.push_back(WrapperData(data3, length));

        length = 1;
        int data4[] = {1};
        test_data_set_.push_back(WrapperData(data4, length));

        length = 10;
        int data5[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        test_data_set_.push_back(WrapperData(data5, length));

        length = 10;
        int data6[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        test_data_set_.push_back(WrapperData(data6, length));

        // 生成随机数组进行随机化测试
        // generate random array for random test
        // srand(1);
        // const int per_array_length = 1000;
        // const int num_generate_array = 10;
        // const int range = 10;
        // for (int i = 0; i < num_generate_array; i++) {
        //     int generate_array[per_array_length];
        //     for (int j = 0; j < per_array_length; j++) {
        //         generate_array[j] = rand() % range;
        //     }
        //     test_data_set_.push_back(WrapperData(generate_array,
        //     per_array_length));
        // }
    }

    void TearDown() override {}
};

TEST_F(SortTest, InsertSort) {
    InsertSort<int> insert_sort = InsertSort<int>(std::greater<int>());
    TestSort(insert_sort);
}

TEST_F(SortTest, SelectSort) {
    // a > b, 返回true表示后续优先级高
    // a > b, return true means a has higher priority
    SelectSort<int> select_sort = SelectSort<int>(std::greater<int>());
    TestSort(select_sort);
}

TEST_F(SortTest, ShellSort) {
    ShellSort<int> shell_sort = ShellSort<int>(std::greater<int>());
    TestSort(shell_sort);
}

TEST_F(SortTest, BubbleSort) {
    BubbleSort<int> bubble_sort = BubbleSort<int>(std::greater<int>());
    TestSort(bubble_sort);
}

TEST_F(SortTest, MergeSortMergeFunction) {
    MergeSortRecursion<int> merge_sort =
        MergeSortRecursion<int>(std::greater<int>());
    int data[] = {2, 4, 5, 0, 1, 3, 6};
    int* data_pointer[7];
    ConvertArrayToPointer(data, data_pointer, 7);
    merge_sort.helper_array = new int[7];
    Print(data_pointer, 7);
    merge_sort.merge(data_pointer, 0, 4, 6);
    bool actual = IsSorted(data_pointer, 7);
    EXPECT_EQ(actual, true);
    Print(data_pointer, 7);
    for (int* pointer : data_pointer) {
        delete pointer;
    }
}

TEST_F(SortTest, MergeSortRecursion) {
    MergeSortRecursion<int> merge_sort =
        MergeSortRecursion<int>(std::greater<int>());
    TestSort(merge_sort);
}

}  // namespace data_structures