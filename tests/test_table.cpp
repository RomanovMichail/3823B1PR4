#pragma once
#include"iostream"
#include"../lib_list/List.h"
#include"../lib_pair/pair.h"
#include"string.h"
#include"../lib_itable/Itable.h"
#include"../lib_table/table.h"
#include <gtest.h>


TEST(UnstableTest, DefaultConstructor) {
    Unsorted_Table<int, std::string> table;
    EXPECT_EQ(table.size(), 0);
    EXPECT_TRUE(table.empty());
}

TEST(UnstableTest, InsertValue) {
    Unsorted_Table<int, std::string> table;
    int key1 = table.insert("value1");
    int key2 = table.insert("value2");

    EXPECT_EQ(table.size(), 2);
    EXPECT_FALSE(table.empty());
    EXPECT_NE(key1, key2);
    EXPECT_EQ(table.find(key1), "value1");
    EXPECT_EQ(table.find(key2), "value2");
}

TEST(UnstableTest, InsertKeyValue) {
    Unsorted_Table<int, std::string> table;
    table.insert(1, "value1");
    table.insert(2, "value2");
    table.insert(1, "new_value1"); // Overwrite

    EXPECT_EQ(table.size(), 2);
    EXPECT_EQ(table.find(1), "new_value1");
    EXPECT_EQ(table.find(2), "value2");
}

TEST(UnstableTest, FindAndSearch) {
    Unsorted_Table<int, std::string> table;
    table.insert(1, "value1");
    table.insert(2, "value2");

    EXPECT_EQ(table.find(1), "value1");
    EXPECT_EQ(table.find(2), "value2");
    EXPECT_THROW(table.find(3), std::out_of_range);
    EXPECT_TRUE(table.search(1));
    EXPECT_FALSE(table.search(3));
}

TEST(UnstableTest, Erase) {
    Unsorted_Table<int, std::string> table;
    table.insert(1, "value1");
    table.insert(2, "value2");
    table.insert(3, "value3");

    table.erase(2);
    EXPECT_EQ(table.size(), 2);
    EXPECT_FALSE(table.search(2));
    EXPECT_THROW(table.find(2), std::out_of_range);

    table.erase(1);
    table.erase(3);
    EXPECT_TRUE(table.empty());
}

TEST(UnstableTest, CopyConstructor) {
    Unsorted_Table<int, std::string> table1;
    table1.insert(1, "value1");
    table1.insert(2, "value2");

    Unsorted_Table<int, std::string> table2(table1);

    EXPECT_EQ(table1.size(), table2.size());
    EXPECT_EQ(table2.find(1), "value1");
    EXPECT_EQ(table2.find(2), "value2");

    table1.erase(1);
    EXPECT_EQ(table2.size(), 2); 
}


TEST(UnstableTest, SelfAssignment) {
    Unsorted_Table<int, std::string> table;
    table.insert(1, "value1");
    table.insert(2, "value2");

    table = table;

    EXPECT_EQ(table.size(), 2);
    EXPECT_EQ(table.find(1), "value1");
    EXPECT_EQ(table.find(2), "value2");
}