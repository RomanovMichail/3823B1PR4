#include<gtest.h>
#include"E:\PROJECTS\3823B1PR4\lib_queue\Queue.h"
// ���� �� �������� ������������ � isEmpty

TEST(TQueueTest, ConstructorAndIsEmptyTest) {
    TQueue<int> queue(10);  // ������� ������� � �������� 10
    EXPECT_TRUE(queue.isEmpty());  // ���������, ��� ������� �����
}

// ���� �� �������� �������� push � top
TEST(TQueueTest, PushAndTopTest) {
    TQueue<int> queue(10);
    queue.push(42);  // ��������� ������� � �������
    EXPECT_EQ(queue.top(), 42);  // ���������, ��� ������� ������� ��� 42
}

// ���� �� �������� �������� pop
TEST(TQueueTest, PopTest) {
    TQueue<int> queue(10);
    queue.push(42);
    queue.push(99);
    queue.pop();  // ������� ������� �������
    EXPECT_EQ(queue.top(), 99);  // ������ ������� ������� ��� 99
}