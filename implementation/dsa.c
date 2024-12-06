#include "dsa.h"

int main(void) {

  Bst *bst = newBst();
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
  // // LinkedList *linkedList = newLinkedList();
  // // int *nextValue = malloc(sizeof(int));
  // // int *nextNextValue = malloc(sizeof(int));
  // // int *nextNextNextValue = malloc(sizeof(int));
  // // *nextValue = 10;
  // // *nextNextValue = 20;
  // // *nextNextNextValue = 30;
  // // LinkedListNode *next = newLinkedListNode((void *)nextValue);
  // // LinkedListNode *nextNext = newLinkedListNode((void *)nextNextValue);
  // // LinkedListNode *nextNextNext = newLinkedListNode((void
  // // *)nextNextNextValue); linkedList->addNode(linkedList, next);
  // // linkedList->addNode(linkedList, nextNext);
  // // linkedList->addNode(linkedList, nextNextNext);
  // // linkedList->head =
  // //     linkedList->deleteNode(NULL, linkedList->head, (void *)nextValue);
  // // printf("\nAddress at the beginning: %p", linkedList->head);
  // // linkedList->showLinkedList(linkedList->head);
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
  Hashmap *hashmap = newHashmap("number", "number");
  int keys[32];
  for (int i = 0; i < 32; i++) {
    keys[i] = i;
  }
  for (int i = 0; i < 32; i++) {
    // int keyValue = keys[i] * 100;
    int *keyValue = (int *)malloc(sizeof(int));
    *keyValue = keys[i] * 100;
    hashmap->hashmapPut(hashmap, &keys[i], keyValue);
    // assert(listt->head != null);
    // assert(listt->addlinkedlistnode != null);
    // printf("\npointer of the array in %d index:\t%p", i, &keys[i]);
  }
  for (int i = 0; i < 32 / 2; i++) {
    LinkedList *listT = ((LinkedList *)(hashmap->array)[i]);
    // assert(listT->deleteLinkedListNode != NULL);
    assert(listT->showLinkedList != NULL);
    printf("\n------ I:%i------\n", i);
    listT->showLinkedList(listT);
    printf("\n-------------\n", i);
  }

  //   printf("\nvalue: %d", *(int *)(hashmap->array[i]));
  // }
  printf("\n%p", hashmap);
  // Hashmap *hashmap2 = newHashmap("string", "string");
  // hashmap2->hashmapPut(hashmap2, "hola", "daniel");
  // hashmap2->hashmapPut(hashmap2, "carola", "miguel");
}
// [[1600, 0],
//  [1700, 100],
//  [1800, 200],
//  [1900, 300],
//  [2000, 400],
//  [2100, 500],
//  [2200, 600],
//  [2300, 700],
//  [2400, 800],
//  [2500, 900],
//  [2600, 1000],
//  [2700, 1100],
//  [2800, 1200],
//  [2900, 1300],
//  [3000, 1400],
//  [3100, 1500]]
//
