#include "dynamicArray.h"

DynamicArray *newDynamicArray() {
  DynamicArray *ptrArray = (DynamicArray *)malloc(sizeof(DynamicArray));
  ptrArray->counter = 0;
  ptrArray->bottomIndex = 0;
  ptrArray->size = DYNAMICARRAYCAP;
  // ptrArray->array = malloc(sizeof(void *) * ptrArray->size);
  ptrArray->array = malloc(sizeof(int *) * ptrArray->size);
  ptrArray->addElement = addElement;
  ptrArray->setElement = setElement;
  ptrArray->removeElementFront = removeElementFront;
  ptrArray->removeElementBack = removeElementBack;
  ptrArray->getElement = getElement;
  ptrArray->showArray = showArray;

  return ptrArray;
}
void addElement(DynamicArray *dynamicArray, void *element) {
  // imagine we are using int values
  assert(dynamicArray->array != NULL);
  if (dynamicArray->counter > dynamicArray->size) {
    dynamicArray->size = dynamicArray->size * 2;
    // as we are using integers in this example
    dynamicArray->array =
        realloc(dynamicArray->array, sizeof(int) * dynamicArray->size);
  }
  ((int *)dynamicArray->array)[dynamicArray->counter] = *(int *)element;
  dynamicArray->counter++;
}
void setElement(DynamicArray *dynamicArray, int position, void *element) {
  // this case we are testing with ints
  ((int *)dynamicArray->array)[position] = *(int *)element;
}

// I will skip this one by now because shifting left array kind of boring
// no he gives the pos
// I know what i am doing is extremely inneficient but not the purpose now
// I will do a variation  for doing the stack
void removeElementFront(DynamicArray *dynamicArray, int position) {
  for (int i = position; i < dynamicArray->counter; i++) {
    ((int *)dynamicArray->array)[i] = ((int *)dynamicArray->array)[i + 1];
  }
  // update they array reducing it
  dynamicArray->counter--;
}
void removeElementBack(DynamicArray *dynamicArray, int position) {
  for (int i = position; i < dynamicArray->counter; i++) {
    ((int *)dynamicArray->array)[i] = ((int *)dynamicArray->array)[i + 1];
  }
  dynamicArray->bottomIndex++;
}
void *getElement(DynamicArray *dynamicArray, int position) {
  // I think what is passing is the problem with pointer arithmetic
  // return ((void**)dynamicArray->array)[position];
  // this one needed to be rethink for th eistance
  // return ((void **)dynamicArray->array)[position];
  int *element = &((int *)dynamicArray->array)[position];
  return (void *)element;
}
void destroyDynamicArray(DynamicArray *dynamicArray) {
  free(dynamicArray->array);
  free(dynamicArray);
}
void showArray(DynamicArray *dynamicArray) {
  printf("\nARRAY\n");
  // for stack
  for (int i = 0; i < dynamicArray->counter - dynamicArray->bottomIndex; i++) {
    printf("%i\n", ((int *)dynamicArray->array)[i]);
  }
  // for queue
}
