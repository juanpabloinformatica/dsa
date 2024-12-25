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
// I will clean this function as well but for the moment is well.
static BstNode *_addNode(BstNode *bstRoot, BstNode *bstNode, BstNode **root) {
  // Case the tree is empty
  if (*root == NULL) {
    *root = bstNode;
    return NULL;
  }
  if (bstRoot == NULL) {
    return NULL;
  }
  // testing with integers
  if (*(int *)bstNode->value < *(int *)bstRoot->value) {
    if (bstRoot->left != NULL) {
      bstRoot->left = _addNode(bstRoot->left, bstNode, root);
      return bstRoot;
    }
    bstRoot->left = bstNode;
    return bstRoot;
  }
  if (*(int *)bstNode->value > *(int *)bstRoot->value) {
    if (bstRoot->right != NULL) {
      bstRoot->right = _addNode(bstRoot->right, bstNode, root);
      return bstRoot;
    }
    bstRoot->right = bstNode;
    return bstRoot;
  }
}
void addBstNode(Bst *bst, BstNode *bstNode) {
  _addNode(bst->root, bstNode, &bst->root);
}

static NodeDeletionType _getNodeDeletionType(BstNode *node) {
  if (node->left == NULL && node->right == NULL)
    return NOCHILD;
  if (node->left != NULL && node->right != NULL)
    return TWOCHILDREN;
  return ONECHILD;
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
    return;
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
// this method is working
static void _removeNoChildNode(BstNode *antNode, BstNode *node,
                               BstNode **root) {
  if (antNode == NULL) {
    free(*root);
    *root = NULL;
    return;
  }
  if (antNode->left != NULL &&
      *(int *)antNode->left->value == *(int *)node->value) {
    antNode->left = NULL;
  } else {
    antNode->right = NULL;
  }
  free(node);
  node = NULL;
}
static void _removeOneChildNode(BstNode *antNode, BstNode *node,
                                BstNode **root) {
  assert(*root != NULL);

  if (antNode == NULL) {
    antNode = *root;
    (*root) = ((*root)->left != NULL) ? (*root)->left : (*root)->right;
    free(antNode);
    antNode = NULL;
    return;
  }
  if (node->left != NULL) {
    if (antNode->left != NULL &&
        *(int *)antNode->left->value == *(int *)node->value) {
      antNode->left = node->left;
    } else {
      antNode->right = node->left;
    }
  } else {
    if (*(int *)antNode->left->value == *(int *)node->value) {
      antNode->left = node->right;
    } else {
      antNode->right = node->right;
    }
  }
  free(node);
  node = NULL;
  return;
}

static void _setSucessor(BstNode **parentSucessor, BstNode **sucessor,
                         BstNode *tmpNode) {
  if (tmpNode == NULL) {
    return;
  }
  if (tmpNode->right != NULL) {
    *parentSucessor = tmpNode;
    *sucessor = tmpNode->right;
  }
  tmpNode = tmpNode->right;
  _setSucessor(parentSucessor, sucessor, tmpNode);
}
static void _removeSucessorFromParent(BstNode **parentSucessor) {
  (*parentSucessor)->right = NULL;
}
static void _sucessorHandler(BstNode **parentSucessor, BstNode **sucessor,
                             BstNode *bstNode) {
  _setSucessor(parentSucessor, sucessor, bstNode->left);
}
static void _removeTwoChildrenNodes(BstNode *antNode, BstNode *node,
                                    BstNode **root) {

  /* So what is needed to do */
  /* I will sketch what is supposed to be done */
  BstNode *parentSucessor = node;
  BstNode *sucessor = node->left;
  _sucessorHandler(&parentSucessor, &sucessor, node);
  if (antNode != NULL) {
    // i will improve this reall
    sucessor->left = (node->left == sucessor) ? NULL : node->left;
    sucessor->right = node->right;
    if (antNode->left != NULL &&
        *(int *)antNode->left->value == *(int *)node->value) {
      antNode->left = sucessor;
    } else {
      antNode->right = sucessor;
    }
    _removeSucessorFromParent(&parentSucessor);
    free(node);
    node = NULL;
    /* free(parentSucessor); */
    /* parentSucessor = NULL; */
  } else {
    // I think the  mistake is that the sucessor is a local pointer ones
    // the function ends it dissapear
    if ((*root)->left == parentSucessor) {
      antNode = *root;
      sucessor->left = (node->left == sucessor) ? NULL : node->left;
      sucessor->right = node->right;
      *root = sucessor;
      _removeSucessorFromParent(&parentSucessor);
      /* free(parentSucessor); */
      /* parentSucessor = NULL; */
    } else {
      antNode = *root;
      (*root)->left->right = (*root)->right;
      (*root) = (*root)->left;
      free(antNode);
      antNode = NULL;
    }
  }
}

void removeBstNode(Bst *bst, BstNode *targetNode) {
  assert(targetNode != NULL);
  // I will have to modified where the bst->root, so if i create
  // another variable, if i remove the root, the bst->root will remind
  // pointing where it should not so for that I will pass the the &bst->root
  BstNode *node = NULL;
  BstNode *antNode = NULL;
  bool found = false;
  bool *ptrFound = &found;
  /*set the node and his antNode, and a global variable to stop recursion*/
  _setAntNodeAndNode(&antNode, &node, bst->root, targetNode, ptrFound);
  /*Once we have both nodes, we can check what kind of deletion we have to
   * make*/
  /*If this, then there is no node to delete*/
  assert(node != NULL);
  NodeDeletionType nodeDeletionType = _getNodeDeletionType(node);
  switch (nodeDeletionType) {
  case NOCHILD:
    /* assert(bst->root->left == antNode); */
    /*In case is the root the one I need to move*/
    _removeNoChildNode(antNode, node, &bst->root);
    break;
  case ONECHILD:
    assert(bst->root != NULL);
    _removeOneChildNode(antNode, node, &bst->root);
    break;
  case TWOCHILDREN:
    _removeTwoChildrenNodes(antNode, node, &bst->root);
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
