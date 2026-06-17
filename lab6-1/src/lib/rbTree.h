//
// Created by SeemS on 14.03.2026.
//

#ifndef LAB6_1_RBTREE_H
#define LAB6_1_RBTREE_H

enum EColor {
    RED = 0,
    BLACK = 1
};

typedef struct TNode {
    int value;
    int parent;
    int left;
    int right;
    unsigned char color;
} TNode;

typedef struct TRBTree {
    TNode *nodes;
    int nextIdx;
} TRBTree;

#define NILL -1

// Выводит чёрную высоту дерева
int GetBlackHeight(TRBTree *tree, int nodeIdx);

// Вставляет нод в дерево
void Insert(TRBTree *tree, int *root, int value);

#endif //LAB6_1_RBTREE_H
