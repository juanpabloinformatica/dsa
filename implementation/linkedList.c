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
  // ptrLinkedList->getHashmapNode = getHashmapNode;
  return ptrLinkedList;
}
static void _showList(LinkedListNode *linkedListNode) {
  if (linkedListNode == NULL) {
    return;
  }
  if (linkedListNode->next == NULL) {
    printf("%i  ", *(int *)linkedListNode->element);
  } else {
    printf("%i -> ", *(int *)linkedListNode->element);
  }
  _showList(linkedListNode->next);
}
void showLinkedList(LinkedList *linkedList) {
  // i do this wrapper to been able to execute the recursion.
  LinkedListNode *linkedListNode = linkedList->head;
  _showList(linkedListNode);
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
    if (antHead == NULL) {
      antHead = head;
      head = head->next;
      free(antHead);
      return;
    } else {
      antHead->next = head->next;
      free(head);
      return;
    }
    // printf("\nANT_VALUE: %d", *(int *)antHead->element);
    // printf("\nANT_VALUE: %d", *(int *)antHead->element);
    // return;
  }
  antHead = head;
  head = head->next;
  _deleteNode(head, antHead, node);
}
void deleteLinkedListNode(LinkedList *linkedList, LinkedListNode *node) {
  // printf("I am here");
  LinkedListNode *antHead = NULL;
  // printf("i pass here");
  LinkedListNode *head = linkedList->head;
  // printf("HEAD NEXT PTR: %p", head->next);
  _deleteNode(head, antHead, node);
  // printf("HEAD NEXT PTR: %p", head);


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
