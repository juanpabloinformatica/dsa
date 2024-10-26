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
  // void *array[size];
  void *array;
  void (*addElement)(DynamicArray *dynamicArray, void *element);
  void (*setElement)(DynamicArray *dynamicArray, int postion, void *element);
  void (*removeElement)(DynamicArray *dynamicArray, int position);
  void (*removeElementBack)(DynamicArray *dynamicArray,int position);
  void *(*getElement)(DynamicArray *dynamicArray, int position);
  void (*showArray)(DynamicArray *dynamicArray);
};

DynamicArray *newDynamicArray();
void addElement(DynamicArray *dynamicArray, void *element);
void setElement(DynamicArray *dynamicArray, int postion, void *element);
void removeElement(DynamicArray *dynamicArray, int position);
void removeElementBack(DynamicArray *dynamicArray,int position);
void *getElement(DynamicArray *dynamicArray, int position);
void showArray(DynamicArray *dynamicArray);
void destroyDynamicArray(DynamicArray *dynamicArray);
#endif
