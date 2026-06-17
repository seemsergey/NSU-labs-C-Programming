//
// Created by SeemS on 14.03.2026.
//

#include "rbTree.h"

static int CreateNode(TRBTree *tree, int value) {
    int idx = tree->nextIdx++;
    tree->nodes[idx].value = value;
    tree->nodes[idx].left = tree->nodes[idx].right = tree->nodes[idx].parent = NILL;
    tree->nodes[idx].color = RED;
    return idx;
}

static void RotateLeft(TRBTree *tree, int *root, int pivotIndx) {
    int rightChild = tree->nodes[pivotIndx].right;

    tree->nodes[pivotIndx].right = tree->nodes[rightChild].left;
    if (tree->nodes[rightChild].left != NILL) {
        tree->nodes[tree->nodes[rightChild].left].parent = pivotIndx;
    }

    tree->nodes[rightChild].parent = tree->nodes[pivotIndx].parent;

    if (tree->nodes[pivotIndx].parent == NILL) {
        *root = rightChild;
    } else if (pivotIndx == tree->nodes[tree->nodes[pivotIndx].parent].left) {
        tree->nodes[tree->nodes[pivotIndx].parent].left = rightChild;
    } else {
        tree->nodes[tree->nodes[pivotIndx].parent].right = rightChild;
    }

    tree->nodes[rightChild].left = pivotIndx;
    tree->nodes[pivotIndx].parent = rightChild;
}

static void RotateRight(TRBTree *tree, int *root, int pivotIndx) {
    int leftChild = tree->nodes[pivotIndx].left;

    tree->nodes[pivotIndx].left = tree->nodes[leftChild].right;
    if (tree->nodes[leftChild].right != NILL) {
        tree->nodes[tree->nodes[leftChild].right].parent = pivotIndx;
    }

    tree->nodes[leftChild].parent = tree->nodes[pivotIndx].parent;

    if (tree->nodes[pivotIndx].parent == NILL) {
        *root = leftChild;
    } else if (pivotIndx == tree->nodes[tree->nodes[pivotIndx].parent].right) {
        tree->nodes[tree->nodes[pivotIndx].parent].right = leftChild;
    } else {
        tree->nodes[tree->nodes[pivotIndx].parent].left = leftChild;
    }

    tree->nodes[leftChild].right = pivotIndx;
    tree->nodes[pivotIndx].parent = leftChild;
}

static void BalanceAfterInsert(TRBTree *tree, int *root, int newNode) {
    while (tree->nodes[newNode].parent != NILL && tree->nodes[tree->nodes[newNode].parent].color == RED) {
        int parent = tree->nodes[newNode].parent;
        int grandparent = tree->nodes[parent].parent;

        if (parent == tree->nodes[grandparent].left) {
            int uncle = tree->nodes[grandparent].right;
            if (uncle != NILL && tree->nodes[uncle].color == RED) {
                tree->nodes[parent].color = BLACK;
                tree->nodes[uncle].color = BLACK;
                tree->nodes[grandparent].color = RED;
                newNode = grandparent;
            } else {
                if (newNode == tree->nodes[parent].right) {
                    newNode = parent;
                    RotateLeft(tree, root, newNode);
                    parent = tree->nodes[newNode].parent;
                }
                tree->nodes[parent].color = BLACK;
                tree->nodes[grandparent].color = RED;
                RotateRight(tree, root, grandparent);
            }
        } else {
            int uncle = tree->nodes[grandparent].left;
            if (uncle != NILL && tree->nodes[uncle].color == RED) {
                tree->nodes[parent].color = BLACK;
                tree->nodes[uncle].color = BLACK;
                tree->nodes[grandparent].color = RED;
                newNode = grandparent;
            } else {
                if (newNode == tree->nodes[parent].left) {
                    newNode = parent;
                    RotateRight(tree, root, newNode);
                    parent = tree->nodes[newNode].parent;
                }
                tree->nodes[parent].color = BLACK;
                tree->nodes[grandparent].color = RED;
                RotateLeft(tree, root, grandparent);
            }
        }
    }
    tree->nodes[*root].color = BLACK;
}

int GetBlackHeight(TRBTree *tree, int nodeIdx) {
    int blackHeight = 0;
    int current = nodeIdx;

    while (current != NILL) {
        if (tree->nodes[current].color == BLACK) {
            blackHeight++;
        }
        current = tree->nodes[current].left;
    }
    return blackHeight + 1;
}

void Insert(TRBTree *tree, int *root, int value) {
    int newNode = CreateNode(tree, value);
    int current = *root;
    int potentialParent = NILL;

    while (current != NILL) {
        potentialParent = current;
        if (value < tree->nodes[current].value) {
            current = tree->nodes[current].left;
        } else {
            current = tree->nodes[current].right;
        }
    }

    tree->nodes[newNode].parent = potentialParent;

    if (potentialParent == NILL) {
        *root = newNode;
    } else if (value < tree->nodes[potentialParent].value) {
        tree->nodes[potentialParent].left = newNode;
    } else {
        tree->nodes[potentialParent].right = newNode;
    }

    BalanceAfterInsert(tree, root, newNode);
}
