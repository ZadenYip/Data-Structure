#include <gtest/gtest.h>

#include <functional>
#include <vector>

#include "sort/bubble_sort.h"
#include "sort/insert_sort.h"
#include "sort/select_sort.h"
#include "sort/shell_sort.h"

namespace data_structures {
class WrapperData {
   public:
    int*(*data_pointer_array_);
    int length_;
    ~WrapperData() { delete[] data_pointer_array_; }
    WrapperData() : data_pointer_array_(nullptr), length_(0) {}
    WrapperData(int* data_pointer_array[], int length) : length_(length) {
        data_pointer_array_ = new int*[length];
        for (int i = 0; i < length; i++) {
            data_pointer_array_[i] = data_pointer_array[i];
        }
    }
    WrapperData(const WrapperData& wrapper) {
        length_ = wrapper.length_;
        data_pointer_array_ = new int*[length_];
        for (int i = 0; i < length_; i++) {
            data_pointer_array_[i] = wrapper.data_pointer_array_[i];
        }
    }
};
class SortTest : public ::testing::Test {
   protected:
    std::vector<WrapperData> test_data_set_;
    SortTest() {}
    ~SortTest() override {}
    void TestSort(BaseSort<int>& algorithrm) {
        for (const WrapperData& wrapper : test_data_set_) {
            algorithrm.sort(wrapper.data_pointer_array_, wrapper.length_);
            bool actual = IsSorted(wrapper.data_pointer_array_, wrapper.length_);
            EXPECT_EQ(actual, true);
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
    void ConvertArrayToPointer(int data[], int* data_pointer[], int length) {
        for (int i = 0; i < length; i++) {
            data_pointer[i] = new int(data[i]);
        }
    }

    void SetUp() override {
        int length = 5;
        int data[] = {3, 2, 1, 5, 4};
        int* data_pointer[5];
        ConvertArrayToPointer(data, data_pointer, length);
        test_data_set_.push_back(WrapperData(data_pointer, length));

        length = 10;
        int data2[] = {3, 2, 1, 5, 4, 9, 8, 7, 6, 0};
        int* data_pointer2[10];
        ConvertArrayToPointer(data2, data_pointer2, length);
        test_data_set_.push_back(WrapperData(data_pointer2, length));

        length = 10;
        int data3[] = {12, 24, 83, 41, 42, 66, 79, 80, 81, 24};
        int* data_pointer3[10];
        ConvertArrayToPointer(data3, data_pointer3, length);
        test_data_set_.push_back(WrapperData(data_pointer3, length));

        length = 1;
        int data4[] = {1};
        int* data_pointer4[1];
        ConvertArrayToPointer(data4, data_pointer4, length);
        test_data_set_.push_back(WrapperData(data_pointer4, length));

        length = 10;
        int data5[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int* data_pointer5[10];
        ConvertArrayToPointer(data5, data_pointer5, length);

        length = 10;
        int data6[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        int* data_pointer6[10];
        ConvertArrayToPointer(data6, data_pointer6, length);

        // 生成随机数组进行随机化测试
        srand(time(nullptr));
        for (int i = 0; i < 100; i++) {
            length = 100;
            int data4[100];
            int* data_pointer4[100];
            for (int j = 0; j < length; j++) {
                data4[j] = rand() % 100;
            }
            ConvertArrayToPointer(data4, data_pointer4, length);
            test_data_set_.push_back(WrapperData(data_pointer4, length));
        }
    }

    void TearDown() override {}
};

TEST_F(SortTest, SelectSort) {
    // a > b, 返回true表示后续优先级高
    // a > b, return true means a has higher priority
    SelectSort<int> select_sort = SelectSort<int>(std::greater<int>());
    TestSort(select_sort);
}

TEST_F(SortTest, InsertSort) {
    InsertSort<int> insert_sort = InsertSort<int>(std::greater<int>());
    TestSort(insert_sort);
}

TEST_F(SortTest, ShellSort) {
    ShellSort<int> shell_sort = ShellSort<int>(std::greater<int>());
    TestSort(shell_sort);
}

TEST_F(SortTest, BubbleSort) {
    BubbleSort<int> bubble_sort = BubbleSort<int>(std::greater<int>());
    TestSort(bubble_sort);
}
}  // namespace data_structures