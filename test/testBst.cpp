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
  /* std::cout<< *(int*)bst->root->value <<std::endl; */
  /* ASSERT_TRUE(*(int *)bst->root->value == tempValue); */
  /* // for more than one value */
  /* const int ARRAY_LENGTH = 6; */
  /* int elements[ARRAY_LENGTH]; */
  /* for (int i = 0; i < ARRAY_LENGTH; i++) { */
  /*   elements[i] = i; */
  /*   BstNode* bstNode = newBstNode((int*)&elements[i]); */
  /*   bst->addBstNode(bst,bstNode); */
  /* } */
  // test for check is working well
  // root = 10
  // [20,5,9,25,6]
  // root->right = 20 | root->left=5 | root->left->right=9 | root->right->right=25 | root->left->right->right = 6
  //
  int testArrayLength = 5;
  int testArray[testArrayLength] = {20,5,9,25,6};
  for(int i = 0;i<testArrayLength;i++){
      testArray[i] = i;
      BstNode* bstNode = newBstNode((int*)&testArray[i]);
      bst->addBstNode(bst,bstNode);
  }
  ASSERT_TRUE(*(int*)bst->root->value==10);
  /* ASSERT_TRUE(*(int*)bst->root->right->value == 20); */
  /* ASSERT_TRUE(*(int*)bst->root->left->value == 5); */
  /* ASSERT_TRUE(*(int*)bst->root->left->right->value == 9); */
  /* ASSERT_TRUE(*(int*)bst->root->right->right->value == 25); */
  /* ASSERT_TRUE(*(int*)bst->root->left->right->right->value == 25); */
}
// TEST(BstTest,HandleRemoveElement){
//
// }
