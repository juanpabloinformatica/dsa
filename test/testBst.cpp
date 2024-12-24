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
  std::cout << "Initial tree state" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 20
  BstNode *bstNode = newBstNode((int *)&testArray[3]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(bst->root->left->left == NULL);
  std::cout << "Deleting 20" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 40
  bstNode = newBstNode((int *)&testArray[4]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(bst->root->left->right == NULL);
  std::cout << "Deleting 40" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 60
  bstNode = newBstNode((int *)&testArray[5]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(bst->root->right->left == NULL);
  std::cout << "Deleting 60" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 80
  bstNode = newBstNode((int *)&testArray[6]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(bst->root->right->right == NULL);
  std::cout << "Deleting 80" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 30
  bstNode = newBstNode((int *)&testArray[1]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(bst->root->left == NULL);
  std::cout << "Deleting 30" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 70
  bstNode = newBstNode((int *)&testArray[2]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(bst->root->right == NULL);
  std::cout << "Deleting 70" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 50
  bstNode = newBstNode((int *)&testArray[0]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(bst->root == NULL);
  std::cout << "Deleting 50" << std::endl;
  bst->inorderBstTraversal(bst);
}

TEST(BstTest, HandleBstRemoveNodeWithOneChild) {
  Bst *bst = newBst();
  const int testArrayLength = 7;
  int testArray[testArrayLength] = {50, 30, 70, 40, 60};
  for (int i = 0; i < testArrayLength; i++) {
    BstNode *bstNode = newBstNode((int *)&testArray[i]);
    bst->addBstNode(bst, bstNode);
  }
  std::cout << "Initial tree state" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 30
  BstNode *bstNode = newBstNode((int *)&testArray[1]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(*(int *)bst->root->left->value == testArray[3]);
  std::cout << "Deleting 30" << std::endl;
  bst->inorderBstTraversal(bst);

  // deleting 70
  bstNode = newBstNode((int *)&testArray[2]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(*(int *)bst->root->right->value == testArray[4]);
  std::cout << "Deleting 70" << std::endl;
  bst->inorderBstTraversal(bst);

  // deleting 40
  bstNode = newBstNode((int *)&testArray[3]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(bst->root->left == NULL);
  std::cout << "Deleting 40" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 50
  bstNode = newBstNode((int *)&testArray[0]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(*(int *)bst->root->value == testArray[4]);
  std::cout << "Deleting 50" << std::endl;
  bst->inorderBstTraversal(bst);

  // deleting 30
  bstNode = newBstNode((int *)&testArray[4]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(bst->root == NULL);
  std::cout << "Deleting Root 60" << std::endl;
  bst->inorderBstTraversal(bst);
}
TEST(BstTest, HandleBstRemoveNodeWithTwoChildren) {
  Bst *bst = newBst();
  const int testArrayLength = 11;
  int testArray[testArrayLength] = {50, 30, 70, 20, 40, 25, 60, 80, 75, 85, 82};
  for (int i = 0; i < testArrayLength; i++) {
    BstNode *bstNode = newBstNode((int *)&testArray[i]);
    std::cout << *(int *)bstNode->value << std::endl;
    bst->addBstNode(bst, bstNode);
  }
  std::cout << "Initial tree state" << std::endl;
  bst->inorderBstTraversal(bst);

  // deleting 30
  ASSERT_TRUE(*(int *)bst->root->left->value == 30);
  BstNode *bstNode = newBstNode((int *)&testArray[1]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(*(int *)bst->root->left->value == 25);
  std::cout << "Deleting 30" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 70
  bstNode = newBstNode((int *)&testArray[2]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(*(int *)bst->root->right->value == 60);
  std::cout << "Deleting 70" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 80
  bstNode = newBstNode((int *)&testArray[7]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(*(int *)bst->root->right->right->value == 75);
  std::cout << "Deleting 80" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 85
  bstNode = newBstNode((int *)&testArray[9]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(*(int *)bst->root->right->right->right->value == 82);
  std::cout << "Deleting 82" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 25
  bstNode = newBstNode((int *)&testArray[5]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(*(int *)bst->root->left->value == 20);
  std::cout << "Deleting 25" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 50
  bstNode = newBstNode((int *)&testArray[0]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(*(int *)bst->root->value == 40);
  ASSERT_TRUE(*(int *)bst->root->left->value == 20);
  std::cout << "Deleting 50" << std::endl;
  bst->inorderBstTraversal(bst);
  // deleting 40
  bstNode = newBstNode((int *)&testArray[4]);
  bst->removeBstNode(bst, bstNode);
  ASSERT_TRUE(*(int *)bst->root->value == 20);
  ASSERT_TRUE(*(int *)bst->root->right->value == 60);
  ASSERT_TRUE(*(int *)bst->root->right->right->value == 75);
  ASSERT_TRUE(*(int *)bst->root->right->right->right->value == 82);
  ASSERT_TRUE(bst->root->left == NULL);
  std::cout << "Deleting 40" << std::endl;
  bst->inorderBstTraversal(bst);
}
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
