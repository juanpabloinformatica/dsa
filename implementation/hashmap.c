#include "hashmap.h"
#include <stdint.h>
Hashmap *newHashmap(char *keyType, char *valueType) {
  Hashmap *ptrHashmap = (Hashmap *)malloc(sizeof(Hashmap));
  ptrHashmap->keyType = (char *)malloc(sizeof(char) * strlen(keyType));
  ptrHashmap->valueType = (char *)malloc(sizeof(char) * strlen(valueType));
  ptrHashmap->counter = 0;
  memcpy(ptrHashmap->keyType, keyType, strlen(keyType));
  memcpy(ptrHashmap->valueType, valueType, strlen(valueType));
  ptrHashmap->hashmapPut = hashmapPut;
  ptrHashmap->hashmapGet = hashmapGet;
  ptrHashmap->hashmapRemove = hashmapRemove;
  ptrHashmap->hashmapContainsKey = hashmapContainsKey;
  ptrHashmap->hashmapContainsValue = hashmapContainsValue;

  return ptrHashmap;
}
int hashFunction(Hashmap *hashmap, void *key) {
  assert(strcmp(hashmap->keyType, HASHMAP_TYPE_NUMBER) == 0 ||
         strcmp(hashmap->keyType, HASHMAP_TYPE_STRING) == 0);
  if (strcmp(hashmap->keyType, HASHMAP_TYPE_STRING) == 0) {
    int sum = 0;
    while (*(char *)key) {
      sum += *(char *)key;
      key++;
    }
    return sum % MODULE_FACTOR;
  } else {
    int keyNumber = *(int *)key;
    return keyNumber % MODULE_FACTOR;
  }
}
void hashmapPut(Hashmap *hashmap, void *key, void *value) {
  assert(strcmp(hashmap->keyType, HASHMAP_TYPE_NUMBER) == 0 ||
         strcmp(hashmap->keyType, HASHMAP_TYPE_STRING) == 0);
  int getIndex = hashFunction(hashmap, key);
  if (hashmap->array[getIndex] == NULL) {
    LinkedList *list = newLinkedList();
    HashmapNode *hashmapNode = newHashmapNode(key, value);
    LinkedListNode *node = newLinkedListNode(hashmapNode);
    list->addLinkedListNode(list, node);
    // list->showLinkedList(list);
    hashmap->array[getIndex] = list;
    // LinkedList *listT = hashmap->array[getIndex];
    // listT->showLinkedList(listT);
  } else {
    LinkedList *list = hashmap->array[getIndex];
    // I need to add a node but the node has to have the value and the key
    // why???
    // because at the moment of looking different keys can return the same index
    // bucket so I need to verify the key and the value in each node at the
    // moment of traversing the bucket list
    HashmapNode *hashmapNode = newHashmapNode(key, value);
    LinkedListNode *node = newLinkedListNode(hashmapNode);
    list->addLinkedListNode(list, node);
    // list->showLinkedList(list);
  }
}
// void destroyHashmapNode(HashmapNode *hashmapNode) {
//   free(hashmapNode->key);
//   free(hashmapNode->value);
//   free(hashmapNode);
// }
// for the moment it will return integers
// void *hashmapGet(Hashmap *hashmap, void *key) {
//   int hashmapLength = sizeof(hashmap->array) / sizeof(hashmap->array[0]);
//   bool keyExist = false;
//   HashmapNode *hashmapNode = NULL;
//   // int keyIndex =
//   for (int i = 0; i < hashmapLength; i++) {
//     LinkedList *linkedList = (LinkedList *)hashmap->array[i];
//     hashmapNode = linkedList->getHashmapNode(linkedList->head, key);
//     if (hashmapNode != NULL) {
//       return hashmapNode;
//     }
//     // if ((hashmapNode = linkedList->getHashmapNode(linkedList->head,
//     // key)!=NULL)) traverse linkedlist
//     //   HashmapNode *hashmapNode =
//     //       (HashmapNode *)((*(LinkedList *)(hashmap->array[i])).head);
//     //
//     // LinkedListNode *linkedListNode =
//     //     (LinkedListNode *)(*(LinkedList *)(hashmap->array[i])).head;
//
//     // for integer by the moment
//     // if (*(int *)hashmapNode->key == *(int *)key) {
//     //   keyExist = true;
//     //   break;
//     // }
//   }
// }
int hashmapGet(Hashmap *hashmap, void *key) {
  int hashmapLength = sizeof(hashmap->array) / sizeof(hashmap->array[0]);
  bool keyExist = false;
  HashmapNode *hashmapNode = NULL;
  int keyIndex = hashFunction(hashmap, key);
  LinkedList *linkedList = (LinkedList *)hashmap->array[keyIndex];
  if (linkedList != NULL) {
    // hashmapNode = linkedList->getHashmapNode(linkedList->head, key);
    if (hashmapNode != NULL) {
      return *(int *)hashmapNode->value;
    }
  }
  return -1;
}
void hashmapRemove(Hashmap *hashmap, void *key) {
  int hashmapLength = sizeof(hashmap->array) / sizeof(hashmap->array[0]);
  bool keyExist = false;
  HashmapNode *hashmapNode = NULL;
  int keyIndex = hashFunction(hashmap, key);
  LinkedList *linkedList = (LinkedList *)hashmap->array[keyIndex];
  if (linkedList != NULL) {
    // HashmapNode *hashmapNode =
    // linkedList->getHashmapNode(linkedList->head, key);
    // printf("Removing node ->  key:%i -> key:%i", *(int *)hashmapNode->key,
    printf("\nBefore removing it:");
    // showLinkedList(linkedList->head);
    // *(int *)hashmapNode->key);
    // I need to do all of this better  for sure
    LinkedListNode *antptr = newLinkedListNode(NULL);
    // linkedList->head = linkedList->deleteNode(antptr, linkedList->head, key);
    printf("\nAfter removing it:");
    // showLinkedList(linkedList->head);
  }
}
bool hashmapContainsKey(Hashmap *hashmap, void *key) { return true; }
bool hashmapContainsValue(Hashmap *hashmap, void *element) { return true; }
void destroyHashmap(Hashmap *hashmap) {
  free(hashmap->keyType);
  free(hashmap->valueType);
  free(hashmap);
}
