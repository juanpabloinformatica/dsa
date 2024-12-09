#include "bst.h"
#include <stdio.h>

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
  ptrBst->inorderBstTraversal = inorderBstTraversal;
  return ptrBst;
}
static BstNode *_addNode(BstNode *bstRoot, BstNode *bstNode) {
  if (bstRoot == NULL) {
    return NULL;
  }
  // testing with integers
  if (*(int *)bstNode->value < *(int *)bstRoot->value) {
    printf("\nnode value  < root value\n");
    if (bstRoot->left == NULL) {
      bstRoot->left = bstNode;
      return bstRoot;
    } else {
      bstRoot->left = _addNode(bstRoot->left, bstNode);
    }
  } else if (*(int *)bstNode->value > *(int *)bstRoot->value) {
    printf("\nnode value  > root value\n");
    if (bstRoot->right == NULL) {
      bstRoot->right = bstNode;
      return bstRoot;
    } else {
      bstRoot->right = _addNode(bstRoot->right, bstNode);
      return bstRoot;
    }
  }
}

void addBstNode(Bst *bst, BstNode *bstNode) {
  // not autocompletition but well
  if (bst->root == NULL) {
    bst->root = bstNode;
    return;
  }
  _addNode(bst->root, bstNode);
}
static void _removeNode(BstNode *antRoot, BstNode *root, BstNode *node) {
  if (root == NULL) {
    return;
  }
  if (*(int *)root->value == *(int *)node->value) {
    if (root->left == NULL && root->right == NULL) {
      if (*(int *)antRoot->left->value == *(int *)node->value) {
        antRoot->left = NULL;
      } else if (*(int *)antRoot->right->value == *(int *)node->value) {
        antRoot->right = NULL;
      }
      free(root);
      root = NULL;
    } else if (root->left != NULL || root->right != NULL) {
      if (root->left != NULL) {
        if (*(int *)antRoot->left->value == *(int *)root->value) {
          antRoot->left = root->left;
        } else if (*(int *)antRoot->right->value == *(int *)root->value) {
          antRoot->right = root->left;
        }
      } else {
        if (*(int *)antRoot->left->value == *(int *)root->value) {
          antRoot->left = root->right;
        } else if (*(int *)antRoot->right->value == *(int *)root->value) {
          antRoot->right = root->right;
        }
      }
      free(root);
      root = NULL;
    }

    // if (root->left != NULL || root->right != NULL) {
    //   if()
    // }
  }
  if (root != NULL) {
    _removeNode(root, root->left, node);
    // root->left = NULL;
  }
  if (root != NULL) {
    _removeNode(root, root->right, node);
    // root->right=NULL;
  }
}
void removeBstNode(Bst *bst, BstNode *bstNode) {
  BstNode *antRoot = NULL;
  _removeNode(antRoot, bst->root, bstNode);
}

void removeMinBstNode(Bst *bst) {}
void removeMaxBstNode(Bst *bst) {}

static void _findMin(BstNode *root, BstNode **min) {
  // considering the value is an int
  if (root == NULL) {
    return;
  }
  if (*(int *)root->value < *(int *)(*min)->value) {
    printf("\nRoot: %i is less than min: %i\n", *(int *)root->value,
           *(int *)(*min)->value);
    *min = root;
  }
  _findMin(root->left, min);
  _findMin(root->right, min);

  // return min;
}
BstNode *findMin(Bst *bst) {
  BstNode **min = &(bst->root);
  _findMin(bst->root, min);
  return *min;
}

static void _findMax(BstNode *root, BstNode **max) {
  // considering the value is an int
  if (root == NULL) {
    return;
  }
  if (*(int *)root->value > *(int *)(*max)->value) {
    printf("\nRoot: %i is less than min: %i\n", *(int *)root->value,
           *(int *)(*max)->value);
    *max = root;
  }
  _findMax(root->left, max);
  _findMax(root->right, max);
  // return min;
}
BstNode *findMax(Bst *bst) {
  BstNode **min = &(bst->root);
  _findMax(bst->root, min);
  return *min;
}
static void _inorder(BstNode *root) {
  if (root == NULL) {
    return;
  }
  _inorder(root->left);
  printf("%i -> ", *(int *)root->value);
  _inorder(root->right);
}
void inorderBstTraversal(Bst *bst) {
  _inorder(bst->root);
  printf("\n");
}
void destroyBst(Bst *bst) {}
void destroyBstNode(BstNode *bstNode) {}
