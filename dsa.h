#ifndef __DSA__
#define __DSA__
typedef struct DynamicArray DynamicArray;
typedef struct HashMap HashMap;
typedef struct Stack Stack;
typedef struct Queue Queue;
typedef struct LinkedListNode LinkedListNode;
struct LinkedListNode {
  void *element;
  LinkedListNode *next;
};
typedef struct LinkedList LinkedList;
struct LinkedList {
  LinkedListNode *head;
};
LinkedListNode *newLinkedListNode(void *value);
LinkedList *newLinkedList();
void addNode(LinkedList *linkedList, LinkedListNode *node);
// void showLinkedList(LinkedList *linkedList);
void showLinkedList(LinkedListNode *node);
// void deleteNode(LinkedListNode *antNode, LinkedListNode *node, void *value);
LinkedListNode *deleteNode(LinkedListNode *antNode, LinkedListNode *node,
                           void *value);
typedef struct BstNode BstNode;
typedef struct Bst Bst;
typedef struct Graph Graph;
#endif
