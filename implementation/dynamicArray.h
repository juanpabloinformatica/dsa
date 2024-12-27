#ifndef __DYNAMIC_ARRAY__
#define __DYNAMIC_ARRAY__
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define DYNAMICARRAYCAP 10
typedef struct DynamicArray DynamicArray;

// extern int createdNewArray;
struct DynamicArray {
  int counter;
  int bottomIndex;
  int size;
  void *array;
  // int* array;
  void (*addElement)(DynamicArray *dynamicArray, void *element);
  void (*setElement)(DynamicArray *dynamicArray, int postion, void *element);
  void (*removeElementFront)(DynamicArray *dynamicArray, int position);
  void (*removeElementBack)(DynamicArray *dynamicArray, int position);
  void *(*getElement)(DynamicArray *dynamicArray, int position);
  void (*showArray)(DynamicArray *dynamicArray, int i, int size);
};

DynamicArray *newDynamicArray(void);
void addElement(DynamicArray *dynamicArray, void *element);
void setElement(DynamicArray *dynamicArray, int postion, void *element);
void removeElementFront(DynamicArray *dynamicArray, int position);
void removeElementBack(DynamicArray *dynamicArray, int position);
void *getElement(DynamicArray *dynamicArray, int position);
// void showArray(DynamicArray *dynamicArray);
void showArray(DynamicArray *dynamicArray, int i, int size);
void destroyDynamicArray(DynamicArray *dynamicArray);
#endif
