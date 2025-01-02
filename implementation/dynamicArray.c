#include "dynamicArray.h"

DynamicArray *newDynamicArray() {
  DynamicArray *ptrArray = (DynamicArray *)malloc(sizeof(DynamicArray));
  ptrArray->counter = 0;
  ptrArray->bottomIndex = 0;
  ptrArray->size = DYNAMICARRAYCAP;
  ptrArray->array = malloc(sizeof(void *) * (long unsigned int)ptrArray->size);
  /* ptrArray->array = malloc(sizeof(int) * ptrArray->size); */
  /* ptrArray->array = (void *)malloc(sizeof(int) * ptrArray->size); */
  ptrArray->addElement = addElement;
  ptrArray->setElement = setElement;
  ptrArray->removeElementFront = removeElementFront;
  ptrArray->removeElementBack = removeElementBack;
  ptrArray->getElement = getElement;
  ptrArray->showArray = showArray;
  return ptrArray;
}
// General Functions
void *getElement(DynamicArray *dynamicArray, int position) {
  /* int *element = &((int *)dynamicArray->array)[position]; */
  void *element = (dynamicArray->array)[position];
  return element;
}
void addElement(DynamicArray *dynamicArray, void *element) {
  // imagine we are using int values
  assert(dynamicArray->array != NULL);
  if (dynamicArray->counter > dynamicArray->size) {
    dynamicArray->size = dynamicArray->size * 2;
    // as we are using integers in this example
    dynamicArray->array =
        realloc(dynamicArray->array,
                sizeof(void *) * (long unsigned int)dynamicArray->size);
  }
  (dynamicArray->array)[dynamicArray->counter] = element;
  dynamicArray->counter++;
}
void setElement(DynamicArray *dynamicArray, int position, void *element) {
  assert(element != NULL);
  // this case we are testing with ints
  (dynamicArray->array)[position] = element;
}
// Recursive functions
void removeElementFront(DynamicArray *dynamicArray, int position) {
  assert(position >= 0 && position <= dynamicArray->size - 1);

  if (position == dynamicArray->counter) {
    dynamicArray->counter--;
    return;
  }
  (dynamicArray->array)[position] = (dynamicArray->array)[position + 1];
  removeElementFront(dynamicArray, ++position);
  // update they array reducing it
}
void removeElementBack(DynamicArray *dynamicArray, int position) {
  assert(position >= 0 && position <= dynamicArray->size - 1);
  if (position == dynamicArray->counter) {
    dynamicArray->bottomIndex++;
    return;
  }
  (dynamicArray->array)[position] = (dynamicArray->array)[position + 1];
  removeElementBack(dynamicArray, ++position);
}

void showArray(DynamicArray *dynamicArray, int i, int size) {
  if (i == size) {
    return;
  }
  if (i == size - 1) {
    printf("%i\n", ((int *)dynamicArray->array)[i]);
  } else {
    printf("%i -> ", ((int *)dynamicArray->array)[i]);
  }
  showArray(dynamicArray, ++i, size);
}
// Destruying everything
void destroyDynamicArray(DynamicArray *dynamicArray) {
  free(dynamicArray->array);
  dynamicArray->array = NULL;
  free(dynamicArray);
  dynamicArray = NULL;
}
