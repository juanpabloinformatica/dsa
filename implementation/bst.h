#ifndef __BST__
#define __BST__
#include <stdlib.h>

// then problably i use wrapper and stuffs
typedef struct BstNode BstNode;
struct BstNode {
  void *value;
  BstNode *left;
  BstNode *right;
};
typedef struct Bst Bst;
struct Bst {
  BstNode *root;
  void (*addBstNode)(Bst *bst, BstNode *bstNode);
  void (*removeBstNode)(Bst *bst, BstNode *bstNode);
  void (*removeMinBstNode)(Bst *bst);
  void (*removeMaxBstNode)(Bst *bst);
  BstNode *(*findMin)(Bst *bst);
  BstNode *(*findMax)(Bst *bst);
  void *(*prettyPrintBst)(Bst *bst);
  void (*inorderBstTraversal)(Bst *bst);
};

BstNode *newBstNode(void *value);
Bst *newBst(void);
// if void it can not accumulate
void addBstNode(Bst *bst, BstNode *bstNode);
void removeBstNode(Bst *bst, BstNode *bstNode);
void removeMinBstNode(Bst *bst);
void removeMaxBstNode(Bst *bst);
// BstNode *findMin(Bst *bst);
BstNode *findMin(Bst *bst);
BstNode *findMax(Bst *bst);
void prettyPrintBst(Bst *bst);
void destroyBst(Bst *bst);
void destroyBstNode(BstNode *bstNode);
// inorder traversal
// left child => parent => right child
void inorderBstTraversal(Bst *bst);

#endif
