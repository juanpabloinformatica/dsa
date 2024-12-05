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
  // ptrHashmap->hashmapContainsValue = hashmapContainsValue;

  return ptrHashmap;
}
int hashFunction(Hashmap *hashmap, void *key) {
  assert(strcmp(hashmap->keyType, HASHMAP_TYPE_NUMBER) == 0 ||
         strcmp(hashmap->keyType, HASHMAP_TYPE_STRING) == 0);
  if (strcmp(hashmap->keyType, HASHMAP_TYPE_STRING) == 0) {
    int sum = 0;
    // this should be done also with recursion
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
    hashmap->array[getIndex] = list;
  } else {
    LinkedList *list = hashmap->array[getIndex];
    HashmapNode *hashmapNode = newHashmapNode(key, value);
    LinkedListNode *node = newLinkedListNode(hashmapNode);
    list->addLinkedListNode(list, node);
    list->showLinkedList(list);
  }
}
// void destroyHashmapNode(HashmapNode *hashmapNode) {
//   free(hashmapNode->key);
//   free(hashmapNode->value);
//   free(hashmapNode);
// }
void *hashmapGet(Hashmap *hashmap, void *key) {
  // int hashmapArrayLength = sizeof(hashmap->array) /
  // sizeof(hashmap->array[0]); bool keyExist = false; HashmapNode *hashmapNode
  // = NULL;
  int keyIndex = hashFunction(hashmap, key);
  LinkedList *linkedList = ((LinkedList *)hashmap->array[keyIndex]);
  if (linkedList != NULL) {
    printf("linkedList exist");
    HashmapNode *hashmapNode = newHashmapNode(key, NULL);
    LinkedListNode *lLHNode = newLinkedListNode(hashmapNode);
    LinkedListNode *lln = linkedList->getLinkedListNode(linkedList, lLHNode);
    return lln;
  }
  return NULL;
}
void hashmapRemove(Hashmap *hashmap, void *key) {
  int hashmapLength = sizeof(hashmap->array) / sizeof(hashmap->array[0]);
  bool keyExist = false;
  HashmapNode *hashmapNode = NULL;
  int keyIndex = hashFunction(hashmap, key);
  LinkedList *linkedList = ((LinkedList *)(hashmap->array)[keyIndex]);
  if (linkedList != NULL) {
    HashmapNode *hashmapNode = newHashmapNode(key, NULL);
    LinkedListNode *lLNode = newLinkedListNode(hashmapNode);
    linkedList->deleteLinkedListNode(linkedList, lLNode);
  }
}
bool hashmapContainsKey(Hashmap *hashmap, void *key) {
  LinkedListNode *gottenNode = hashmap->hashmapGet(hashmap, key);
  return (gottenNode != NULL) ? true : false;
}
// bool hashmapContainsValue(Hashmap *hashmap, void *element) { return true; }
void destroyHashmap(Hashmap *hashmap) {
  free(hashmap->keyType);
  free(hashmap->valueType);
  free(hashmap);
}
