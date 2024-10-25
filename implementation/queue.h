#ifndef __QUEUE__
#define __QUEUE__
#include "dynamicArray.h"
#include <stdbool.h>
typedef struct Queue Queue;
struct Queue {
  int bottomIndex;
  DynamicArray *dynamicArray;
  bool (*isEmpty)(Queue *queue);
  void (*enqueue)(Queue *queue, void *element);
  void (*dequeue)(Queue *queue);
  int (*queueSize)();
};
Queue *newQueue();
bool isEmpty(Queue *queue);
void enqueue(Queue *queue, void *element);
void dequeue(Queue *queue);
int queueSize(Queue* queue);
void destroyQueue(Queue* queue);
#endif
