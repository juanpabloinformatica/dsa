#include "bst.h"

BstNode *newBstNode(void *value) {
  BstNode *ptrBstNode = (BstNode *)malloc(sizeof(BstNode));
  ptrBstNode->value = value;
  ptrBstNode->left = NULL;
  ptrBstNode->right = NULL;
  return ptrBstNode;
}
Bst *newBst(void) {
  Bst *ptrBst = (Bst *)malloc(sizeof(Bst));
  ptrBst->root = NULL;
  ptrBst->addBstNode = addBstNode;
  ptrBst->removeBstNode = removeBstNode;
  ptrBst->removeMinBstNode = removeMinBstNode;
  ptrBst->removeMaxBstNode = removeMaxBstNode;
  ptrBst->findMin = findMin;
  ptrBst->findMax = findMax;
  return ptrBst;
}
void addBstNode(Bst *bst, BstNode *bstNode) {}
void *removeBstNode(Bst *bst, BstNode *bstNode) {}
void *removeMinBstNode(Bst *bst) {}
void *removeMaxBstNode(Bst *bst) {}
void *findMin(Bst *bst) {}
void *findMax(Bst *bst) {}
void destroyBst(Bst *bst) {}
void destroyBstNode(BstNode *bstNode) {}
