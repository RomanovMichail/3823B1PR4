#include"..\lib_list\List.h"
#include"..\lib_list\Node.h"
#include"gtest.h"

class TestListsLib : public ::testing::Test {
protected:
	TList<int> list = TList<int>();
};

TEST_F(TestListsLib, check_push_front) {
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	EXPECT_EQ(list._head->value(), 3);
	EXPECT_EQ(list._head->next()->value(), 2);
	EXPECT_EQ(list._tail->value(), 1);
}

TEST_F(TestListsLib, check_empty) {
	list.push_front(1);
	EXPECT_EQ(list._head->value(), list._tail->value());
}

TEST_F(TestListsLib, check_push_back) {
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	EXPECT_EQ(list._head->value(), 1);
	EXPECT_EQ(list._head->next()->value(), 2);
	EXPECT_EQ(list._tail->value(), 3);
}

TEST(TestLists, check_find) {
	TList<int> list;
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	TNode<int>* val = list.find(6);
	EXPECT_EQ(val->value(), 6);
	EXPECT_EQ(val->next()->value(), 7);
}

TEST_F(TestListsLib, check_insert_pos) {
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.insert(1, 2);
	EXPECT_EQ(list._head->next()->value(), 2);
	EXPECT_EQ(list._head->next()->next()->value(), 5);
}

TEST_F(TestListsLib, check_insert_throw) {
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		ASSERT_THROW(list.insert(5, 10), std::out_of_range);
		ASSERT_THROW(list.insert(-1, 10), std::out_of_range);
}

TEST_F(TestListsLib, check_insert_node) {
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	TNode<int>* val = list.find(6);
	list.insert(val, 1);
	EXPECT_EQ(val->next()->value(), 1);
	EXPECT_EQ(val->next()->next()->value(), 7);
}

TEST_F(TestListsLib, check_insert_node_throw) {
	list.push_back(5);
	list.push_back(6);
	ASSERT_ANY_THROW(list.insert(nullptr, 5));
}

TEST_F(TestListsLib, check_pop_front) {
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.pop_front();
	ASSERT_EQ(list._head->value(), 6);
}

TEST_F(TestListsLib, check_pop_front_throw) {
	ASSERT_ANY_THROW(list.pop_front());
}

TEST_F(TestListsLib, check_pop_back) {
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	list.pop_back();
	ASSERT_EQ(list._tail->value(), 7);
}


TEST_F(TestListsLib, check_erase_node) {
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	TNode<int>* val = list.find(7);
	list.erase(val);
	ASSERT_EQ(list._head->next()->next()->value(), 8);
}

TEST_F(TestListsLib, check_erase_node_throw) {
	ASSERT_ANY_THROW(list.erase(nullptr));
}

TEST_F(TestListsLib, check_erase_pos) {
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.erase(1);
	ASSERT_EQ(list._head->next()->value(), 7);
}

TEST_F(TestListsLib, check_erase_pos_throw) {
	list.push_back(5);
	ASSERT_ANY_THROW(list.erase(-1));
	ASSERT_ANY_THROW(list.erase(2));
}

TEST_F(TestListsLib, check_replace) {
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	TNode<int>* val = list.find(6);
	list.replace(val, 9);
	ASSERT_EQ(val->value(), 9);
}
TEST_F(TestListsLib, reverse_list) {
	TList<int> s = TList<int>();
	for (int i = 0; i < 10; i++) {
		s.push_back(i);
	}
	TNode<int>* l = s.find(2);
	s._tail->next(l);
	EXPECT_EQ(s.hasCycle(), 1);
	s._tail->next(nullptr);
}

TEST_F(TestListsLib, rabbit_and_turtle) {
	TList<int> s = TList<int>();
	for (int i = 0; i < 10; i++) {
		s.push_back(i);
	}
	TNode<int>* l = s.find(2);
	s._tail->next(l);
	EXPECT_EQ(s.hasCycle(), 1);
	s._tail->next(nullptr);
}