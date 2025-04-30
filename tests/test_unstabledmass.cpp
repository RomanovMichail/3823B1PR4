#include"../lib_unstabledmass/unstabledmass.h"
#include"gtest.h"


TEST(UnsTableDMTest, InsertWithKey) {
    Unsorted_Table<int, std::string> table;
    table.insert(1, "one");
    ASSERT_EQ(table.find(1), "one");
    
}

TEST(UnsTableDMTest, EraseExistingKey) {
    Unsorted_Table<int, int> table;
    int key1 = table.insert(10);
    int key2 = table.insert(20);
    
    table.erase(key1);
    EXPECT_THROW(table.find(key1), std::logic_error);
    ASSERT_EQ(table.find(key2), 20);
}

TEST(UnsTableDMTest, EraseNonExistentKeyThrows) {
    Unsorted_Table<std::string, int> table;
    table.insert("valid_key", 42);
    
    EXPECT_THROW(table.erase("invalid_key"), std::logic_error);
}

TEST(UnsTableDMTest, OperatorBracket) {
    Unsorted_Table<std::string, int> table;
    table.insert("one", 1);
    
    ASSERT_EQ(table["one"], 1);
    table["one"] = 2;
    ASSERT_EQ(table["one"], 2);
    
    EXPECT_THROW(table["two"], std::logic_error);
}

TEST(UnsTableDMTest, FindInEmptyTableThrows) {
    Unsorted_Table<int, double> table;
    EXPECT_THROW(table.find(42), std::logic_error);
}

TEST(UnsTableDMTest, InsertAfterErase) {
    Unsorted_Table<int, std::string> table;
    int key = table.insert("first");
    table.erase(key);
    
    table.insert(key, "second");
    ASSERT_EQ(table.find(key), "second");
}

TEST(UnsTableDMTest, ModifyValueViaOperator) {
    Unsorted_Table<int, int> table;
    int key = table.insert(5);
    table[key] = 10;
    ASSERT_EQ(table.find(key), 10);
}