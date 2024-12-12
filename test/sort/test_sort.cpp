#include <gtest/gtest.h>

#include <functional>

#include "sort/select_sort.h"

namespace data_structures {
class SortTest : public ::testing::Test {
   protected:
    ~SortTest() override {}
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(SortTest, SelectSort) {
    int data[] = {3, 2, 1, 5, 4};
    int length = 5;
    // a > b, 返回true表示后续优先级高
    // a > b, return true means a has higher priority
    SelectSort<int> select_sort = SelectSort<int>(std::greater<int>());
    select_sort.sort(data, length);
    int expected[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < length; i++) {
        EXPECT_EQ(data[i], expected[i]);
    }
}
}  // namespace data_structures