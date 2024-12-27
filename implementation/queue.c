#include "queue.h"

Queue *newQueue() {
  Queue *ptrQueue = (Queue *)malloc(sizeof(Queue));
  ptrQueue->dynamicArray = newDynamicArray();
  ptrQueue->queueIsEmpty = queueIsEmpty;
  ptrQueue->enqueue = enqueue;
  ptrQueue->dequeue = dequeue;
  ptrQueue->queueSize = queueSize;
  return ptrQueue;
}

bool queueIsEmpty(Queue *queue) {
  assert(queue != NULL);
  return (queue->dynamicArray->counter == 0 ||
          queue->dynamicArray->bottomIndex >= queue->dynamicArray->counter)
             ? true
             : false;
}
void enqueue(Queue *queue, void *element) {
  assert(queue != NULL);
  assert(element != NULL);
  queue->dynamicArray->addElement(queue->dynamicArray, element);
}

void *dequeue(Queue *queue) {
  assert(queue != NULL);
  assert(queue->queueIsEmpty(queue) == false);
  // we are going to return this just in case
  void *elementInArray =
      queue->dynamicArray->getElement(queue->dynamicArray, 0);
  int *element = (int *)malloc(sizeof(int));
  *element = *(int *)elementInArray;
  queue->dynamicArray->removeElementBack(queue->dynamicArray, 0);
  return (void *)element;
}

int queueSize(Queue *queue) {
  assert(queue != NULL);
  return queue->dynamicArray->size;
}
void destroyQueue(Queue *queue) {
  assert(queue != NULL);
  destroyDynamicArray(queue->dynamicArray);
  free(queue);
  queue = NULL;
}
