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
HashmapNode *newHashmapNode(void *key, void *value) {
  HashmapNode *ptrHashmapNode = (HashmapNode *)malloc(sizeof(HashmapNode));
  ptrHashmapNode->key = key;
  ptrHashmapNode->value = value;
  return ptrHashmapNode;
}
void hashmapPut(Hashmap *hashmap, void *key, void *value) {
  assert(strcmp(hashmap->keyType, HASHMAP_TYPE_NUMBER) == 0 ||
         strcmp(hashmap->keyType, HASHMAP_TYPE_STRING) == 0);
  int getIndex = hashFunction(hashmap, key);
  if (hashmap->array[getIndex] == NULL) {
    LinkedList *list = newLinkedList();
    HashmapNode *hashmapNode = newHashmapNode(key, value);
    LinkedListNode *node = newLinkedListNode(hashmapNode);
    list->addNode(list, node);
    hashmap->array[getIndex] = list;
  } else {
    LinkedList *list = hashmap->array[getIndex];
    // I need to add a node but the node has to have the value and the key
    // why???
    // because at the moment of looking different keys can return the same index
    // bucket so I need to verify the key and the value in each node at the
    // moment of traversing the bucket list
    HashmapNode *hashmapNode = newHashmapNode(key, value);
    LinkedListNode *node = newLinkedListNode(hashmapNode);
    list->addNode(list, node);
    list->showLinkedList(list->head);
  }
}
void destroyHashmapNode(HashmapNode *hashmapNode) {
  free(hashmapNode->key);
  free(hashmapNode->value);
  free(hashmapNode);
}
void hashmapGet(Hashmap *hashmap, void *key) {}
void hashmapRemove(Hashmap *hashmap, void *key) {}
bool hashmapContainsKey(Hashmap *hashmap, void *key) { return true; }
bool hashmapContainsValue(Hashmap *hashmap, void *element) { return true; }
void destroyHashmap(Hashmap *hashmap) {
  free(hashmap->keyType);
  free(hashmap->valueType);
  free(hashmap);
}
