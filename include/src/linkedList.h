#pragma once
// #ifndef __LINKED_LIST__
// #define __LINKED_LIST__
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
  void (*addLinkedList)(LinkedList *linkedList, LinkedListNode *node);
  void (*showLinkedListNode)(LinkedList *linkedList);
  void (*deleteLinkedListNode)(LinkedList *linkedList, LinkedListNode *node);
  void *(*getLinkedListNode)(LinkedList *linkedList, LinkedListNode *node);
};
LinkedListNode *newLinkedListNode(void *value);
LinkedList *newLinkedList(void);
HashmapNode *newHashmapNode(void *key, void *value);
// RECURSIVE
void addLinkedList(LinkedList *linkedList, LinkedListNode *node);
void showLinkedListNode(LinkedList *linkedList);
void deleteLinkedListNode(LinkedList *linkedList, LinkedListNode *node);
void *getLinkedListNode(LinkedList *linkedList, LinkedListNode *node);
void destroyLinkedList(LinkedList* linkedList);
void destroyNode(LinkedListNode* node);
// #endif
