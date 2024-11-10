#include"..\lib_pair\pair.h"
#include"gtest.h"
#include"string.h"

TEST(TPairTest, ParameterizedConstructor) {
    TPair<int, int> pair(5, 10);
    EXPECT_EQ(pair.first(), 5);
    EXPECT_EQ(pair.second(), 10);
}

TEST(TPairTest, CopyConstructor) {
    TPair<int, int> pair1(3, 6);
    TPair<int, int> pair2(pair1);
    EXPECT_EQ(pair2.first(), 3);
    EXPECT_EQ(pair2.second(), 6);
}

TEST(TPairTest, AssignmentOperator) {
    TPair<int, int> pair1(4, 8);
    TPair<int, int> pair2;
    pair2 = pair1;
    EXPECT_EQ(pair2.first(), 4);
    EXPECT_EQ(pair2.second(), 8);
}

TEST(TPairTest, MakePair) {
    TPair<int, int> pair;
    pair.make_pair(7, 14);
    EXPECT_EQ(pair.first(), 7);
    EXPECT_EQ(pair.second(), 14);
}


TEST(TPairTest, Set_First_Second) {
    TPair<int, int> pair;
    pair.set_first(11);
    pair.set_second(22);
    EXPECT_EQ(pair.first(), 11);
    EXPECT_EQ(pair.second(), 22);
}


TEST(TPairTest, EqualityOperators) {
    TPair<int, int> pair1(5, 10);
    TPair<int, int> pair2(5, 10);
    TPair<int, int> pair3(7, 10);
    EXPECT_TRUE(pair1 == pair2);
    EXPECT_FALSE(pair1 != pair2);
    EXPECT_FALSE(pair1 == pair3);
}
TEST(TPairTest, OperatorMTET) {
    TPair<int, int> pair1(5, 10);
    TPair<int, int> pair2(5, 10);
    TPair<int, int> pair3(4, 12);
    TPair<int, int> pair4(6, 8);
    EXPECT_TRUE(pair1 >= pair2);
    EXPECT_TRUE(pair1 >= pair3);
    EXPECT_FALSE(pair1 >= pair4);
}

TEST(TPairTest, OperatorLTET) {
    TPair<int, int> pair1(5, 10);
    TPair<int, int> pair2(5, 10);
    TPair<int, int> pair3(4, 12);
    TPair<int, int> pair4(6, 8);
    EXPECT_TRUE(pair1 <= pair2);
    EXPECT_FALSE(pair1 <= pair3);
    EXPECT_TRUE(pair1 <= pair4);
}

TEST(TPairTest, Swap) {
    TPair<int, int> pair1(3, 6);
    TPair<int, int> pair2(7, 14);
    pair1.swap(pair2);
    EXPECT_EQ(pair1.first(), 7);
    EXPECT_EQ(pair1.second(), 14);
    EXPECT_EQ(pair2.first(), 3);
    EXPECT_EQ(pair2.second(), 6);
}




