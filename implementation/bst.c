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
  return ptrBst;
}
static BstNode* _addNode(BstNode *bstRoot, BstNode *bstNode){
    if(bstRoot==NULL){
        return NULL;
    }
    // testing with integers
    if (*(int*)bstNode->value<*(int*)bstRoot->value){
        printf("\nEntering <\n");
        if (bstRoot->left==NULL) {
            bstRoot->left = bstNode;
            return NULL;
        }else{
            bstRoot->left = _addNode(bstRoot->left,bstNode);
        }
    }else if(*(int*)bstNode->value > *(int*)bstRoot->value){
        printf("\nEntering >\n");
        if (bstRoot->right==NULL) {
            bstRoot->right = bstNode;
            return NULL;
        }else{
            bstRoot->right = _addNode(bstRoot->right,bstNode);
        }
    }
}

void addBstNode(Bst *bst, BstNode *bstNode){
    // not autocompletition but well
   if (bst->root==NULL) {
       bst->root= bstNode;
       return;
   }
   _addNode(bst->root,bstNode);
}
void *removeBstNode(Bst *bst, BstNode *bstNode) {}
void *removeMinBstNode(Bst *bst) {}
void *removeMaxBstNode(Bst *bst) {}
void *findMin(Bst *bst) {}
void *findMax(Bst *bst) {}
void destroyBst(Bst *bst) {}
void destroyBstNode(BstNode *bstNode) {}
