#ifndef __STACK__
#define __STACK__
#include "dynamicArray.h"
#include <stdbool.h>
#include <stdlib.h>
typedef struct Stack Stack;
struct Stack {
  // top == counter so using counter, so stack will by dynamic
  // The thing is that if I use this i need to implement the removing of
  // elements So well do that
  // int top;
  DynamicArray *dynamicArray;
  void (*push)(Stack *stack, void *element);
  void* (*pop)(Stack *stack);
  void (*peek)(Stack *stack);
  bool (*stackIsEmpty)(Stack *stack);
};

Stack *newStack();
void push(Stack *stack, void *element);
void* pop(Stack *stack);
void peek(Stack *stack);
bool stackIsEmpty(Stack *stack);
void destroyStack();
#endif
