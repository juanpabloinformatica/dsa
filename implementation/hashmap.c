#include "hashmap.h"
#include <stdint.h>
#
Hashmap *newHashmap() {
  Hashmap *ptrHashmap = (Hashmap *)malloc(sizeof(Hashmap));
  ptrHashmap->hashmapPut = hashmapPut;
  ptrHashmap->hashmapGet = hashmapGet;
  ptrHashmap->hashmapRemove = hashmapRemove;
  ptrHashmap->hashmapContainsKey = hashmapContainsKey;
  ptrHashmap->hashmapContainsValue = hashmapContainsValue;
  return ptrHashmap;
}
int hashFunction(Hashmap *hashmap, void *key, char *type) {

  assert(strcmp(type, "number") == 0 || strcmp(type, "string"));
  if (strcmp(type, "number") == 0) {
    // this warning is good to know nevertheless is assure that a int is passed
    int key = *(int *)key;
    int keyToIndex = key / DIVIDE_FACTOR;
    return keyToIndex;
    // is a number
  } else if (strcmp(type, "string") == 0) {
    return -1;
  } else {
    printf("Not yet implemented.");
    return -1;
  }
}
char* getKeyType(void* key){

}
void hashmapPut(Hashmap *hashmap, void *key, void *value) {
  // get hash
  int index;
  char *type = getKeyType(key);
  if () {
    index = hashFunction(key, );
  } else if () {
    index = hashFunction(key, );
  } else {
  }
  // if (hashmap->array[index] == NULL) {
  //   hashmap->array[index] = value;
  // } else {
  // }
}
void hashmapGet(Hashmap *hashmap, void *key) {}
void hashmapRemove(Hashmap *hashmap, void *key) {}
bool hashmapContainsKey(Hashmap *hashmap, void *key) {}
bool hashmapContainsValue(Hashmap *hashmap, void *element) {}
void destroyHashmap(Hashmap *hashmap) {}
