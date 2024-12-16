#include "gtest/gtest.h"
#include <iostream>
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
  // Bst *bst = newBst();
  // int tempValue = 10;
  // int *ptrTempValue = &tempValue;
  // BstNode *bstNode = newBstNode(ptrTempValue);
  // bst->addBstNode(bst, bstNode);
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
  // root->right = 20 | root->left=5 | root->left->right=9 |
  // root->right->right=25 | root->left->right->right = 6
  //
  Bst *bst = newBst();
  int tempValue = 10;
  int *ptrTempValue = &tempValue;
  BstNode *bstNode = newBstNode(ptrTempValue);
  bst->addBstNode(bst, bstNode);
  const int testArrayLength = 5;
  int testArray[testArrayLength] = {20, 5, 9, 25, 6};
  for (int i = 0; i < testArrayLength; i++) {
    BstNode *bstNode = newBstNode((int *)&testArray[i]);
    bst->addBstNode(bst, bstNode);
    // std::cout << "\nROOT _ ADDRESS" << bst->root << std::endl;
  }
  ASSERT_TRUE(*(int *)bst->root->value == 10);
  ASSERT_TRUE(*(int *)bst->root->right->value == 20);
  ASSERT_TRUE(*(int *)bst->root->left->value == 5);
  ASSERT_TRUE(*(int *)bst->root->left->right->value == 9);
  ASSERT_TRUE(*(int *)bst->root->right->right->value == 25);
  ASSERT_TRUE(*(int *)bst->root->left->right->left->value == 6);
}
// TEST(BstTest,HandleRemoveElement){
//
//
// }
TEST(BstTest, HandleFindMin) {
  Bst *bst = newBst();
  const int testArrayLength = 6;
  int testArray[testArrayLength] = {10, 20, 5, 9, 25, 6};
  for (int i = 0; i < testArrayLength; i++) {
    BstNode *bstNode = newBstNode((int *)&testArray[i]);
    bst->addBstNode(bst, bstNode);
  }
  BstNode *bstNode = newBstNode((int *)&testArray[0]);
  BstNode *minNode = bst->findMin(bst);
  ASSERT_EQ(*(int *)minNode->value, 5);
}

TEST(BstTest, HandleFindMax) {
  Bst *bst = newBst();
  const int testArrayLength = 6;
  int testArray[testArrayLength] = {10, 20, 5, 9, 25, 6};
  for (int i = 0; i < testArrayLength; i++) {
    BstNode *bstNode = newBstNode((int *)&testArray[i]);
    bst->addBstNode(bst, bstNode);
  }
  BstNode *bstNode = newBstNode((int *)&testArray[0]);
  BstNode *maxNode = bst->findMax(bst);
  ASSERT_EQ(*(int *)maxNode->value, 25);
}
TEST(BstTest, HandleBstRemoveLeaft) {
  Bst *bst = newBst();
  const int testArrayLength = 7;
  int testArray[testArrayLength] = {50, 30, 70, 20, 40, 60, 80};
  for (int i = 0; i < testArrayLength; i++) {
    BstNode *bstNode = newBstNode((int *)&testArray[i]);
    bst->addBstNode(bst, bstNode);
  }
  BstNode *bstNode = newBstNode((int *)&testArray[3]);
  std::cout << "\nWorking deleting node with 0 child in normal bst" << std::endl;
  std::cout << "\nBefore" << std::endl;
  bst->inorderBstTraversal(bst);
  bst->removeBstNode(bst, bstNode);
  std::cout << "\nAfter" << std::endl;
  bst->inorderBstTraversal(bst);
  // ASSERT_TRUE(*(int *)bst->root->left->left->value == 20);
  ASSERT_TRUE(bst->root->left->left == NULL);
  bstNode = newBstNode((int *)&testArray[4]);
  bst->removeBstNode(bst, bstNode);
  // bst->inorderBstTraversal(bst);

  // int valueT = 500;
  // BstNode *bstNode3 = newBstNode(&valueT);
  // bst->removeBstNode(bst,bstNode3);
  // std::cout << "\nAfter --2--" << std::endl;
  // bst->inorderBstTraversal(bst);

  // Bst *bst2 = newBst();
  // BstNode *bstNode2 = newBstNode((int *)&testArray[0]);
  // bst2->addBstNode(bst2, bstNode2);
  // std::cout << "\nWorking deleting node with 0 child in one node bst" << std::endl;
  // std::cout << "\nBefore" << std::endl;
  // bst2->inorderBstTraversal(bst2);
  // bst2->removeBstNode(bst2,bstNode2);
  // std::cout << "\nAfter" << std::endl;
  // bst2->inorderBstTraversal(bst2);

}
// TEST(BstTest, HandleBstRemoveNodeWithOneChild) {
//   Bst *bst = newBst();
//   const int testArrayLength = 6;
//   int testArray[testArrayLength] = {50, 30, 70, 20, 40, 80};
//   for (int i = 0; i < testArrayLength; i++) {
//     BstNode *bstNode = newBstNode((int *)&testArray[i]);
//     std::cout << *(int *)bstNode->value << std::endl;
//     bst->addBstNode(bst, bstNode);
//   }
//   BstNode *bstNode = newBstNode((int *)&testArray[2]);
//   std::cout << "\nBefore" << std::endl;
//   bst->inorderBstTraversal(bst);
//   bst->removeBstNode(bst, bstNode);
//   // ASSERT_TRUE(*(int *)bst->root->left->left->value == 20);
//   ASSERT_TRUE(*(int *)bst->root->right->value == 80);
//   std::cout << "\nAfter" << std::endl;
//   bst->inorderBstTraversal(bst);
// }
// TEST(BstTest,HandleBstRemoveNodeWithTwoChildren){
//   Bst *bst = newBst();
//   const int testArrayLength = 7;
//   int testArray[testArrayLength] = {50, 30, 70, 20, 40,60, 80};
//   for (int i = 0; i < testArrayLength; i++) {
//     BstNode *bstNode = newBstNode((int *)&testArray[i]);
//     std::cout << *(int *)bstNode->value << std::endl;
//     bst->addBstNode(bst, bstNode);
//   }
//   BstNode *bstNode = newBstNode((int *)&testArray[0]);
//   bst->removeBstNode(bst, bstNode);
// }
// TEST(BstTest, HandleInorderTraversal) {
//   Bst *bst = newBst();
//   const int testArrayLength = 7;
//   int testArray[testArrayLength] = {50, 30, 70, 20, 40, 60, 80};
//   for (int i = 0; i < testArrayLength; i++) {
//     BstNode *bstNode = newBstNode((int *)&testArray[i]);
//     bst->addBstNode(bst, bstNode);
//   }
//   // bst->inorderBstTraversal(bst);
//   // std::string resultStringTest = "\n20->30->40->50->60->70->80->\n";
//   // std::cout << resultStringTest << std::endl;
// }

