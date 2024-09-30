#include<gtest.h>
#include"C:\Michail_Romanov\3823B1PR4\lib_queue\Queue.h"


TEST(TQueueTest, ConstructorTest) {
    ASSERT_NO_THROW(TQueue<int> queue(10));
      
}

TEST(TQueueTest, IsEmptyTest) {
    TQueue<int> queue(10);
    EXPECT_TRUE(queue.isEmpty());
}

TEST(TQueueTest, PushAndTopTest) {
    TQueue<int> queue(10);
    queue.push(42);  
    EXPECT_EQ(queue.top(), 42);  
}


TEST(TQueueTest, PopTest) {
    TQueue<int> queue(10);
    queue.push(42);
    queue.push(99);
    queue.pop();  
    EXPECT_EQ(queue.top(), 99);  
}//тест на исключение, создать очередь размером поменьше, проверка, что всё сдвигается нормально

TEST(TQueueTest, OverflowTest) {
    TQueue<int> queue(2);
    queue.push(42);
    queue.push(99);
    EXPECT_THROW(queue.push(42), std::overflow_error);
}

TEST(TQueueTest,PopAllTest) {
    TQueue<int> queue(2);
    queue.push(42);
    queue.push(99);

    queue.pop();
    queue.pop();

    EXPECT_THROW(queue.pop(), std::logic_error);


}
TEST(TQueueTest, TopOnEmptyTest) {
    TQueue<int> queue(2);
   
    EXPECT_THROW(queue.top(), std::logic_error);


}
TEST(TQueueTest, PushAndPop) {
    TQueue<int> queue(7);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.push(7);
    
 

    queue.pop();
    queue.pop();

    queue.push(13);
    queue.push(14);
    for (size_t i = 0; i < 5; i++)
    {
        queue.pop();
    }
    EXPECT_EQ(queue.top(), 13);

}