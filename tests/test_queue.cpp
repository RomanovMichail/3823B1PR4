#include<gtest.h>
#include"E:\PROJECTS\3823B1PR4\lib_queue\Queue.h"
// Тест на проверку конструктора и isEmpty

TEST(TQueueTest, ConstructorAndIsEmptyTest) {
    TQueue<int> queue(10);  // Создаем очередь с размером 10
    EXPECT_TRUE(queue.isEmpty());  // Проверяем, что очередь пуста
}

// Тест на проверку операции push и top
TEST(TQueueTest, PushAndTopTest) {
    TQueue<int> queue(10);
    queue.push(42);  // Добавляем элемент в очередь
    EXPECT_EQ(queue.top(), 42);  // Проверяем, что верхний элемент это 42
}

// Тест на проверку операции pop
TEST(TQueueTest, PopTest) {
    TQueue<int> queue(10);
    queue.push(42);
    queue.push(99);
    queue.pop();  // Удаляем верхний элемент
    EXPECT_EQ(queue.top(), 99);  // Теперь верхний элемент это 99
}