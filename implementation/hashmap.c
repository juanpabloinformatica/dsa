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
    // printf("\nin here\n");
    // char *keyString;
    // memcpy(keyString, key, strlen(key));
    int sum = 0;
    while (*(char *)key) {
      // printf("%c", *(char *)key);
      sum += *(char *)key;
      key++;
    }

    printf("\nModule factor: %d ", MODULE_FACTOR);
    printf("\nvalue: %d", sum % MODULE_FACTOR);
    return sum % MODULE_FACTOR;
  } else if (strcmp(hashmap->keyType, HASHMAP_TYPE_NUMBER) == 0) {
    int keyNumber = *(int *)key;
    return keyNumber % MODULE_FACTOR;
  } else {
    return -1;
  }
}
// char *getKeyType(void *key) {}
void hashmapPut(Hashmap *hashmap, void *key, void *value) {
  assert(strcmp(hashmap->keyType, HASHMAP_TYPE_NUMBER) == 0 ||
         strcmp(hashmap->keyType, HASHMAP_TYPE_STRING) == 0);
  if (strcmp(hashmap->keyType, HASHMAP_TYPE_STRING) == 0) {
    // printf("hashmap key is a string.");
    int getIndex = hashFunction(hashmap, key);
    if (hashmap->array[getIndex] == NULL) {
      hashmap->array[getIndex] = value;
      // printf("%d", *(int *)hashmap->array[getIndex]);
    } else {
      // handling collision
    }
  } else if (strcmp(hashmap->keyType, HASHMAP_TYPE_NUMBER) == 0) {
    // printf("hashmap key is a number.");
    int getIndex = hashFunction(hashmap, key);
    if (hashmap->array[getIndex] == NULL) {
      hashmap->array[getIndex] = value;
      // printf("%d", *(int *)hashmap->array[getIndex]);
    } else {
      // handling collision
    }
  } else {
    printf("Not defined yet.");
  }
}
void hashmapGet(Hashmap *hashmap, void *key) {}
void hashmapRemove(Hashmap *hashmap, void *key) {}
bool hashmapContainsKey(Hashmap *hashmap, void *key) { return true; }
bool hashmapContainsValue(Hashmap *hashmap, void *element) { return true; }
void destroyHashmap(Hashmap *hashmap) {}
