#include "gtest/gtest.h"
// #include <iostream>

extern "C" {
#include "../implementation/dynamicArray.h"
}
// Handling creation
TEST(DynamicArrayTest, HandleCreation) {
  DynamicArray *dynamicArray = newDynamicArray();
  EXPECT_TRUE(dynamicArray != NULL);
}
// Handling Adding
TEST(DynamicArrayTest, HandleAddingElements) {
  // i will continue
  const int ARRAY_LENGTH = 30;
  DynamicArray *dynamicArray = newDynamicArray();
  int elements[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elements[i] = i;
    dynamicArray->addElement(dynamicArray, (int *)&elements[i]);
  }
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    int element = *(int *)(dynamicArray->array)[i];
    ASSERT_EQ(element, i);
  }
}
TEST(DynamicArrayTest, HandleGettingElements) {
  const int ARRAY_LENGTH = 30;
  DynamicArray *dynamicArray = newDynamicArray();
  int elements[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elements[i] = i;
    dynamicArray->addElement(dynamicArray, (int *)&elements[i]);
  }
  ASSERT_TRUE(*(int *)dynamicArray->getElement(dynamicArray, 0) == 0);
  ASSERT_TRUE(*(int *)dynamicArray->getElement(dynamicArray, 1) == 1);
  ASSERT_TRUE(*(int *)dynamicArray->getElement(dynamicArray, 2) == 2);
  ASSERT_TRUE(*(int *)dynamicArray->getElement(dynamicArray, 3) == 3);
}

TEST(DynamicArrayTest, HandleDeletingElementsFront) {
  const int ARRAY_LENGTH = 30;
  const int REMOVE_ELEMENTS = 10;
  DynamicArray *dynamicArray = newDynamicArray();
  int elements[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elements[i] = i;
    dynamicArray->addElement(dynamicArray, (int *)&elements[i]);
  }
  for (int i = 0; i < REMOVE_ELEMENTS; i++) {
    dynamicArray->removeElementFront(dynamicArray, 0);
  }
  int testArray[ARRAY_LENGTH - REMOVE_ELEMENTS];
  for (int i = 0; i < ARRAY_LENGTH - REMOVE_ELEMENTS; i++) {
    testArray[i] = REMOVE_ELEMENTS + i;
  }
  for (int i = 0; i < ARRAY_LENGTH - REMOVE_ELEMENTS; i++) {
    int element = *(int *)(dynamicArray->array)[i];
    ASSERT_EQ(element, testArray[i]);
  }
}

// TEST(DynamicArrayTest, HandleDeletingElementsBack) {
//   // DynamicArray *dynamicArray = newDynamicArray();
// }
