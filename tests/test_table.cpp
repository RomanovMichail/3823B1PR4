#pragma once
#include"iostream"
#include"../lib_list/List.h"
#include"../lib_pair/pair.h"
#include"string.h"
#include"../lib_itable/Itable.h"
#include"../lib_table/table.h"
#include <gtest.h>


TEST(UnsortedTableTest, EmptyTable) {
    UnsortedTable<int, std::string> table;
    EXPECT_THROW(table.find(1), std::logic_error); 
}

TEST(UnsortedTableTest, InsertAndFind) {
    UnsortedTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");
    EXPECT_EQ(table.find(1), "one");
    EXPECT_EQ(table.find(2), "two");
}


TEST(UnsortedTableTest, OperatorBracketRead) {
    UnsortedTable<int, std::string> table;
    table.insert(3, "three");
    EXPECT_EQ(table[3], "three");
}


TEST(UnsortedTableTest, OperatorBracketWrite) {
    UnsortedTable<int, std::string> table;
    table.insert(4, "four");
    table[4] = "new_four";
    EXPECT_EQ(table.find(4), "new_four");
}

TEST(UnsortedTableTest, Erase) {
    UnsortedTable<int, std::string> table;
    table.insert(5, "five");
    table.erase(5);
    EXPECT_THROW(table.find(5), std::logic_error); 
}


TEST(UnsortedTableTest, FindNonExistent) {
    UnsortedTable<int, std::string> table;
    EXPECT_THROW(table.find(10), std::logic_error);
}


TEST(UnsortedTableTest, InsertDuplicateKey) {
    UnsortedTable<int, std::string> table;
    table.insert(6, "six");
    EXPECT_THROW(table.insert(6, "six_again"), std::logic_error);
}