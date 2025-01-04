#ifndef __HASH_MAP__
#define __HASH_MAP__
#include "dynamicArray.h"
#include "linkedList.h"
#include "graph.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// hashfunction Cormen method applied
#define ARRAY_MAX_SIZE (1 << 4)
// #define DIVIDE_FACTOR (1 << 4) * 10
#define MODULE_FACTOR ARRAY_MAX_SIZE
#define HASHMAP_TYPE_NUMBER "number"
#define HASHMAP_TYPE_STRING "string"
#define HASHMAP_TYPE_USER_DEFINED "void*"
#define HASHFUNCTION(hashmap, key)                                             \
  _Generic((key),                                                              \
      int: hashFunctionNumber((hashmap), (key)),                               \
      char *: hashFunctionString((hashmap), (key)),                            \
      void *: hashFunctionUserDefined((hashmap), (key)))

#define IS_NUMBER(variable) (())
typedef struct HashmapNode HashmapNode;
// struct HashmapNode {
//   void *key;
//   void *value;
// };

typedef struct Hashmap Hashmap;
struct Hashmap {
  char *keyType;
  char *valueType;
  // void *array[ARRAY_MAX_SIZE];
  DynamicArray *array;
  int counter;
  void (*hashmapPut)(Hashmap *hashmap, void *key, void *value);
  // void *(*hashmapGet)(Hashmap *hashmap, void *key);
  void *(*hashmapGet)(Hashmap *hashmap, void *key);
  void (*hashmapRemove)(Hashmap *hashmap, void *key);
  bool (*hashmapContainsKey)(Hashmap *hashmap, void *key);
  // bool (*hashmapContainsValue)(Hashmap *hashmap, void *value);
};

Hashmap *newHashmap(char *keyType, char *valueType);
// HashmapNode *newHashmapNode(void *key, void *value);
int hashFunction(Hashmap *hashmap, void *key);
void hashmapPut(Hashmap *hashmap, void *key, void *value);
// void* hashmapGet(Hashmap *hashmap, void *key);
void *hashmapGet(Hashmap *hashmap, void *key);
void hashmapRemove(Hashmap *hashmap, void *key);
bool hashmapContainsKey(Hashmap *hashmap, void *key);
// bool hashmapContainsValue(Hashmap *hashmap, void *value);
void destroyHashmap(Hashmap *hashmap);
int hashFunctionNumber(Hashmap *hashmap, void *key);
int hashFunctionString(Hashmap *hashmap, void *key);
int hashFunctionUserDefined(Hashmap *hashmap, void *key);
// void destroyHashmapNode(HashmapNode *hashmapNode);
#endif
