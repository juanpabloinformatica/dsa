#include "gtest/gtest.h"
#include <iostream>
extern "C" {
#include "../implementation/stack.h"
}
TEST(StackTest, HandleStackCreation) {
  Stack *stack = newStack();
  EXPECT_TRUE(stack != NULL);
}
TEST(StackTest, HandleStackPush) {
  int N = 5;
  Stack *stack = newStack();
  int elements[N];
  for (int i = 0; i < N; i++) {
    elements[i] = i;
    stack->push(stack, (int *)&elements[i]);
  }
  ASSERT_EQ(stack->dynamicArray->counter - 1, (N - 1));
}
TEST(StackTest, HandleStackPop) {
  int N = 5;
  Stack *stack = newStack();
  int elements[N];
  for (int i = 0; i < N; i++) {
    elements[i] = i;
    stack->push(stack, (int *)&elements[i]);
  }
  int elementPoped = *(int *)(stack->pop(stack));
  ASSERT_EQ(elementPoped, N - 1);
}

TEST(StackTest, HandleStackIsEmpty) {
  int N = 5;
  Stack *stack = newStack();
  int elements[N];
  for (int i = 0; i < N; i++) {
    elements[i] = i;
    stack->push(stack, (int *)&elements[i]);
  }
  int i = N - 1;
  while (stack->stackIsEmpty(stack) == false) {
    int elementPoped = *(int *)(stack->pop(stack));
    ASSERT_EQ(elementPoped, i--);
  }
  ASSERT_EQ(stack->dynamicArray->counter, 0);
}
