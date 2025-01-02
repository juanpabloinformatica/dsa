#include "gtest/gtest.h"
extern "C" {
#include "../implementation/queue.h"
}
TEST(QueueTest, HandleQueueCreation) {
  Queue *queue = newQueue();
  EXPECT_TRUE(queue != NULL);
}
TEST(QueueTest, HandleQueueEnqueue) {
  const int ARRAY_LENGTH = 30;
  Queue *queue = newQueue();
  int elements[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elements[i] = i;
    queue->enqueue(queue, (int *)&elements[i]);
  }
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    int queueElement = *(int *)(queue->dynamicArray->array)[i];
    ASSERT_EQ(queueElement, elements[i]);
  }
}
TEST(QueueTest, HandleQueueDequeue) {
  const int ARRAY_LENGTH = 30;
  Queue *queue = newQueue();
  int elements[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elements[i] = i;
    queue->enqueue(queue, (int *)&elements[i]);
  }
  int dequeuedElement = *(int *)queue->dequeue(queue);
  ASSERT_EQ(dequeuedElement, 0);
}

TEST(QueueTest, HandleQueueIsEmpty) {
  const int ARRAY_LENGTH = 30;
  Queue *queue = newQueue();
  int elements[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elements[i] = i;
    queue->enqueue(queue, (int *)&elements[i]);
  }
  int testElement = 0;
  while (queue->queueIsEmpty(queue) == false) {
    int dequeuedElement = *(int *)queue->dequeue(queue);
    ASSERT_EQ(dequeuedElement, testElement++);
  }
  ASSERT_EQ(queue->dynamicArray->bottomIndex, ARRAY_LENGTH);
}
