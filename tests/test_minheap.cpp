#include"gtest.h"
#include"../lib_minheap/MinHeap.h"


TEST(MinHeapTest, Constructor) {
    MinHeap<int> heap;
    EXPECT_TRUE(heap.is_empty());
}
TEST(MinHeapTest, Insert) {
    MinHeap<int> heap;
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(1);
    EXPECT_EQ(heap.min(), 1);
}

TEST(MinHeapTest, RemoveMin) {
    MinHeap<int> heap;
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(1);
    EXPECT_EQ(heap.remove_min(), 1);
    EXPECT_EQ(heap.remove_min(), 5);
    EXPECT_EQ(heap.min(), 10);
}


TEST(MinHeapTest, MinThrowsOnEmptyHeap) {
    MinHeap<int> heap;
    EXPECT_THROW(heap.min(), std::underflow_error);
}

TEST(MinHeapTest, RemoveMinThrowsOnEmptyHeap) {
    MinHeap<int> heap;
    EXPECT_THROW(heap.remove_min(), std::underflow_error);
}


TEST(MinHeapTest, Emplace) {
    MinHeap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(30);
    heap.emplace(1, 5);
    EXPECT_EQ(heap.min(), 5);
}
