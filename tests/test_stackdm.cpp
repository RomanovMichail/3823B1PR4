#include <gtest.h>
#include "..\lib_stack_dm\StackDM.h"


TEST(TStackDMTest, StackIsEmpty) {
    TStackDM<int> stack;
    EXPECT_TRUE(stack.isEmpty());

}



TEST(TStackDMTest, ConstructorTest) {
    TStackDM<int> stack;
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_FALSE(stack.isFull());
}

TEST(TStackDMTest, PushTest) {

    TStackDM<int> stack;
    stack.push(10);
    EXPECT_FALSE(stack.isEmpty());


    stack.push(20);
    stack.push(30);
    
}


TEST(TStackDMTest, PushAndTopTest) {
    TStackDM<int> stack;
    stack.push(10);
    stack.push(20);
    EXPECT_EQ(20, stack.top());


}

TEST(TStackDMTest, PopTest) {
    TStackDM<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.pop();
    stack.pop();
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());


    EXPECT_THROW(stack.pop(), std::logic_error);



}


TEST(TStackDMTLTest, DestructorTest) {
    TStackDM<int>* stack = new TStackDM<int>;
    stack->push(1);
    stack->push(2);
    delete stack;
}