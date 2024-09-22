#include <gtest.h>
#include "../lib_stack/stack.h"
TEST(TStackTest, ConstructorTest) {
    TStack<int> stack(5); 
    EXPECT_TRUE(stack.isEmpty());  
    EXPECT_FALSE(stack.isFull()); 
}

TEST(TStackTest, PushTest) {
    TStack<int> stack(3);  
    stack.push(10);
    EXPECT_FALSE(stack.isEmpty());  


    stack.push(20);
    stack.push(30);
    EXPECT_TRUE(stack.isFull());    

 
    EXPECT_THROW(stack.push(40), std::overflow_error);
}




TEST(TStackTest, IsEmptyAndIsFullTest) {
    TStack<int> stack(2);
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_FALSE(stack.isFull());

    stack.push(1);
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_FALSE(stack.isFull());

    stack.push(2);
    EXPECT_TRUE(stack.isFull());
}


TEST(TStackTest, DestructorTest) {
    TStack<int>* stack = new TStack<int>(5);
    stack->push(1);
    stack->push(2);
    delete stack;
}