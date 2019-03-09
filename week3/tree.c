#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BSTNode *BSTree;

typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

BSTree newNode(int v) {
    BSTree new = malloc(sizeof(BSTNode));
    assert(new != NULL);
    new->value = v;
    new->left = new->right = NULL;
    return new;
}

// insert a new value into a binary search tree
BSTree insert(BSTree t, int v) {

}

// recursive version
BSTree insertR(BSTree t, int v) {

}

// count the number of internal nodes in a BSTree
int countInternal(BSTree t) {

}

// return the depth of the node containing a given key if it exists,
// -1 otherwise
// the depth of a root node is zero
int nodeDepth(BSTree t, int key) {

}

// compute the maximum branch length of a BSTree
// the branch length is the number of edges on the longest path from
// the root to a leaf
int BSTreeMaxBranchLen(BSTree t) {

}

// compute the width of a BSTree
int BSTWidth(BSTree t) {

}

// print out the values of each node in the tree in infix order
void BSTreeInfix(BSTree t) {

}

// search for a value in a BSTree
// return 1 if found, 0 otherwise
int BSTreeFind(BSTree t, int v) {

}

// find maximum value in a binary tree
int BTMaxValue(BSTree t) {

}

// return 1 if t is a binary search tree, 0 otherwise
int isBSTree(BSTree t) {

}
