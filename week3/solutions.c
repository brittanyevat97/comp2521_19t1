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
    // need a parent node to keep track of previous node
    BSTree parent = NULL;
    BSTree curr = t;
    while (curr != NULL) {
        parent = curr;
        if (v < curr->value)
            curr = curr->left;
        else if (v > curr->value)
            curr = curr->right;
        else // v == curr->value
            return t;
    }
    BSTree new = newNode(v);
    if (parent == NULL) return new;
    if (v < parent->value)
        parent->left = new;
    else // v > parent->value
        parent->right = new;
    return t;
}

// recursive version
BSTree insertR(BSTree t, int v) {
    if (t == NULL) return newNode(v);
    // note use of
    //  't->left = insertR(t->left, v);'
    // instead of just
    //  'insertR(t->left, v);'
    // to make sure we are actually updating our tree
    if (v < t->value)
        t->left = insertR(t->left, v);
    else if (v > t->value)
        t->right = insertR(t->right, v);
    // note that in the case that v == t->value, none of the other
    // cases are matched, and we just return t
    return t;
}

// count the number of internal nodes in a BSTree
int countInternal(BSTree t) {
    // consider base case first
    if (t == NULL) return 0;
    // special case when we have a node with no children
    if (t->left == NULL && t->right == NULL) return 0;
    // recursive case
    // number of internal nodes is:
    //  1 (since the root node is an internal node) +
    //  number of internal nodes in left subtree +
    //  number of internal nodes in right subtree
    return 1 + countInternal(t->left) + countInternal(t->right);
}

// return the depth of the node containing a given key if it exists,
// -1 otherwise
// the depth of a root node is zero
int nodeDepth(BSTree t, int key) {
    // base case
    if (t == NULL) return -1;
    // consider root's value and treat recursive case accordingly
    if (t->value == key) return 0;
    int depth;
    if (key < t->value)
        depth = nodeDepth(t->left);
    else
        depth = nodeDepth(t->right);
    // if we didn't find the key value in the left / right subtree, then
    // it is not possible for it to be in the tree we are looking at
    if (depth == -1) return -1;
    return 1 + depth;
}

// compute the maximum branch length of a BSTree
// the branch length is the number of edges on the longest path from
// the root to a leaf
int BSTreeMaxBranchLen(BSTree t) {
    // base case
    if (t == NULL) return 0;
    // special case when we have a node with no children
    if (t->left == NULL && t->right == NULL) return 0;
    // recursive case
    int left = BSTreeMaxBranchLen(t->left);
    int right = BSTreeMaxBranchLen(t->right);
    return 1 + (left > right ? left : right);
}

// compute the width of a BSTree
int BSTWidth(BSTree t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 3;
    return 3 + BSTWidth(t->left) + BSTWidth(t->right);
}

// print out the values of each node in the tree in infix order
void BSTreeInfix(BSTree t) {
    // Infix order: LNR (left subtree, root node, right subtree)
    // base case
    if (t == NULL) return;
    // print left subtree recursively using infix order
    BSTreeInfix(t->left);
    // print value of root node
    printf("%d ", t->value);
    // print right subtree recursively using infix order
    BSTreeInfix(t->right);
}

// search for a value in a BSTree
// return 1 if found, 0 otherwise
int BSTreeFind(BSTree t, int v) {
    // base case, if we reach the empty tree, we have not found v
    if (t == NULL) return 0;
    // recursive case
    if (v < t->value) return BSTreeFind(t->left, v);
    if (v > t->value) return BSTreeFind(t->right, v);
    // if none of the other cases match, then v == t->value
    return 1;
}

// find maximum value in a binary tree
int BTMaxValue(BSTree t) {
    if (t == NULL) return INT_MIN;
    // since this is a binary tree (not necessarily a binary search
    // tree), we need to consider all values in the tree
    int leftMax = BTMaxValue(t->left);
    int rightMax = BTMaxValue(t->right);
    int maxChild = (leftMax > rightMax ? leftMax : rightMax);
    return (t->value > maxChild ? t->value : maxChild);
}

// we need a helper function to keep track of the current allowed
// minimum and maximum values in the tree - we can then check if
// t->value is greater than (or equal to) the current allowed min,
// and less than (or equal to) the current allowed max, and then
// recursively check the subtrees, updating the allowed min / max
// to now account for t->value
int isBSTreeHelper(BSTree t, int min, int max) {
    if (t == NULL) return 1;
    if (t->value < min || t->value > max) return 0;
    return isBSTreeHelper(t->left, min, t->value - 1) 
        && isBSTreeHelper(t->right, t->value + 1, max);
}

// return 1 if t is a binary search tree, 0 otherwise
int isBSTree(BSTree t) {
    return isBSTreeHelper(t, INT_MIN, INT_MAX);
}
