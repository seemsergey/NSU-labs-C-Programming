#include <stdio.h>
#include <stdlib.h>
#include "lib/rbTree.h"

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        if (n == 0) printf("0");
        return 0;
    }

    TRBTree tree;
    tree.nodes = (TNode *) malloc(sizeof(TNode) * n);
    tree.nextIdx = 0;

    int root = NILL;

    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) == 1) {
            Insert(&tree, &root, value);
        }
    }

    printf("%d", GetBlackHeight(&tree, root));

    free(tree.nodes);
    return 0;
}
