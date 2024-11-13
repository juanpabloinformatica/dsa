#ifndef __HASH_MAP__
#define __HASH_MAP__
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// hashfunction Cormen method applied
#define ARRAY_MAX_SIZE 1 << 4
// #define DIVIDE_FACTOR (1 << 4) * 10
#define MODULE_FACTOR ARRAY_MAX_SIZE
#define HASHMAP_TYPE_NUMBER "number"
#define HASHMAP_TYPE_STRING "string"

// #define IS_NUMBER(variable) (())
typedef struct Hashmap Hashmap;
struct Hashmap {
  char *keyType;
  char *valueType;
  void *array[ARRAY_MAX_SIZE];
  int counter;
  void (*hashmapPut)(Hashmap *hashmap, void *key, void *value);
  void (*hashmapGet)(Hashmap *hashmap, void *key);
  void (*hashmapRemove)(Hashmap *hashmap, void *key);
  bool (*hashmapContainsKey)(Hashmap *hashmap, void *key);
  bool (*hashmapContainsValue)(Hashmap *hashmap, void *value);
};
Hashmap *newHashmap(char *keyType, char *valueType);
int hashFunction(Hashmap *hashmap, void *key);
void hashmapPut(Hashmap *hashmap, void *key, void *value);
void hashmapGet(Hashmap *hashmap, void *key);
void hashmapRemove(Hashmap *hashmap, void *key);
bool hashmapContainsKey(Hashmap *hashmap, void *key);
bool hashmapContainsValue(Hashmap *hashmap, void *value);
void destroyHashmap(Hashmap *hashmap);
#endif
