#include "linkedList.h"
#include <string.h>

LinkedListNode *newLinkedListNode(void *value) {
  assert(value != NULL);
  LinkedListNode *ptrLinkedListNode =
      (LinkedListNode *)malloc(sizeof(LinkedListNode));
  ptrLinkedListNode->element = value;
  ptrLinkedListNode->next = NULL;

  return ptrLinkedListNode;
}

HashmapNode *newHashmapNode(void *key, void *value) {
  assert(key != NULL && value != NULL);
  HashmapNode *ptrHashmapNode = (HashmapNode *)malloc(sizeof(HashmapNode));
  ptrHashmapNode->key = key;
  ptrHashmapNode->value = value;
  return ptrHashmapNode;
}

LinkedList *newLinkedList() {
  LinkedList *ptrLinkedList = (LinkedList *)malloc(sizeof(LinkedList));
  ptrLinkedList->head = NULL;
  ptrLinkedList->addLinkedList = addLinkedList;
  ptrLinkedList->showLinkedListNode = showLinkedListNode;
  ptrLinkedList->deleteLinkedListNode = deleteLinkedListNode;
  ptrLinkedList->getLinkedListNode = getLinkedListNode;

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
static void *_getNode(LinkedListNode *tmpHead, LinkedListNode *node,
                      char *type) {
  if (tmpHead == NULL) {
    return NULL;
  }
  if (strcmp(type, "hashmap") == 0) {
    HashmapNode *hnh = (HashmapNode *)tmpHead->element;
    HashmapNode *hnn = (HashmapNode *)node->element;
    if (*(int *)hnh->key == *(int *)hnn->key) {
      return tmpHead;
    }
  } else if (strcmp(type, "number") == 0) {
    if (*(int *)tmpHead->element == *(int *)node->element) {
      return tmpHead;
    }
  } else {
    return NULL;
  }

  tmpHead = tmpHead->next;
  _getNode(tmpHead, node, type);
  /* return tmpHead; */
  return tmpHead;
}
void *getLinkedListNode(LinkedList *linkedList,
                        LinkedListNode *linkedListNode) {
  assert(linkedList != NULL);
  assert(linkedListNode != NULL);
  bool isHashmapNode = true;
  bool isNormalNode = false;

  if (isHashmapNode == true) {
    // HashmapNode *gHmn = _getNode(linkedList->head, linkedListNode,
    // "hashmap");
    LinkedListNode *ln;
    ln = _getNode(linkedList->head, linkedListNode, "hashmap");
    return ln;
  }
  if (isNormalNode == true) {
    LinkedListNode *ln = _getNode(linkedList->head, linkedListNode, "number");
    return ln;
  }
  return NULL;
}
void showLinkedListNode(LinkedList *linkedList) {
  assert(linkedList != NULL);
  // i do this wrapper to been able to execute the recursion.
  // just for testing
  bool isNumberNode = false;
  bool isHashmapNode = true;

  if (isNumberNode == true) {
    LinkedListNode *linkedListNode = linkedList->head;
    _showNormalList(linkedListNode);
  }
  if (isHashmapNode == true) {
    ////printf("I enter here");
    LinkedListNode *linkedListNode = linkedList->head;
    _showHashmapList(linkedListNode);
  }
}

static void _addNode(LinkedListNode *linkedListNode,
                     LinkedListNode *linkedListNewNode, LinkedListNode **head) {
  if ((*head) == NULL) {
    *head = linkedListNewNode;
    return;
  }
  if (linkedListNode->next == NULL) {
    linkedListNode->next = linkedListNewNode;
    return;
  }
  _addNode(linkedListNode->next, linkedListNewNode, head);
}
void addLinkedList(LinkedList *linkedList, LinkedListNode *node) {
  assert(linkedList != NULL);
  assert(node != NULL);
  _addNode(linkedList->head, node, &linkedList->head);
}

static void _deleteNode(LinkedListNode *tmpHead, LinkedListNode *antHead,
                        LinkedListNode *node, LinkedListNode **head) {
  if (*(int *)(*head)->element == *(int *)node->element) {
    antHead = *head;
    *head = (*head)->next;
    destroyNode(antHead);
    return;
  }
  if (tmpHead == NULL) {
    return;
  }
  if (*(int *)tmpHead->element == *(int *)node->element) {
    if (antHead != NULL) {
      antHead->next = tmpHead->next;
    }
    destroyNode(tmpHead);
    return;
  }
  antHead = tmpHead;
  tmpHead = tmpHead->next;
  _deleteNode(tmpHead, antHead, node, head);
}
void deleteLinkedListNode(LinkedList *linkedList, LinkedListNode *node) {
  LinkedListNode *antHead = NULL;
  _deleteNode(linkedList->head, antHead, node, &linkedList->head);
}

void destroyHashmapNode(HashmapNode *hashmapNode) {
  free(hashmapNode);
  hashmapNode = NULL;
}
void destroyNode(LinkedListNode *linkedListNode) {
  free(linkedListNode);
  linkedListNode = NULL;
}
static void _destroyNodes(LinkedListNode *antTmpHead, LinkedListNode *tmpHead) {
  if (tmpHead == NULL) {
    return;
  }
  destroyNode(antTmpHead);
  antTmpHead = tmpHead;
  _destroyNodes(antTmpHead, tmpHead->next);
}

void destroyLinkedList(LinkedList *linkedList) {
  _destroyNodes(linkedList->head, linkedList->head->next);
  free(linkedList);
  linkedList = NULL;
}
