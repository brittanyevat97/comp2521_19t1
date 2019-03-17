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
    // base case - empty tree
    if (t == NULL) {
        printf("diff: 0\n");
        return 0;
    }

    // special case - tree with a root node and no children
    // this has height 0 not 1 with the above definition
    if (t->left == NULL && t->right == NULL) {
        printf("data: %d, diff: 0\n", t->value);
        return 0;
    }

    int l = printHeightDiff(t->left);
    int r = printHeightDiff(t->right);
    int diff = l - r;
    printf("data: %d, diff: %d\n", t->value, diff);

    return 1 + (l > r ? l : r);
}

// Return the height of a given binary tree, if it is an
// AVL tree, otherwise return -1
int isAVL(BSTree t) {
    // base case - empty tree
    if (t == NULL) return 0;

    // special case - tree with a root node and no children
    if (t->left == NULL && t->right == NULL) return 0;

    int l = isAVL(t->left);
    int r = isAVL(t->right);

    // if either subtree is not an AVL tree (i.e. not height-balanced),
    // then the whole tree is not an AVL tree so return -1
    if (l == -1 || r == -1) return -1;

    // absolute value of the difference between the heights of the two
    // subtrees must be at most 1
    // if it is not, return -1
    int diff = l - r;
    if (diff < -1 || diff > 1) return -1;

    return 1 + (l > r ? l : r);
}
