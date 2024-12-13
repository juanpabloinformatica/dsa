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
                               BstNode *targetNode, bool* ptrFound) {
  if (*node == NULL && *ptrFound==false) {
    return;
  }
  if(*(int*)(*node)->value==*(int*)targetNode->value){
    *ptrFound = true;
  }
  *antNode = *node;
  *node = (*node)->left;
  _setAntNodeAndNode(antNode, node, targetNode, ptrFound);
  *antNode = *node;
  *node = (*node)->right;
  _setAntNodeAndNode(antNode, node, targetNode, ptrFound);
}
void removeBstNode(Bst *bst, BstNode *targetNode) {
  // I will have to modified where the bst->root, so if i create
  // another variable, if i remove the root, the bst->root will remind pointing
  // where it should not so for that I will pass the the &bst->root
  BstNode* node = bst->root;
  BstNode* antNode = NULL ;
  bool found = false;
  bool *ptrFound = &found;
  /*set the node and his antNode, and a global variable to stop recursion*/
  _setAntNodeAndNode(&antNode,&node,targetNode,ptrFound);
  /*Once we have both nodes, we can check what kind of deletion we have to make*/

  NodeDeletionType nodeDeletionType = _getNodeDeletionType(node);

  /*Now we can do a switch and do the deletion depending the type*/
  /* switch (nodeDeletionType) { */
  /* case NOCHILD: */
  /*   _removeNoChildNode(antNode,node); */
  /*   break; */
  /* case ONECHILD: */
  /*   _removeOneChildNode(antNode,node); */
  /*   break; */
  /* case TWOCHILDEN: */
  /*   _removeTwoChildrenNode(antNode,node); */
  /*   break; */
  /* } */
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
