#include "linkedList.h"

LinkedListNode *newLinkedListNode(void *value) {
  LinkedListNode *ptrLinkedListNode =
      (LinkedListNode *)malloc(sizeof(LinkedListNode));
  ptrLinkedListNode->element = value;
  ptrLinkedListNode->next = NULL;

  return ptrLinkedListNode;
}

HashmapNode *newHashmapNode(void *key, void *value) {
  HashmapNode *ptrHashmapNode = (HashmapNode *)malloc(sizeof(HashmapNode));
  ptrHashmapNode->key = key;
  ptrHashmapNode->value = value;
  return ptrHashmapNode;
}

LinkedList *newLinkedList() {
  LinkedList *ptrLinkedList = (LinkedList *)malloc(sizeof(LinkedList));
  ptrLinkedList->head = NULL;
  ptrLinkedList->addLinkedListNode = addLinkedListNode;
  ptrLinkedList->showLinkedList = showLinkedList;
  ptrLinkedList->deleteLinkedListNode = deleteLinkedListNode;
  return ptrLinkedList;
}
static void _showNormalList(LinkedListNode *linkedListNode) {
  if (linkedListNode == NULL) {
    return;
  }
  if (linkedListNode->next == NULL) {
    printf("%i  ", *(int *)linkedListNode->element);
  } else {
    printf("%i -> ", *(int *)linkedListNode->element);
  }
  _showNormalList(linkedListNode->next);
}

static void _showHashmapList(LinkedListNode *linkedListNode) {
  if (linkedListNode == NULL) {
    return;
  }
  HashmapNode *hn = (HashmapNode *)linkedListNode->element;
  if (linkedListNode->next == NULL) {
    printf("[%i,%i]  ", *(int *)hn->key, *(int *)hn->value);
  } else {
    printf("[%i,%i] -> ", *(int *)hn->key, *(int *)hn->value);
  }
  _showHashmapList(linkedListNode->next);
}
void showLinkedList(LinkedList *linkedList) {
  // i do this wrapper to been able to execute the recursion.
  // just for testing
  bool isNumberNode = false;
  bool isHashmapNode = true;

  if (isNumberNode == true) {
    LinkedListNode *linkedListNode = linkedList->head;
    _showNormalList(linkedListNode);
  }
  if (isHashmapNode == true) {
    printf("\nI enter here");
    LinkedListNode *linkedListNode = linkedList->head;
    _showHashmapList(linkedListNode);
  }
}

static void _addNode(LinkedListNode *linkedListNode,
                     LinkedListNode *linkedListNewNode) {
  if (linkedListNode->next == NULL) {
    linkedListNode->next = linkedListNewNode;
    return;
  }
  _addNode(linkedListNode->next, linkedListNewNode);
}
void addLinkedListNode(LinkedList *linkedList, LinkedListNode *node) {
  if (linkedList->head == NULL) {
    linkedList->head = node;
    return;
  }
  LinkedListNode *linkedListNode = linkedList->head;
  _addNode(linkedListNode, node);
}

static void _deleteNode(LinkedListNode *head, LinkedListNode *antHead,
                        LinkedListNode *node) {
  if (head == NULL) {
    return;
  }
  if (*(int *)head->element == *(int *)node->element) {
    antHead->next = head->next;
    free(head);
    return;
  }
  antHead = head;
  head = head->next;
  _deleteNode(head, antHead, node);
}
void deleteLinkedListNode(LinkedList *linkedList, LinkedListNode *node) {
  // printf("I am here");
  LinkedListNode *antHead = NULL;
  LinkedListNode *head = linkedList->head;
  if (*(int *)linkedList->head->element == *(int *)node->element) {
    antHead = head;
    linkedList->head = linkedList->head->next;
    free(antHead);
    return;
  }
  _deleteNode(head, antHead, node);
}

HashmapNode *getHashmapNode(LinkedListNode *node, void *key) {
  // I will do it iterative by now but then I do it recursively
  LinkedListNode *tmpNode = node;
  HashmapNode *hashmapNode;
  for (; tmpNode->next != NULL; tmpNode = tmpNode->next) {
    // only for integers working
    hashmapNode = (HashmapNode *)(tmpNode->element);
    if (*(int *)hashmapNode->key == *(int *)key) {
      return hashmapNode;
    }
  }
  hashmapNode = (HashmapNode *)(tmpNode->element);
  if (*(int *)hashmapNode->key == *(int *)key) {
    return hashmapNode;
  }
  return NULL;
}

void destroyHashmapNode(HashmapNode *hashmapNode) {
  free(hashmapNode->key);
  free(hashmapNode->value);
  free(hashmapNode);
}
