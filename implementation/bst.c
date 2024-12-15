#include "bst.h"
#include <assert.h>
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
// I will also change this
static BstNode *_addNode(BstNode *bstRoot, BstNode *bstNode) {
  if (bstRoot == NULL) {
    return NULL;
  }
  // testing with integers
  if (*(int *)bstNode->value < *(int *)bstRoot->value) {
    // printf("\nnode value  < root value\n");
    if (bstRoot->left == NULL) {
      bstRoot->left = bstNode;
      return bstRoot;
    } else {
      bstRoot->left = _addNode(bstRoot->left, bstNode);
      return bstRoot;
    }
  } else if (*(int *)bstNode->value > *(int *)bstRoot->value) {
    // printf("\nnode value  > root value\n");
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
static BstNode *_getBstNodeSuccesor(BstNode *root) {
  if (root == NULL) {
    return NULL;
  }
  _getBstNodeSuccesor(root->right);
  return root;
}

static NodeDeletionType _getNodeDeletionType(BstNode*node){
  if(node->left == NULL && node->right==NULL)
    return NOCHILD;
  if(node->left!=NULL || node->right !=NULL)
    return ONECHILD;
  return TWOCHILDREN;
}
static void _setAntNodeAndNode(BstNode **antNode, BstNode **node,
                               BstNode *tmpNode, BstNode *targetNode,
                               bool *ptrFound) {
  if (tmpNode == NULL) {
    return;
  }
  // in here once he found it, it should not move anymore
  if (*(int *)tmpNode->value == *(int *)targetNode->value) {
    *node = tmpNode;
    *ptrFound = true;
  }
  if (*ptrFound == false) {
    *antNode = tmpNode;
    *node = tmpNode->left;
    _setAntNodeAndNode(antNode, node, tmpNode->left, targetNode, ptrFound);
  }
  if (*ptrFound == false) {
    *antNode = tmpNode;
    *node = tmpNode->right;
    _setAntNodeAndNode(antNode, node, tmpNode->right, targetNode, ptrFound);
  }
}
static void _removeNoChildNode(BstNode* antNode,BstNode**node){
  if (antNode != NULL) {
    BstNode *antNodeChildToAttachTo =
        (*(int *)antNode->left->value == *(int *)(*node)->value)
            ? antNode->left
            : antNode->right;
    antNodeChildToAttachTo = NULL;
  }
  free((*node));
  (*node) = NULL;
  return;
}
static void _removeOneChildNode(BstNode* antNode,BstNode**node){

    BstNode *sonToKeep = ((*node)->left != NULL) ? (*node)->left : (*node)->right;
  if(antNode!=NULL){
    BstNode *antNodeChildToAttachTo =
        (*(int *)antNode->left->value == *(int *)(*node)->value) ? antNode->left
                                                              : antNode->right;
    antNodeChildToAttachTo = sonToKeep;
    free((*node));
    (*node) = NULL;
  }else{
    antNode = *node;
    *node = sonToKeep;
    free(antNode);
    antNode = NULL;
  }
  return;
}
static void _removeTwoChildrenNodes(BstNode* antNode,BstNode**node){

}
void removeBstNode(Bst *bst, BstNode *targetNode) {
  assert(targetNode != NULL);
  // I will have to modified where the bst->root, so if i create
  // another variable, if i remove the root, the bst->root will remind pointing
  // where it should not so for that I will pass the the &bst->root
  BstNode *node = NULL;
  BstNode *antNode = NULL;
  bool found = false;
  bool *ptrFound = &found;
  /*set the node and his antNode, and a global variable to stop recursion*/
  _setAntNodeAndNode(&antNode, &node, bst->root, targetNode, ptrFound);
  if (antNode != NULL) {
    printf("\nANT_NODE: %i", *(int *)antNode->value);
  } else {
    printf("\nANT_NODE: NULL");
  }
  printf("\nNODE: %i",*(int*)node->value);
  /*Once we have both nodes, we can check what kind of deletion we have to
   * make*/
  /*If this, then there is no node to delete*/
  assert(node != NULL);
  NodeDeletionType nodeDeletionType = _getNodeDeletionType(node);
  switch (nodeDeletionType) {
  case NOCHILD:
    _removeNoChildNode(antNode, &node);
    break;
  case ONECHILD:
    _removeOneChildNode(antNode, &node);
    break;
  case TWOCHILDREN:
    _removeTwoChildrenNodes(antNode, &node);
    break;
  }
  /* BstNode *antRoot = NULL; */
  /* _removeNode(antRoot, &bst->root, bstNode); */
}

void removeMinBstNode(Bst *bst) {}
void removeMaxBstNode(Bst *bst) {}

static void _findMin(BstNode *root, BstNode **min) {
  // considering the value is an int
  if (root == NULL) {
    return;
  }
  if (*(int *)root->value < *(int *)(*min)->value) {
    // printf("\nRoot: %i is less than min: %i\n", *(int *)root->value,
    //      *(int *)(*min)->value);
    //
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
    ////printf("\nRoot: %i is less than min: %i\n", *(int *)root->value,
    /* *(int *)(*max)->value); */
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
  ////printf("\n");
}
void destroyBst(Bst *bst) {}
void destroyBstNode(BstNode *bstNode) {}
