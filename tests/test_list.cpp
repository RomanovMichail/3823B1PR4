#include"..\lib_list\List.h"
#include"..\lib_list\Node.h"
#include"gtest.h"



TEST(TestListsLib, push_front) {
	TList<int> list;
	list.push_front(10);
	EXPECT_EQ(list.get_size(), 1);
	EXPECT_EQ(list._head->value(), 10);
}

TEST(TestListsLib, empty) {
	TList<int> list;
	list.push_front(1);
	EXPECT_EQ(list._head->value(), list._tail->value());
}

TEST(TestListsLib, push_back) {
	TList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	EXPECT_EQ(list._head->value(), 1);
	EXPECT_EQ(list._head->next()->value(), 2);
	EXPECT_EQ(list._tail->value(), 3);
}

TEST(TestLists, find) {
	TList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	TNode<int>* val = list.find(3);
	EXPECT_EQ(val->value(), 3);
	EXPECT_EQ(val->next()->value(), 4);
}

TEST(TestListsLib,  insert_pos) {
	TList<int> list;
	list.push_back(10);
	list.push_back(30);
	list.insert(1, 20);  
	EXPECT_EQ(list.find(20)->value(), 20);
}

TEST(TestListsLib, insert_throw) {
		TList<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		ASSERT_THROW(list.insert(12, 5), std::out_of_range);
		ASSERT_THROW(list.insert(-2, 10), std::out_of_range);
}

TEST(TestListsLib, insert_node) {
	TList<int> list;
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	TNode<int>* val = list.find(6);
	list.insert(val, 1);
	EXPECT_EQ(val->next()->value(), 1);
	EXPECT_EQ(val->next()->next()->value(), 7);
}

TEST(TestListsLib, insert_node_throw) {
	TList<int> list;
	list.push_back(5);
	list.push_back(6);
	ASSERT_ANY_THROW(list.insert(nullptr, 5));
}

TEST(TestListsLib, pop_front) {
	TList<int> list;
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.pop_front();
	ASSERT_EQ(list._head->value(), 6);
}

TEST(TestListsLib, pop_front_throw) {
	TList<int> list;
	ASSERT_ANY_THROW(list.pop_front());
}

TEST(TestListsLib,  pop_back) {
	TList<int> list;
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	list.pop_back();
	ASSERT_EQ(list._tail->value(), 7);
}


TEST(TestListsLib, erase_node) {
	TList<int> list;
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	TNode<int>* val = list.find(7);
	list.erase(val);
	ASSERT_EQ(list._head->next()->next()->value(), 8);
}

TEST(TestListsLib, erase_node_throw) {
	TList<int> list;
	ASSERT_ANY_THROW(list.erase(nullptr));
}

TEST(TestListsLib, erase_pos) {
	TList<int> list;
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.erase(1);
	ASSERT_EQ(list._head->next()->value(), 7);
}

TEST(TestListsLib, erase_pos_throw) {
	TList<int> list;
	list.push_back(5);
	ASSERT_ANY_THROW(list.erase(-1));
	ASSERT_ANY_THROW(list.erase(2));
}

TEST(TestListsLib, replace) {
	TList<int> list;
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	TNode<int>* val = list.find(6);
	list.replace(val, 9);
	ASSERT_EQ(val->value(), 9);
}
TEST(TestListsLib, rabbit_and_turtle) {
	TList<int> s = TList<int>();
	for (int i = 0; i < 10; i++) {
		s.push_back(i);
	}
	TNode<int>* cycleStart = s.find(2);
	s._tail->next(cycleStart); 

	EXPECT_EQ(s.hasCycle(), 1);

	s._tail->next(nullptr); 
}
TEST(TestListsLib, reverse_list) {
	TList<int> s = TList<int>();
	for (int i = 0; i < 10; i++) {
		s.push_back(i);
	}
	TNode<int>* cycleStart = s.find(2);
	s._tail->next(cycleStart);

	EXPECT_EQ(s.reverse(), 1);

	s._tail->next(nullptr);
}

TEST(TestListsLib, errays) {
	TList<int> list;
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.erase(2);
	EXPECT_EQ(list.get_size(), 2);
	EXPECT_EQ(list._tail->value(), 6);
}

TEST(TListIteratorTest, IterateThroughList) {
	TList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	auto it = list.begin();
	EXPECT_EQ(*it, 1);
	++it;
	EXPECT_EQ(*it, 2);
	++it;
	EXPECT_EQ(*it, 3);
	++it;
	EXPECT_EQ(it, list.end());
}

TEST(TListIteratorTest, OutOfBounds) {
	TList<int> list;
	auto it = list.begin();
	EXPECT_THROW(*it, std::logic_error);
}

TEST(TListIteratorTest, PostfixIncrement) {
	TList<int> list;
	list.push_back(1);
	list.push_back(2);

	auto it = list.begin();
	auto old_it = it++;
	EXPECT_EQ(*old_it, 1);
	EXPECT_EQ(*it, 2);
}

TEST(TListIteratorTest, CompareIterators) {
	TList<int> list;
	list.push_back(1);

	auto it1 = list.begin();
	auto it2 = list.end();

	EXPECT_NE(it1, it2);
	++it1;
	EXPECT_EQ(it1, it2);
}