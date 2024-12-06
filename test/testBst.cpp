#include "gtest/gtest.h"
extern "C" {
#include "../implementation/bst.h"
}
TEST(BstTest, HandleCreationBst) {
  Bst *bst = newBst();
  ASSERT_TRUE(bst != NULL);
  ASSERT_TRUE(bst->addBstNode != NULL);
  ASSERT_TRUE(bst->removeBstNode != NULL);
  ASSERT_TRUE(bst->removeMaxBstNode != NULL);
  ASSERT_TRUE(bst->removeMaxBstNode != NULL);
  ASSERT_TRUE(bst->findMin != NULL);
  ASSERT_TRUE(bst->findMax != NULL);
}
TEST(BstTest, HandleCreationBstNode) {
  int value = 10;
  int *ptrValue = &value;
  BstNode *bst = newBstNode(ptrValue);
  ASSERT_TRUE(bst != NULL);
  ASSERT_TRUE(bst->value == ptrValue);
  ASSERT_TRUE(bst->left == NULL);
  ASSERT_TRUE(bst->right == NULL);
}

TEST(BstTest, HandleAddElement) {
  Bst *bst = newBst();
  int tempValue = 10;
  int *ptrTempValue = &tempValue;
  BstNode *bstNode = newBstNode(ptrTempValue);
  bst->addBstNode(bst, bstNode);
  ASSERT_TRUE(*(int *)bst->root == tempValue);
}
// TEST(BstTest,HandleRemoveElement){
//
// }
