#include "dsa.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  LinkedList *linkedList = newLinkedList();
  int *nextValue = malloc(sizeof(int));
  int *nextNextValue = malloc(sizeof(int));
  int *nextNextNextValue = malloc(sizeof(int));
  *nextValue = 10;
  *nextNextValue = 20;
  *nextNextNextValue = 30;
  LinkedListNode *next = newLinkedListNode((void *)nextValue);
  LinkedListNode *nextNext = newLinkedListNode((void *)nextNextValue);
  LinkedListNode *nextNextNext = newLinkedListNode((void *)nextNextNextValue);
  addNode(linkedList, next);
  addNode(linkedList, nextNext);
  addNode(linkedList, nextNextNext);
  linkedList->head = deleteNode(NULL, linkedList->head, (void *)nextValue);
  printf("\nAddress at the beginning: %p", linkedList->head);
  showLinkedList(linkedList->head);
  printf("\nAddress at the end: %p", linkedList->head);

  // both are the same because before i was passing the linked list so it was
  // creating another variable with the same linkedlist address but was
  // modificating directly the head of the linked list, now if i pass only the
  // head is creating another variable with the same address so the original
  // rest the same
  // free(nextValue);
  free(nextNextValue);
  free(nextNextNextValue);
  free(linkedList);
  return 0;
}
LinkedListNode *newLinkedListNode(void *value) {
  LinkedListNode *ptrLinkedListNode =
      (LinkedListNode *)malloc(sizeof(LinkedListNode));
  ptrLinkedListNode->element = value;
  ptrLinkedListNode->next = NULL;

  return ptrLinkedListNode;
}
LinkedList *newLinkedList() {
  LinkedList *ptrLinkedList = (LinkedList *)malloc(sizeof(LinkedList));
  ptrLinkedList->head = NULL;
  return ptrLinkedList;
}
// i want to do everything recursive
void addNode(LinkedList *linkedList, LinkedListNode *node) {
  // for starting
  if (linkedList->head == NULL) {
    linkedList->head = node;
  } else {
    node->next = linkedList->head;
    linkedList->head = node;
  }
}
// void deleteNode(LinkedListNode *antNode, LinkedListNode *node, void *value) {
//   if (node == NULL) {
//     return;
//   }
//   if (*(int *)node->element == *(int *)value && antNode == NULL) {
//     node = node->next;
//     return;
//   }
//   if (*(int *)node->element == *(int *)value) {
//     antNode->next = node->next;
//     free(node);
//     return;
//   }
//   deleteNode(node, node->next, value);
// }
// this works like that because what is happening is that the return do an stack
// pop and retake from the end of the previous line in the stack element top-1
//
LinkedListNode *deleteNode(LinkedListNode *antNode, LinkedListNode *node,
                           void *value) {
  if (node == NULL) {
    return NULL;
  }
  if (*(int *)node->element == *(int *)value) {
    antNode->next = node->next;
    free(node);
    return NULL;
  }
  deleteNode(node, node->next, value);
  return node;
}
void showLinkedList(LinkedListNode *node) {
  if (node == NULL) {
    return;
  }
  printf("\nvalue: %i", *(int *)node->element);
  node = node->next;
  showLinkedList(node);
}
// void showLinkedList(LinkedList *linkedList) {
//   if (linkedList->head == NULL) {
//     return;
//   }
//   printf("\nvalue: %i", *(int *)linkedList->head->element);
//   linkedList->head = linkedList->head->next;
//   showLinkedList(linkedList);
// }
