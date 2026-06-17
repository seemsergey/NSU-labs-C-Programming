//
// Created by SeemS on 28.04.2026.
//

#include "kruskal.h"
#include <stdlib.h>

void MakeDsu(TDsu *dsu, int n) {
    dsu->n = n;
    dsu->parent = (int *)malloc((n + 1) * sizeof(int));
    dsu->rnk = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        dsu->parent[i] = i;
        dsu->rnk[i] = 0;
    }
}

void FreeDsu(TDsu *dsu) {
    free(dsu->parent);
    free(dsu->rnk);
}

int FindSet(int v, int *parent) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = FindSet(parent[v], parent);
}

void UnionSets(int a, int b, int *parent, int *rnk) {
    int rootA = FindSet(a, parent);
    int rootB = FindSet(b, parent);
    if (rootA != rootB) {
        if (rnk[rootA] < rnk[rootB]) {
            parent[rootA] = rootB;
        } else if (rnk[rootA] > rnk[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootA] = rootB;
            rnk[rootB] += 1;
        }
    }
}

int CompareEdges(const void *a, const void *b) {
    const TEdge *edgeA = (const TEdge *)a;
    const TEdge *edgeB = (const TEdge *)b;
    if (edgeA->weight < edgeB->weight) {
        return -1;
    }
    if (edgeA->weight > edgeB->weight) {
        return 1;
    }
    return 0;
}
