#include "dynamicArray.h"

DynamicArray *newDynamicArray() {
  DynamicArray *ptrArray = (DynamicArray *)malloc(sizeof(DynamicArray));
  ptrArray->counter = 0;
  ptrArray->bottomIndex = 0;
  ptrArray->size = DYNAMICARRAYCAP;
  ptrArray->array = malloc(sizeof(void *) * ptrArray->size);
  ptrArray->addElement = addElement;
  ptrArray->setElement = setElement;
  ptrArray->removeElement = removeElement;
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
  // dynamicArray->size = dynamicArray->size - 1;
  // updatin ptr to point to chunk with 4 less bytes in this case cause is an
  // integer as we are using integers in this example
  // dynamicArray->array =
  // realloc(dynamicArray->array, sizeof(int) * dynamicArray->size);
}
void removeElementBack(DynamicArray *dynamicArray, int position) {
  for (int i = position; i < dynamicArray->counter; i++) {
    ((int *)dynamicArray->array)[i] = ((int *)dynamicArray->array)[i + 1];
  }
  dynamicArray->bottomIndex++;
  // update they array reducing it
  // dynamicArray->counter--;
  // [0,2,3,4,5,6,7,8]
  // [2,3,4,5,6,7,8]

  // for (int i = position; i < dynamicArray->counter; i++) {
  //   ((int *)dynamicArray->array)[i] = ((int *)dynamicArray->array)[i + 1];
  // }
  // // update they array reducing it
  // dynamicArray->counter--;
  // dynamicArray->size = dynamicArray->size - 1;
  // // updatin ptr to point to chunk with 4 less bytes in this case cause is
  // // integer as we are using integers in this example
  // dynamicArray->array =
  //     realloc(dynamicArray->array, sizeof(int) * dynamicArray->size);
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
  printf("ARRAY\n");
  for (int i = 0; i < dynamicArray->counter; i++) {
    printf("%i\n", ((int *)dynamicArray->array)[i]);
  }
}
