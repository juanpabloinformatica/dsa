#include "queue.h"

Queue *newQueue() {
  Queue *ptrQueue = (Queue *)malloc(sizeof(Queue));
  ptrQueue->dynamicArray = newDynamicArray();
  ptrQueue->dequeue = dequeue;
  ptrQueue->enqueue = enqueue;
  ptrQueue->queueSize = queueSize;
  ptrQueue->bottomIndex = 0;
  ptrQueue->queueIsEmpty = queueIsEmpty;
  return ptrQueue;
}

bool queueIsEmpty(Queue *queue) {
  // bool empty = false;
  if (queue->dynamicArray->counter == 0) {
    return true;
  }
  if (queue->dynamicArray->counter <= queue->bottomIndex) {
    return true;
  }
  return false;
}
void enqueue(Queue *queue, void *element) {
  queue->dynamicArray->addElement(queue->dynamicArray, element);
  printf("SHOWING ARRAY EACH TIME ONE ADDED: \n");
  queue->dynamicArray->showArray(queue->dynamicArray);
  printf("\n");
}

void *dequeue(Queue *queue) {
  void *frontElement =
      queue->dynamicArray->getElement(queue->dynamicArray, queue->bottomIndex);
  printf("\nBottom Index: %d", *(int *)frontElement);
  queue->dynamicArray->removeElementBack(queue->dynamicArray, queue->bottomIndex);
  queue->bottomIndex++;
  return frontElement;
}

int queueSize(Queue *queue) { return queue->dynamicArray->size; }
void destroyQueue(Queue *queue) {
  free(queue->dynamicArray);
  free(queue);
}
