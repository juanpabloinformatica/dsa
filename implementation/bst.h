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
  void *(*removeBstNode)(Bst *bst, BstNode *bstNode);
  void *(*removeMinBstNode)(Bst *bst);
  void *(*removeMaxBstNode)(Bst *bst);
  void *(*findMin)(Bst *bst);
  void *(*findMax)(Bst *bst);
};
BstNode *newBstNode(void *value);
Bst *newBst(void);
void addBstNode(Bst *bst, BstNode *bstNode);
void *removeBstNode(Bst *bst, BstNode *bstNode);
void *removeMinBstNode(Bst *bst);
void *removeMaxBstNode(Bst *bst);
void *findMin(Bst *bst);
void *findMax(Bst *bst);
void destroyBst(Bst *bst);
void destroyBstNode(BstNode *bstNode);

#endif
