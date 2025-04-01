#ifndef __DYNAMIC_ARRAY_TEST__
#define __DYNAMIC_ARRAY_TEST__
extern "C" {
#include "../implementation/dynamicArray.h"
}
#include <gtest/gtest.h>
using ::testing::Test;
class DynamicArrayTest : public Test {
protected:
  DynamicArray *dynamicArray;
  int elements[ARRAY_LENGTH];
  void preSetup(void);
  void SetUp() override;
  void TearDown() override;
};
#endif
