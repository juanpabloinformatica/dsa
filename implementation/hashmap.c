#include "hashmap.h"
#include "linkedList.h"
#include <stdint.h>
Hashmap *newHashmap(char *keyType, char *valueType) {
  assert(strcmp(keyType, "number") == 0 || strcmp(keyType, "string") == 0);
  assert(strcmp(valueType, "number") == 0 || strcmp(valueType, "string") == 0);

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
  return ptrHashmap;
}
static int _stringGetSum(int sum, char *key) {
  if (!*(char *)key) {
    return 0;
  }
  sum += *(char *)key;
  _stringGetSum(sum, key + 1);
  return sum;
}
int hashFunction(Hashmap *hashmap, void *key) {
  assert(hashmap != NULL);
  assert(hashmap->hashmapContainsKey(hashmap, key) == true);
  assert(strcmp(hashmap->keyType, HASHMAP_TYPE_NUMBER) == 0 ||
         strcmp(hashmap->keyType, HASHMAP_TYPE_STRING) == 0);
  if (strcmp(hashmap->keyType, HASHMAP_TYPE_STRING) == 0) {
    int sum = _stringGetSum(0, key);
    return sum % MODULE_FACTOR;
  } else {
    int keyNumber = *(int *)key;
    return keyNumber % MODULE_FACTOR;
  }
}
void hashmapPut(Hashmap *hashmap, void *key, void *value) {
  assert(hashmap != NULL);
  assert(key != NULL);
  assert(value != NULL);
  assert(strcmp(hashmap->keyType, HASHMAP_TYPE_NUMBER) == 0 ||
         strcmp(hashmap->keyType, HASHMAP_TYPE_STRING) == 0);
  int getIndex = hashFunction(hashmap, key);
  if (hashmap->array[getIndex] != NULL) {
    LinkedList *list = hashmap->array[getIndex];
    HashmapNode *hashmapNode = newHashmapNode(key, value);
    LinkedListNode *node = newLinkedListNode(hashmapNode);
    list->addLinkedList(list, node);
    list->showLinkedListNode(list);
    return;
  }
  LinkedList *list = newLinkedList();
  HashmapNode *hashmapNode = newHashmapNode(key, value);
  LinkedListNode *node = newLinkedListNode(hashmapNode);
  list->addLinkedList(list, node);
  hashmap->array[getIndex] = list;
}
void *hashmapGet(Hashmap *hashmap, void *key) {
  assert(hashmap->hashmapContainsKey(hashmap, key) == true);
  // int hashmapArrayLength = sizeof(hashmap->array) /
  // sizeof(hashmap->array[0]); bool keyExist = false; HashmapNode *hashmapNode
  // = NULL;
  int keyIndex = hashFunction(hashmap, key);
  LinkedList *linkedList = ((LinkedList *)hashmap->array[keyIndex]);
  /* if (linkedList != NULL) { */
  HashmapNode *hashmapNode = newHashmapNode(key, NULL);
  LinkedListNode *lLHNode = newLinkedListNode(hashmapNode);
  LinkedListNode *lln = linkedList->getLinkedListNode(linkedList, lLHNode);
  return lln;
  /* } */
  /* return NULL; */
}
void hashmapRemove(Hashmap *hashmap, void *key) {
  assert(hashmap != NULL);
  assert(hashmap->hashmapContainsKey(hashmap, key) == true);
  int keyIndex = hashFunction(hashmap, key);
  LinkedList *linkedList = ((LinkedList *)(hashmap->array)[keyIndex]);
  /* if (linkedList != NULL) { */
  HashmapNode *hashmapNode = newHashmapNode(key, NULL);
  LinkedListNode *lLNode = newLinkedListNode(hashmapNode);
  linkedList->deleteLinkedListNode(linkedList, lLNode);
  /* } */
}
bool hashmapContainsKey(Hashmap *hashmap, void *key) {
  assert(hashmap != NULL);
  LinkedListNode *gottenNode = hashmap->hashmapGet(hashmap, key);
  return (gottenNode != NULL) ? true : false;
}
// bool hashmapContainsValue(Hashmap *hashmap, void *element) { return true; }
void _destroyHashmapLists(void *array[], int arraySize, int i) {
  if (i == arraySize - 1) {
    return;
  }
  destroyLinkedList((LinkedList *)(array[i]));
  _destroyHashmapLists(array, arraySize, ++i);
}
void destroyHashmap(Hashmap *hashmap) {
  _destroyHashmapLists(hashmap->array, ARRAY_MAX_SIZE, 0);
  free(hashmap->keyType);
  free(hashmap->valueType);
  free(hashmap);
}
