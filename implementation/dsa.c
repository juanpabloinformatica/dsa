#include "dsa.h"

int main(void) {
  // int element0 = 0;
  // int element1 = 1;
  // int element2 = 2;
  // int element3 = 3;
  // int element4 = 4;
  // int element5 = 5;
  // int element6 = 6;
  // int element7 = 7;
  // int element8 = 8;
  // int element9 = 9;
  // int element10 = 10;
  // int element11 = 11;
  // int element12 = 12;
  // int element13 = 13;
  // int element14 = 14;
  // int element15 = 15;
  // int element16 = 16;
  // int element17 = 17;
  // // // ------------------- Testing linked list--------------
  LinkedList *linkedList = newLinkedList();
  int *v1Ptr;
  int *v2Ptr;
  int *v3Ptr;
  int *v4Ptr;
  int *v5Ptr;
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  int v4 = 4;
  int v5 = 5;
  v1Ptr = &v1;
  v2Ptr = &v2;
  v3Ptr = &v3;
  v4Ptr = &v4;
  v5Ptr = &v5;
  linkedList->recAddLinkedListNode(linkedList, newLinkedListNode(v1Ptr));
  linkedList->recAddLinkedListNode(linkedList, newLinkedListNode(v2Ptr));
  linkedList->recAddLinkedListNode(linkedList, newLinkedListNode(v3Ptr));
  linkedList->recAddLinkedListNode(linkedList, newLinkedListNode(v4Ptr));
  linkedList->recAddLinkedListNode(linkedList, newLinkedListNode(v5Ptr));
  linkedList->recShowLinkedList(linkedList);
  // int *nextValue = malloc(sizeof(int));
  // int *nextNextValue = malloc(sizeof(int));
  // // // int *nextNextNextValue = malloc(sizeof(int));
  // *nextValue = 10;
  // *nextNextValue = 20;
  // // // *nextNextNextValue = 30;
  // LinkedListNode *next = newLinkedListNode((void *)nextValue);
  // LinkedListNode *nextNext = newLinkedListNode((void *)nextNextValue);
  // // LinkedListNode *nextNextNext = newLinkedListNode((void
  // // *)nextNextNextValue);
  // linkedList->addNode(linkedList, next);
  // linkedList->addNode(linkedList, nextNext);
  // // linkedList->addNode(linkedList, nextNextNext);
  // linkedList->head =
  //     linkedList->deleteNode(NULL, linkedList->head, (void *)nextNextValue);
  // // // printf("\nAddress at the beginning: %p", linkedList->head);
  // // linkedList->showLinkedListN(linkedList->head);
  // showLinkedListNormalNode(linkedList->head);
  // // printf("\nAddress at the end: %p", linkedList->head);
  // // // both are the same because before i was passing the linked list so it
  // // // was
  // // // // // creating another variable with the same linkedlist address but
  // was
  // // // // // modificating directly the head of the linked list, now if i
  // pass
  // // only
  // // // // // the
  // // // // // head is creating another variable with the same address so the
  // // // original
  // // // // // rest the same
  // // free(nextValue);
  // // free(nextNextValue);
  // // free(nextNextNextValue);
  // // free(linkedList);
  // // // // end linked list
  // // // // ----------------  Testing dynamic array --------------
  // // DynamicArray *dynamic = newDynamicArray();
  // //
  // // dynamic->addElement(dynamic, &element0);
  // // dynamic->addElement(dynamic, &element1);
  // // dynamic->addElement(dynamic, &element2);
  // // dynamic->addElement(dynamic, &element3);
  // // dynamic->addElement(dynamic, &element4);
  // // dynamic->addElement(dynamic, &element5);
  // // dynamic->addElement(dynamic, &element6);
  // // dynamic->addElement(dynamic, &element7);
  // // dynamic->addElement(dynamic, &element8);
  // // dynamic->addElement(dynamic, &element9);
  // // dynamic->addElement(dynamic, &element10);
  // // // dynamic->showArray(dynamic);
  // // dynamic->addElement(dynamic, &element10);
  // // dynamic->addElement(dynamic, &element11);
  // // dynamic->addElement(dynamic, &element12);
  // // dynamic->addElement(dynamic, &element13);
  // // dynamic->addElement(dynamic, &element14);
  // // dynamic->addElement(dynamic, &element15);
  // // dynamic->addElement(dynamic, &element16);
  // // dynamic->addElement(dynamic, &element17);
  // // dynamic->showArray(dynamic);
  // // // int elementGetPos13 = *(int *)dynamic->getElement(dynamic, 13);
  // // // printf("ELEMENT GET: %d", elementGetPos13);
  // // // dynamic->setElement(dynamic, 13, &elemaent0);
  // // // dynamic->showArray(dynamic);
  // // for (int i = 0; i < 10; i++) {
  // //   dynamic->removeElementFront(dynamic, dynamic->counter);
  // // }
  // // printf("\nAfter removing some characters:\n  ");
  // // dynamic->showArray(dynamic);
  // // destroyDynamicArray(dynamic);
  // // // // ------------- Testing stack ------------------
  // // printf("\n TESTING STACK\n");
  // Stack *stack = newStack();
  // stack->push(stack, &element0);
  // stack->push(stack, &element1);
  // stack->push(stack, &element2);
  // stack->push(stack, &element3);
  // stack->push(stack, &element4);
  // stack->dynamicArray->showArray(stack->dynamicArray);
  // while (stack->stackIsEmpty(stack) == false) {""
  //   printf("\nElement: %d", *(int *)stack->pop(stack));
  // }
  // destroyStack(stack);
  // printf("\n");
  // // ------------ end testing queue -----------------
  // // ------------ Testing queue ----------------
  // printf("[QUEUE] Testing queue\n");
  // Queue *queue = newQueue();
  // queue->enqueue(queue, &element0);
  // // queue->dynamicArray->showArray(queue->dynamicArray);
  // queue->enqueue(queue, &element1);
  // // queue->dynamicArray->showArray(queue->dynamicArray);
  // queue->enqueue(queue, &element2);
  // // queue->dynamicArray->showArray(queue->dynamicArray);
  // queue->enqueue(queue, &element3);
  // queue->enqueue(queue, &element4);
  // queue->enqueue(queue, &element5);
  // // queue->dynamicArray->showArray(queue->dynamicArray);
  // while (queue->queueIsEmpty(queue) == false) {
  //   void *value = queue->dequeue(queue);
  //   printf("\n[QUEUE] Element: %d ", *(int *)value);
  //   free(value);
  // }
  // queue->dynamicArray->showArray(queue->dynamicArray);
  // destroyQueue(queue);
  // //
  // return 0;
  // ---------------- Testing hashmap ------------------
  // Hashmap *hashmap = newHashmap("number", "number");
  // int keys[32];
  // for (int i = 0; i < 32; i++) {
  //   keys[i] = i;
  // }
  // for (int i = 0; i < 32; i++) {
  //   int *keyValue = (int *)malloc(sizeof(int));
  //   *keyValue = keys[i] * 100;
  //   hashmap->hashmapPut(hashmap, &keys[i], keyValue);
  // }
  // printf("\n%p", hashmap);
  // int result = hashmap->hashmapGet(hashmap, &keys[17]);
  // assert(result == keys[17] * 100);
  // hashmap->hashmapRemove(hashmap, &keys[17]);

  // ---------------- End Testing hashmap ------------------
}
