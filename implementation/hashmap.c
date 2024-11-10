#include "hashmap.h"

Hashmap *newHashmap() {
  Hashmap *ptrHashmap = (Hashmap *)malloc(sizeof(Hashmap));
  ptrHashmap->hashmapPut = hashmapPut;
  ptrHashmap->hashmapGet = hashmapGet;
  ptrHashmap->hashmapRemove = hashmapRemove;
  ptrHashmap->hashmapContainsKey = hashmapContainsKey;
  ptrHashmap->hashmapContainsValue = hashmapContainsValue;
  return ptrHashmap;
}
int hashFunction(void *element) {}
void hashmapPut(Hashmap *hashmap, void *element) {
  // get hash
  int index = hashFunction(element);
  if (hashmap->array[index] == NULL) {
    hashmap->array[index] = element;
  } else {
  }
}
void hashmapGet(void *key) {}
void hashmapRemove(void *key) {}
bool hashmapContainsKey(void *key) {}
bool hashmapContainsValue(void *element) {}
void destroyHashmap(Hashmap *hashmap) {}
