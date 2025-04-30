#include"gtest.h"
#include"../lib_maxheap/MaxHeap.h"

TEST(MaxHeapTest, IsEmptyInitially) {
    MaxHeap<int> heap;
    EXPECT_TRUE(heap.is_empty());
}

TEST(MaxHeapTest, InsertAndMax) {
    MaxHeap<int> heap;
    heap.insert(10);
    EXPECT_EQ(heap.max(), 10);
    heap.insert(20);
    EXPECT_EQ(heap.max(), 20);
    heap.insert(15);
    EXPECT_EQ(heap.max(), 20);
}

TEST(MaxHeapTest, RemoveMax) {
    MaxHeap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    EXPECT_EQ(heap.remove_max(), 20);
    EXPECT_EQ(heap.max(), 15);
    EXPECT_EQ(heap.remove_max(), 15);
    EXPECT_EQ(heap.max(), 10);
}


TEST(MaxHeapTest, RemoveMaxUnderflow) {
    MaxHeap<int> heap;
    EXPECT_THROW(heap.remove_max(), std::underflow_error);
}

TEST(MaxHeapTest, EmplaceTest) {
    MaxHeap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.emplace(0, 5); 
    EXPECT_EQ(heap.max(), 15);
}

TEST(MaxHeapTest, InitFromArray) {
    int arr[] = { 10, 40, 30, 5, 12, 6 };
    MaxHeap<int> heap(6, arr);
    EXPECT_EQ(heap.max(), 40);
}