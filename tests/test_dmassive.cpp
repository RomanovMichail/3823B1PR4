#include <gtest.h>
#include "../lib_dmassive/dmassive.h"

TEST(TDMassiveTest, DefaultConstructor) {
    TDMassive<int> massive;
    EXPECT_EQ(massive.size(), 0);
    EXPECT_EQ(massive.capacity(), STEP_CAPACITY);
   
}


TEST(TDMassiveTest, ConstructorWithArray) {
    int arr[] = { 1, 2, 3 };
    TDMassive<int> massive(arr, 3);
    EXPECT_EQ(massive.size(), 3);
    EXPECT_EQ(massive.capacity(), 3);
 
}

TEST(TDMassiveTest, IsEmptyTest) {
    TDMassive<int> massive;
    EXPECT_TRUE(massive.empty());
}
TEST(TDMassiveTest, IsFullTest) {
    int arr[] = { 1, 2, 3 };
    TDMassive<int> massive(arr, 3);
    EXPECT_TRUE(massive.full());
}

TEST(TDMassiveTest, PushBack) {
    TDMassive<int> massive;
    massive.push_back(1);
    massive.push_back(2);
    EXPECT_EQ(massive.size(), 2);
    EXPECT_EQ(massive.data()[0], 1);
    EXPECT_EQ(massive.data()[1], 2);
}

TEST(TDMassiveTest, PopBack) {
    TDMassive<int> massive;
    massive.push_back(1);
    massive.push_back(2);
    massive.pop_back();
    EXPECT_EQ(massive.size(), 1);
    EXPECT_EQ(massive.data()[0], 1);
}

TEST(TDMassiveTest, PushFront) {
    TDMassive<int> massive;
    massive.push_front(2);
    massive.push_front(1);
    EXPECT_EQ(massive.size(), 2);
    EXPECT_EQ(massive.data()[0], 1);
    EXPECT_EQ(massive.data()[1], 2);
}


TEST(TDMassiveTest, PopFront) {
    TDMassive<int> massive;
    massive.push_back(1);
    massive.push_back(2);
    massive.pop_front();
    EXPECT_EQ(massive.size(), 1);
    EXPECT_EQ(massive.data()[0], 2);
}


TEST(TDMassiveTest, Insert) {
    TDMassive<int> massive;
    massive.push_back(1);
    massive.push_back(3);
    massive.insert(2, 1);
    EXPECT_EQ(massive.size(), 3);
    EXPECT_EQ(massive.data()[1], 2);
}

TEST(TDMassiveTest, Replace) {
    TDMassive<int> massive;
    massive.push_back(1);
    massive.push_back(2);
    massive.replace(1, 3);
    EXPECT_EQ(massive.data()[1], 3);
}


TEST(TDMassiveTest, FindFirst) {
    TDMassive<int> massive;
    massive.push_back(1);
    massive.push_back(2);
    massive.push_back(2);
    EXPECT_EQ(massive.find_first(2), 1);
}


TEST(TDMassiveTest, RemoveAll) {
    TDMassive<int> massive;
    massive.push_back(1);
    massive.push_back(2);
    massive.push_back(1);
    massive.remove_all(1);
    EXPECT_EQ(massive.size(), 3);
    EXPECT_EQ(massive.find_first(1), -1);
}


TEST(TDMassiveTest, Clear) {
    TDMassive<int> massive;
    massive.push_back(1);
    massive.push_back(2);
    massive.clear();
    EXPECT_TRUE(massive.empty());
}


TEST(TDMassiveTest, Assign) {
    TDMassive<int> massive1;
    massive1.push_back(1);
    TDMassive<int> massive2;
    massive2.assign(massive1);
    EXPECT_EQ(massive2.size(), 1);
    EXPECT_EQ(massive2.data()[0], 1);
}