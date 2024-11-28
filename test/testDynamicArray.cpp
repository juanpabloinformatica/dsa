#include "gtest/gtest.h"
// #include <iostream>

extern "C" {
#include "../implementation/dynamicArray.h"
}
// Handling showingArray
TEST(DynamicArrayTest, HandleShowingArray) {
  //
  // // const int ARRAY_LENGTH = 30;
  // const int ARRAY_LENGTH = 30;
  // DynamicArray *dynamicArray = newDynamicArray();
  // int elements[ARRAY_LENGTH];
  // for (int i = 0; i < ARRAY_LENGTH; i++) {
  //   elements[i] = i;
  //   dynamicArray->addElement(dynamicArray, (int *)&elements[i]);
  // }
  // int size = dynamicArray->counter - dynamicArray->bottomIndex;
  // int i = 0;
  // // dynamicArray->showArray(dynamicArray, i, size);
  // // int elements[ARRAY_LENGTH];
  // // for (int i = 0; i < ARRAY_LENGTH; i++) {
  // //   elements[i] = i;
  // //   dynamicArray->addElement(dynamicArray, (int *)&elements[i]);
  // // }
  // // // building string
  // // std::string testResult = "";
  // // for (int i = 0; i < ARRAY_LENGTH; i++) {
  // //   if (i != ARRAY_LENGTH - 1) {
  // //     testResult += std::to_string(i) + "->";
  // //   } else {
  // //     testResult += std::to_string(i);
  // //   }
  // // }
  // // std::string result = "";
  // //
  // //
  // // std::cout << result << std::endl;
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
    int element = ((int *)dynamicArray->array)[i];
    ASSERT_EQ(element, i);
  }
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
  // dynamicArray->showArray(dynamicArray);
  for (int i = 0; i < REMOVE_ELEMENTS; i++) {
    dynamicArray->removeElementFront(dynamicArray, 0);
  }
  // dynamicArray->showArray(dynamicArray);
  int testArray[ARRAY_LENGTH - REMOVE_ELEMENTS];
  for (int i = 0; i < ARRAY_LENGTH - REMOVE_ELEMENTS; i++) {
    testArray[i] = REMOVE_ELEMENTS + i;
    // printf("[i]: %d", testArray[i]);
  }
  for (int i = 0; i < ARRAY_LENGTH - REMOVE_ELEMENTS; i++) {
    int element = ((int *)dynamicArray->array)[i];
    // printf("\nelement -> %d", element);
    ASSERT_EQ(element, testArray[i]);
  }
}

TEST(DynamicArrayTest, HandleDeletingElementsBack) {
  DynamicArray *dynamicArray = newDynamicArray();
}
// TEST(DynamicArrayTest, HandleSettingElements) {}
