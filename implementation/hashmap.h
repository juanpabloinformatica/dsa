#ifndef __HASH_MAP__
#define __HASH_MAP__
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// hashfunction Cormen method applied
#define ARRAY_MAX_SIZE 1 << 4
#define DIVIDE_FACTOR (1 << 4) * 10
// #define IS_NUMBER(variable) (())
typedef struct Hashmap Hashmap;
struct Hashmap {
  void *array[ARRAY_MAX_SIZE];
  void (*hashmapPut)(Hashmap *hashmap, void *key, void *value);
  void (*hashmapGet)(Hashmap *hashmap, void *key);
  void (*hashmapRemove)(Hashmap *hashmap, void *key);
  bool (*hashmapContainsKey)(Hashmap *hashmap, void *key);
  bool (*hashmapContainsValue)(Hashmap *hashmap, void *value);
};
Hashmap *newHashmap();
int hashFunction(Hashmap *hashmap, void *key, char *type);
void hashmapPut(Hashmap *hashmap, void *key, void *value);
void hashmapGet(Hashmap *hashmap, void *key);
void hashmapRemove(Hashmap *hashmap, void *key);
bool hashmapContainsKey(Hashmap *hashmap, void *key);
bool hashmapContainsValue(Hashmap *hashmap, void *value);
void destroyHashmap(Hashmap *hashmap);
#endif
