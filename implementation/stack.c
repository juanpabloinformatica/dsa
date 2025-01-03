#include "stack.h"

Stack *newStack() {
  Stack *ptrStack = (Stack *)malloc(sizeof(Stack));
  ptrStack->dynamicArray = newDynamicArray();
  ptrStack->push = push;
  ptrStack->pop = pop;
  ptrStack->peek = peek;
  ptrStack->stackIsEmpty = stackIsEmpty;
  return ptrStack;
}
void push(Stack *stack, void *element) {
  // int for easy pourposes
  stack->dynamicArray->addElement(stack->dynamicArray, element);
}
void *pop(Stack *stack) {

  void *topElementPopped = stack->dynamicArray->getElement(
      stack->dynamicArray, (stack->dynamicArray->counter) - 1);
  int null = 0;
  stack->dynamicArray->setElement(stack->dynamicArray,
                                  stack->dynamicArray->counter, &null);
  stack->dynamicArray->removeElementFront(stack->dynamicArray,
                                          stack->dynamicArray->counter);
  return topElementPopped;
}
void peek(Stack *stack) {
  //printf("\nTOP: %d", *(int *)stack->dynamicArray->getElement(
                          /* stack->dynamicArray, stack->dynamicArray->counter)); */
}
bool stackIsEmpty(Stack *stack) {
  return (stack->dynamicArray->counter == 0) ? true : false;
}
void destroyStack(Stack *stack) {
  destroyDynamicArray(stack->dynamicArray);
  free(stack);
}
