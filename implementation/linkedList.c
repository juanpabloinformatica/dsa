#include "linkedList.h"

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
  ptrLinkedList->addNode = addNode;
  ptrLinkedList->showLinkedList = showLinkedList;
  ptrLinkedList->deleteNode = deleteNode;
  return ptrLinkedList;
}
void addNode(LinkedList *linkedList, LinkedListNode *node) {
  if (linkedList->head == NULL) {
    linkedList->head = node;
  } else {
    node->next = linkedList->head;
    linkedList->head = node;
  }
}
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
  if (node->next == NULL) {
    printf(" %i ", *(int *)node->element);
  } else {
    printf(" %i ->", *(int *)node->element);
  }
  node = node->next;
  showLinkedList(node);
}
// void showLinkedListIterative(LinkedListNode *node) {
//   LinkedListNode *tmp = node;
//   printf("[");
//   while (tmp != NULL) {
//     if (tmp->next != NULL) {
//       printf("%d", *(int *)tmp->element);
//     } else {
//       printf("%d ->", *(int *)tmp->element);
//     }
//     if (tmp->next != NULL) {
//       tmp = tmp->next;
//     }
//   }
// printf("]");
// }
// Need to be implemented !!!!!!!!!!
// void destroyLinkedList(){
//
// }
