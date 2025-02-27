#pragma once
#include"iostream"
#include"../lib_list/List.h"
#include"../lib_pair/pair.h"
#include"string.h"
#include"../lib_itable/Itable.h"
#include"../lib_table/table.h"
#include <gtest.h>


TEST(UnsortedTableTest, InsertAndFind) {
    UnsortedTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");
    table.insert(3, "three");

    EXPECT_EQ(table.find(1), "one");
    EXPECT_EQ(table.find(2), "two");
    EXPECT_EQ(table.find(3), "three");
}

TEST(UnsortedTableTest, FindNonExistentKey) {
    UnsortedTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");

    EXPECT_THROW(table.find(3), std::logic_error);
}

TEST(UnsortedTableTest, SearchExistingKey) {
    UnsortedTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");

    EXPECT_TRUE(table.search(1));
    EXPECT_TRUE(table.search(2));
}

TEST(UnsortedTableTest, SearchNonExistentKey) {
    UnsortedTable<int, std::string> table;
    table.insert(1, "one");

    EXPECT_FALSE(table.search(2));
}

TEST(UnsortedTableTest, EraseKey) {
    UnsortedTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");

    table.erase(1);
    EXPECT_THROW(table.find(1), std::logic_error);
    EXPECT_EQ(table.find(2), "two");
}

TEST(UnsortedTableTest, EraseNonExistentKey) {
    UnsortedTable<int, std::string> table;
    table.insert(1, "one");

    EXPECT_THROW(table.erase(2), std::logic_error);
}

TEST(UnsortedTableTest, InsertDuplicateKey) {
    UnsortedTable<int, std::string> table;
    table.insert(1, "one");

    EXPECT_THROW(table.insert(1, "duplicate"), std::logic_error);
}