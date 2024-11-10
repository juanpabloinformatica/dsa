#ifndef __HASH_MAP__
#define __HASH_MAP__
#include <stdbool.h>
#include <stdlib.h>
#define ARRAY_MAX_SIZE 10
typedef struct Hashmap Hashmap;
struct Hashmap {
  void *array[ARRAY_MAX_SIZE];
  void (*hashmapPut)(Hashmap *hashmap, void *element);
  void (*hashmapGet)(Hashmap* hashmap,void *key);
  void (*hashmapRemove)(Hashmap* hashmap,void *key);
  bool (*hashmapContainsKey)(Hashmap* hashmap,void *key);
  bool (*hashmapContainsValue)(Hashmap *hashmap, void *element);
};
Hashmap *newHashmap();
int hashFunction();
void hashmapPut(Hashmap *hashmap, void *element);
void hashmapGet(void *key);
void hashmapRemove(void *key);
bool hashmapContainsKey(void *key);
bool hashmapContainsValue(void *element);
void destroyHashmap(Hashmap *hashmap);
#endif
