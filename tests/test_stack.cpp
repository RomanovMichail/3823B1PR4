#include <gtest.h>

#include "..\lib_stack\Stack.h"
TEST(TStackTest, StackIsEmpty) {
    TStack<int> stack(5); 
    EXPECT_TRUE(stack.isEmpty());  
     
}



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


TEST(TStackTest, PushAndTopTest) {
    TStack<int> stack(3);
    stack.push(10);
    stack.push(20);
    EXPECT_EQ(20, stack.top());


}

TEST(TStackTest, PopTest) {
    TStack<int> stack(3);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    stack.pop();
    stack.pop();
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());


    EXPECT_THROW(stack.pop(), std::logic_error);



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