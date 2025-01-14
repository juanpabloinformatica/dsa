#include "testDynamicArray.hpp"
#include <gtest/gtest.h>

void DynamicArrayTest::preSetup(void) {
  // filling temporary array to test
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    this->elements[i] = i;
  }
}
void DynamicArrayTest::SetUp() {
  this->preSetup();
  this->dynamicArray = newDynamicArray(NULL);
}
void DynamicArrayTest::TearDown() {
  destroyDynamicArray(this->dynamicArray);
  std::cout << "Cleaning up fixture" << std::endl;
}

// Handling creation
TEST_F(DynamicArrayTest, HandleCreation) {
  EXPECT_TRUE(this->dynamicArray != NULL);
}
// Handling Adding
TEST_F(DynamicArrayTest, HandleAddingElements) {
  // i will continue
  // const int ARRAY_LENGTH = 30;
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    this->dynamicArray->addElement(this->dynamicArray,
                                   (int *)&this->elements[i]);
  }
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    ASSERT_TRUE(*(int *)(this->dynamicArray->array[i]) == this->elements[i]);
  }
}
TEST_F(DynamicArrayTest, HandleGettingElements) {
  // const int ARRAY_LENGTH = 30;
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    this->dynamicArray->addElement(this->dynamicArray,
                                   (int *)&this->elements[i]);
  }
  ASSERT_TRUE(*(int *)dynamicArray->getElement(dynamicArray, 0) == 0);
  ASSERT_TRUE(*(int *)dynamicArray->getElement(dynamicArray, 1) == 1);
  ASSERT_TRUE(*(int *)dynamicArray->getElement(dynamicArray, 2) == 2);
  ASSERT_TRUE(*(int *)dynamicArray->getElement(dynamicArray, 3) == 3);
}

TEST_F(DynamicArrayTest, HandleDeletingElementsFront) {
  // const int ARRAY_LENGTH = 30;
  const int REMOVE_ELEMENTS = 10;
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    dynamicArray->addElement(dynamicArray, (int *)&this->elements[i]);
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
//   // DynamicArray *dynamicArray = newDynamicArray(NULL);
// }
