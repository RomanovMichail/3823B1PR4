#include <gtest.h>
#include "..\lib_stack_tl\StackTL.h"


TEST(TStackTLTest, StackIsEmpty) {
    TStackTL<int> stack(5);
    EXPECT_TRUE(stack.isEmpty());

}



TEST(TStackTLTest, ConstructorTest) {
    TStackTL<int> stack(5);
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_FALSE(stack.isFull());
}

TEST(TStackTLTest, PushTest) {

    TStackTL<int> stack(3);
    stack.push(10);
    EXPECT_FALSE(stack.isEmpty());


    stack.push(20);
    stack.push(30);
    EXPECT_TRUE(stack.isFull());


    EXPECT_THROW(stack.push(40), std::overflow_error);
}


TEST(TStackTLTest, PushAndTopTest) {
    TStackTL<int> stack(3);
    stack.push(10);
    stack.push(20);
    EXPECT_EQ(20, stack.top());


}

TEST(TStackTLTest, PopTest) {
    TStackTL<int> stack(3);
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.pop();
    stack.pop();
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());


    EXPECT_THROW(stack.pop(), std::logic_error);



}





TEST(TStackTLTLTest, IsEmptyAndIsFullTest) {
    TStackTL<int> stack(2);
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_FALSE(stack.isFull());

    stack.push(1);
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_FALSE(stack.isFull());

    stack.push(2);
    EXPECT_TRUE(stack.isFull());
}


TEST(TStackTLTLTest, DestructorTest) {
    TStackTL<int>* stack = new TStackTL<int>(5);
    stack->push(1);
    stack->push(2);
    delete stack;
}