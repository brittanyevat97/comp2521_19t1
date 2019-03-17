#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BSTNode *BSTree;

typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

// Print the height difference between the left subtree and the
// right subtree of every node in a tree
// Return the height of the tree
// In these questions, assume height is defined as the number of edges
// on the longest path from the root to a leaf
int printHeightDiff(BSTree t) {

}

// Return the height of a given binary tree, if it is an
// AVL tree, otherwise return -1
int isAVL(BSTree t) {

}
