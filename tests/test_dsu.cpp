#include <gtest.h>
#include "../lib_dmassive/dmassive.h"
#include "../lib_dsu/dsu.h"
TEST(DSUTest, MakeSet) {
    DSU dsu = 10;
    dsu.make_set(1);
    EXPECT_EQ(dsu.find(1), 1);

    dsu.make_set(5);
    EXPECT_EQ(dsu.find(5), 5);
}

TEST(DSUTest, UnionSets) {
    DSU dsu = 10;
    dsu.make_set(0);
    dsu.make_set(1);
    dsu.union_sets(0, 1);
    EXPECT_EQ(dsu.find(0), dsu.find(1)); 
}

TEST(DSUTest, FindOutOfRange) {
    DSU dsu = 10;
    EXPECT_THROW(dsu.find(-1), std::out_of_range);
    EXPECT_THROW(dsu.find(10), std::out_of_range);
}

TEST(DSUTest, UnionSetsOutOfRange) {
    DSU dsu = 10;
    EXPECT_THROW(dsu.union_sets(-1, 0), std::out_of_range);
    EXPECT_THROW(dsu.union_sets(0, 10), std::out_of_range);
}

TEST(DSUTest, MakeSetOutOfRange) {
    DSU dsu = 10;
    EXPECT_THROW(dsu.make_set(-1), std::out_of_range);
    EXPECT_THROW(dsu.make_set(10), std::out_of_range);
}
TEST(DSUTest, RankTest) {
    DSU dsu = 10;
    dsu.make_set(1);
    dsu.make_set(2);
    dsu.make_set(3);
    dsu.union_sets(1, 2);
    dsu.union_sets(2, 3);
    EXPECT_EQ(dsu.find(1), dsu.find(3)); 
}
TEST(DSUTest, Clear) {
    DSU dsu = 10;
    dsu.make_set(5);
    dsu.clear();
    EXPECT_THROW(dsu.find(5), std::out_of_range); 
}