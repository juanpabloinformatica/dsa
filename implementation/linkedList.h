#ifndef __LINKED_LIST__
#define __LINKED_LIST__
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode LinkedListNode;
struct LinkedListNode {
  void *element;
  LinkedListNode *next;
};
typedef struct LinkedList LinkedList;
struct LinkedList {
  LinkedListNode *head;
  void (*addNode)(LinkedList *linkedList, LinkedListNode *node);
  void (*showLinkedList)(LinkedListNode *node);
  LinkedListNode *(*deleteNode)(LinkedListNode *antNode, LinkedListNode *node,
                                void *value);
};
LinkedListNode *newLinkedListNode(void *value);
LinkedList *newLinkedList();
void addNode(LinkedList *linkedList, LinkedListNode *node);
// void showLinkedList(LinkedList *linkedList);
void showLinkedList(LinkedListNode *node);
// void deleteNode(LinkedListNode *antNode, LinkedListNode *node, void *value);
LinkedListNode *deleteNode(LinkedListNode *antNode, LinkedListNode *node,
                           void *value);
void destroyLinkedList();
#endif
