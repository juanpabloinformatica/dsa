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
  ptrLinkedList->recAddLinkedListNode = recAddLinkedListNode;
  ptrLinkedList->recShowLinkedList = recShowLinkedList;
  ptrLinkedList->recDeleteLinkedListNode = recDeleteLinkedListNode;
  // ptrLinkedList->addNode = addNode;
  // ptrLinkedList->showLinkedList = showLinkedList;
  // ptrLinkedList->deleteNode = deleteNode;
  // ptrLinkedList->getHashmapNode = getHashmapNode;
  return ptrLinkedList;
}
// void addNode(LinkedList *linkedList, LinkedListNode *node) {
//   if (linkedList->head == NULL) {
//     linkedList->head = node;
//   } else {
//     node->next = linkedList->head;
//     linkedList->head = node;
//   }
// }
//
void recShowLinkedList(LinkedList *linkedList) {
  if (linkedList->head == NULL) {
    return;
  }
  LinkedList *tmpLinkedList = linkedList;
  LinkedListNode *tmpLinkedListNode = (LinkedListNode *)linkedList->head;
  printf("%d ->", *(int *)tmpLinkedListNode->element);
  tmpLinkedList->head = tmpLinkedList->head->next;
  recShowLinkedList(tmpLinkedList);
}
void recAddLinkedListNode(LinkedList *linkedList, LinkedListNode *node) {
  if (linkedList->head == NULL) {
    linkedList->head = node;
    return;
  }
  LinkedList *tmpLinkedList = linkedList;
  if (tmpLinkedList->head->next == NULL) {
    tmpLinkedList->head->next = node;
    return;
  }
  tmpLinkedList->head = tmpLinkedList->head->next;
  recAddLinkedListNode(tmpLinkedList, node);
}
void recDeleteLinkedListNode(LinkedList *linkedList, LinkedListNode *node) {}
// design the recursive function
// LinkedListNode *deleteNode(LinkedListNode *antNode, LinkedListNode *node,
//                            void *value) {
//   if (node == NULL) {
//     return NULL;
//   }
//   if (*(int *)node->element == *(int *)value) {
//     antNode->next = node->next;
//     free(node);
//     return NULL;
//   }
//   deleteNode(node, node->next, value);
//   return node;
// }

// LinkedListNode *deleteNode(LinkedListNode *antNode, LinkedListNode *node,
//                            void *value) {
//   if (node == NULL) {
//     return NULL;
//   }
//   if (*(int *)node->element == *(int *)value) {
//     antNode->next = node->next;
//     free(node);
//     return NULL;
//   }
//   deleteNode(node, node->next, value);
//   return node;
// }

// void recShowLinkedList(LinkedListNode *head) {
//   if (head == NULL) {
//     return;
//   }
//   if (head->next == NULL) {
//     printf(" %i ", *(int *)head->element);
//   } else {
//     printf(" %i ->", *(int *)head->element);
//   }
//   head = head->next;
//   recShowLinkedList(head);
// }
// void showLinkedListNormalNode(LinkedListNode *node) {
//   if (node == NULL) {
//     return;
//   }
//   if (node->next == NULL) {
//     printf(" %i ", *(int *)node->element);
//   } else {
//     printf(" %i ->", *(int *)node->element);
//   }
//   node = node->next;
//   recShowLinkedList(node);
// }
// bool isHashmapNode(LinkedListNode *node) {
//
// }

// void showLinkedListHashmapNode(LinkedListNode *node) {
//   if (node == NULL) {
//     return;
//   }
//   HashmapNode *hashmapNode = (HashmapNode *)node->element;
//   if (node->next == NULL) {
//     printf(" %i\n ", *(int *)hashmapNode->value);
//   } else {
//     printf(" %i ->", *(int *)hashmapNode->value);
//   }
//   node = node->next;
//   showLinkedList(node);
// }
// void showLinkedList(LinkedListNode *node) {
//   // assert(sizeof(*(int *)node->element) == sizeof(int) ||
//   //        ((HashmapNode *)(node->element))->key != NULL &&
//   //            ((HashmapNode *)(node->element))->value != NULL);
//   //
//   // if (sizeof(*(int *)node->element) == sizeof(int)) {
//   //   showLinkedListNormalNode(node);
//   // } else {
//   //   showLinkedListHashmapNode(node);
//   // }
//   showLinkedListHashmapNode(node);
// }
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
