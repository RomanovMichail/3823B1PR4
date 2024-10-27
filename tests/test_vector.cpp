#include"gtest.h"

#include "..\lib_vector\vector.h""


TEST(TVectorTest, DefaultConstructor) {
    TVector<int> vec;
    EXPECT_EQ(vec.size(), 0);
}


TEST(TVectorTest, ConstructorWithSizeAndValue) {
    TVector<int> vec(5, 10);
    EXPECT_EQ(vec.size(), 5);
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], 10);
    }
}


TEST(TVectorTest, ConstructorWithArray) {
    int arr[] = { 1, 2, 3, 4, 5 };
    TVector<int> vec(arr, 5);
    EXPECT_EQ(vec.size(), 5);
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], arr[i]);
    }
}

TEST(TVectorTest, IndexOperator) {
    TVector<int> vec(3, 7);
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

TEST(TVectorTest, AdditionOperator) {
    TVector<int> vec1(3, 5);
    TVector<int> vec2(3, 2);
    TVector<int> result = vec1 + vec2;
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], 7);
    EXPECT_EQ(result[1], 7);
    EXPECT_EQ(result[2], 7);
}


TEST(TVectorTest, SubtractionOperator) {
    TVector<int> vec1(3, 5);
    TVector<int> vec2(3, 2);
    TVector<int> result = vec1 - vec2;
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], 3);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 3);
}

TEST(TVectorTest, AdditionAssignmentOperator) {
    TVector<int> vec1(3, 5);
    TVector<int> vec2(3, 2);
    vec1 += vec2;
    EXPECT_EQ(vec1[0], 7);
    EXPECT_EQ(vec1[1], 7);
    EXPECT_EQ(vec1[2], 7);
}

TEST(TVectorTest, SubtractionAssignmentOperator) {
    TVector<int> vec1(3, 5);
    TVector<int> vec2(3, 2);
    vec1 -= vec2;
    EXPECT_EQ(vec1[0], 3);
    EXPECT_EQ(vec1[1], 3);
    EXPECT_EQ(vec1[2], 3);
}


TEST(TVectorTest, DotProductOperator) {
    TVector<int> vec1(3, 2);
    TVector<int> vec2(3, 3);
    int result = vec1 * vec2;
    EXPECT_EQ(result, 18); // 2*3 + 2*3 + 2*3 = 18
}


TEST(TVectorTest, ScalarMultiplicationOperator) {
    TVector<int> vec(3, 3);
    TVector<int> result = vec * 2;
    EXPECT_EQ(result[0], 6);
    EXPECT_EQ(result[1], 6);
    EXPECT_EQ(result[2], 6);
}


TEST(TVectorTest, EqualityOperators) {
    TVector<int> vec1(3, 3);
    TVector<int> vec2(3, 3);
    TVector<int> vec3(3, 4);
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_FALSE(vec1 != vec2);
    EXPECT_FALSE(vec1 == vec3);
    EXPECT_TRUE(vec1 != vec3);
}


TEST(TVectorTest, LengthMethod) {
    TVector<int> vec(3, 2);
    double expected_length = std::sqrt(2 * 2 + 2 * 2 + 2 * 2);
    EXPECT_DOUBLE_EQ(vec.length(), expected_length);
}