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
  return (queue->dynamicArray->counter == 0 ||
          queue->dynamicArray->bottomIndex >= queue->dynamicArray->counter)
             ? true
             : false;
}
void enqueue(Queue *queue, void *element) {
  queue->dynamicArray->addElement(queue->dynamicArray, element);
}

void *dequeue(Queue *queue) {
  // we are going to return this just in case
  void *elementInArray = queue->dynamicArray->getElement(queue->dynamicArray, 0);
  int* element =( int*)malloc(sizeof(int));
  *element = *(int*)elementInArray;
  queue->dynamicArray->removeElementBack(queue->dynamicArray, 0);
  return (void*)element;
}

int queueSize(Queue *queue) { return queue->dynamicArray->size; }
void destroyQueue(Queue *queue) {
  destroyDynamicArray(queue->dynamicArray);
  free(queue);
}
