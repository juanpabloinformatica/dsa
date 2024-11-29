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
  // void (*recAddLinkedListNode)(LinkedList *linkedList, LinkedListNode *node);
  // void (*recAddLinkedListNode)(LinkedListNode *head, LinkedListNode *node);
  // void (*recShowLinkedList)(LinkedListNode *head);
  // void (*recDeleteLinkedListNode)(LinkedListNode *head, LinkedListNode
  // *node);
  void (*recAddLinkedListNode)(LinkedList *linkedList, LinkedListNode *node);
  void (*recShowLinkedList)(LinkedList *linkedList);
  void (*recDeleteLinkedListNode)(LinkedList *linkedList,
                                  LinkedList *antLinkedList,
                                  LinkedListNode *node);
  // void (*addNode)(LinkedList *linkedList, LinkedListNode *node);
  // void (*showLinkedList)(LinkedListNode *node);
  // void (*showLinkedListIterative)(LinkedListNode *node);
  // LinkedListNode *(*deleteNode)(LinkedListNode *antNode, LinkedListNode
  // *node,
  //                               void *key);
  // HashmapNode *(*getHashmapNode)(LinkedListNode *node, void *key);
};
LinkedListNode *newLinkedListNode(void *value);
LinkedList *newLinkedList();
HashmapNode *newHashmapNode(void *key, void *value);
// RECURSIVE
// void recAddLinkedListNode(LinkedList *linkedList, LinkedListNode *node);
// void recShowLinkedList(LinkedList *linkedList);
void recAddLinkedListNode(LinkedList *linkedList, LinkedListNode *node);
void recShowLinkedList(LinkedList *linkedList);
void recDeleteLinkedListNode(LinkedList *linkedList, LinkedList *antLinkedList,
                             LinkedListNode *node);
// void showLinkedList(LinkedList *linkedList);
// void showLinkedList(LinkedListNode *node);
// void showLinkedListNormalNode(LinkedListNode *node);
// void showLinkedListHashmapNode(LinkedListNode *node);
// // void deleteNode(LinkedListNode *antNode, LinkedListNode *node, void
// *value); void removeNode(LinkedListNode *linkedList, LinkedListNode *node);
// LinkedListNode *deleteNode(LinkedListNode *antNode, LinkedListNode *node,
//                            void *key);
// void showLinkedListIterative(LinkedListNode *node);
// HashmapNode *getHashmapNode(LinkedListNode *node, void *key);
// LinkedListNode *getLinkedListNode(LinkedListNode *node, void *value);
//
// void destroyLinkedList();
// void destroyHashmapNode(HashmapNode *hashmapNode);
// ITERATIVE
// void showList(LinkedList *ptrLinkedList);
// static void _showList(LinkedListNode* linkedListNode);
#endif
