#include"gtest.h"
#include"../lib_tbinsearchtree/tbinsearchtree.h"


TEST(BTreeTest, ConstructorTest) {
    ASSERT_NO_THROW(BTree<int> tree);
}

TEST(BTreeTest, InsertAndSearchTest) {
    BTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    EXPECT_NE(tree.search(10), nullptr);
    EXPECT_NE(tree.search(5), nullptr);
    EXPECT_NE(tree.search(15), nullptr);
    EXPECT_EQ(tree.search(20), nullptr);
}

TEST(BTreeTest, InsertDuplicateTest) {
    BTree<int> tree;
    tree.insert(10);
    EXPECT_THROW(tree.insert(10), std::logic_error);
}

TEST(BTreeTest, SearchPrevTest) {
    BTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    int val = 5;
    EXPECT_EQ(tree.search_prev(val)->value(), 10);
    val = 15;
    EXPECT_EQ(tree.search_prev(val)->value(), 10);
}

TEST(BTreeTest, EraseLeafNodeTest) {
    BTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.erase(5);
    EXPECT_EQ(tree.search(5), nullptr);
}

TEST(BTreeTest, EraseNodeWithOneChildTest) {
    BTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(3);
    tree.erase(5);
    EXPECT_EQ(tree.search(5), nullptr);
    EXPECT_NE(tree.search(3), nullptr);
}

TEST(BTreeTest, EraseNodeWithTwoChildrenTest) {
    BTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.erase(5);
    EXPECT_EQ(tree.search(5), nullptr);
    EXPECT_NE(tree.search(3), nullptr);
    EXPECT_NE(tree.search(7), nullptr);
}

TEST(BTreeTest, CopyConstructorTest) {
    BTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    BTree<int> copiedTree(tree);
    EXPECT_NE(copiedTree.search(10), nullptr);
    EXPECT_NE(copiedTree.search(5), nullptr);
    EXPECT_NE(copiedTree.search(15), nullptr);
}

TEST(BTreeTest, AssignmentOperatorTest) {
    BTree<int> tree1;
    tree1.insert(10);
    tree1.insert(5);
    tree1.insert(15);
    BTree<int> tree2;
    tree2 = tree1;
    EXPECT_NE(tree2.search(10), nullptr);
    EXPECT_NE(tree2.search(5), nullptr);
    EXPECT_NE(tree2.search(15), nullptr);
}

TEST(BTreeTest, SizeTest) {
    BTree<int> tree;
    EXPECT_EQ(tree.size(), 0);
    tree.insert(10);
    EXPECT_EQ(tree.size(), 1);
    tree.insert(5);
    EXPECT_EQ(tree.size(), 2);
    tree.erase(5);
    EXPECT_EQ(tree.size(), 1);
}
