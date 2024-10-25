#include "queue.h"

Queue *newQueue() {
  Queue *ptrQueue = (Queue *)malloc(sizeof(Queue));
  ptrQueue->dynamicArray = newDynamicArray();
  ptrQueue->dequeue = dequeue;
  ptrQueue->enqueue = enqueue;
  ptrQueue->queueSize = queueSize;
  ptrQueue->bottomIndex = 0;
  return ptrQueue;
}

bool isEmpty(Queue *queue) {

  // bool empty = false;
  if (queue->dynamicArray->counter == 0) {
    return true;
  }
  if (queue->dynamicArray->counter < queue->bottomIndex) {
    return true;
  }
  return false;
}
void enqueue(Queue *queue, void *element) {
  queue->dynamicArray->addElement(queue->dynamicArray, element);
}

void dequeue(Queue *queue) {
  queue->dynamicArray->removeElement(queue->dynamicArray, queue->bottomIndex);
  queue->bottomIndex++;
}

int queueSize(Queue *queue) { return queue->dynamicArray->size; }
void destroyQueue(Queue *queue) {
  free(queue->dynamicArray);
  free(queue);
}
