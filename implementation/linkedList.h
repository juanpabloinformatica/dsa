#ifndef __LINKED_LIST__
#define __LINKED_LIST__
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct HashmapNode HashmapNode;
struct HashmapNode {
  void *key;
  void *value;
};
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
  void (*showLinkedListIterative)(LinkedListNode *node);
  LinkedListNode *(*deleteNode)(LinkedListNode *antNode, LinkedListNode *node,
                                void *value);
  HashmapNode *(*getHashmapNode)(LinkedListNode *node, void *key);
};
LinkedListNode *newLinkedListNode(void *value);
HashmapNode *newHashmapNode(void *key, void *value);
LinkedList *newLinkedList();
void addNode(LinkedList *linkedList, LinkedListNode *node);
// void showLinkedList(LinkedList *linkedList);
void showLinkedList(LinkedListNode *node);
void showLinkedListNormalNode(LinkedListNode *node);
void showLinkedListHashmapNode(LinkedListNode *node);
// void deleteNode(LinkedListNode *antNode, LinkedListNode *node, void *value);
LinkedListNode *deleteNode(LinkedListNode *antNode, LinkedListNode *node,
                           void *value);
void showLinkedListIterative(LinkedListNode *node);
HashmapNode *getHashmapNode(LinkedListNode *node, void *key);
LinkedListNode *getLinkedListNode(LinkedListNode *node, void *value);

void destroyLinkedList();
void destroyHashmapNode(HashmapNode *hashmapNode);
#endif
