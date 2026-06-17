#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "lib/kruskal.h"

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    if (n < 0 || n > 5000) {
        printf("bad number of vertices\n");
        return 0;
    }

    int m;
    if (scanf("%d", &m) != 1) {
        if (n == 0) {
            printf("no spanning tree\n");
        } else {
            printf("bad number of lines\n");
        }
        return 0;
    }

    if (m < 0 || (long long)m > (long long)n * (n + 1) / 2) {
        printf("bad number of edges\n");
        return 0;
    }

    if (n == 0 || (n > 1 && m == 0)) {
        printf("no spanning tree\n");
        return 0;
    }

    if (n == 1) {
        return 0;
    }

    TEdge *edges = (TEdge *)malloc(m * sizeof(TEdge));
    if (edges == NULL && m > 0) {
        return 0;
    }

    for (int i = 0; i < m; i++) {
        long long from, to, weight;
        int res = scanf("%lld %lld %lld", &from, &to, &weight);
        if (res < 3) {
            printf("bad number of lines\n");
            free(edges);
            return 0;
        }
        if (from < 1 || from > n || to < 1 || to > n) {
            printf("bad vertex\n");
            free(edges);
            return 0;
        }
        if (weight < 0 || weight > INT_MAX) {
            printf("bad length\n");
            free(edges);
            return 0;
        }
        edges[i].from = (unsigned short)from;
        edges[i].to = (unsigned short)to;
        edges[i].weight = (int)weight;
    }

    qsort(edges, m, sizeof(TEdge), CompareEdges);

    TDsu dsu;
    MakeDsu(&dsu, n);

    int *mstIndices = (int *)malloc(n * sizeof(int));
    int edgeCount = 0;

    for (int i = 0; i < m; i++) {
        if (FindSet(edges[i].from, dsu.parent) != FindSet(edges[i].to, dsu.parent)) {
            UnionSets(edges[i].from, edges[i].to, dsu.parent, dsu.rnk);
            mstIndices[edgeCount] = i;
            edgeCount += 1;
            if (edgeCount == n - 1) {
                break;
            }
        }
    }

    if (edgeCount != n - 1) {
        printf("no spanning tree\n");
    } else {
        for (int i = 0; i < edgeCount; i++) {
            TEdge resEdge = edges[mstIndices[i]];
            printf("%d %d\n", resEdge.from, resEdge.to);
        }
    }

    free(mstIndices);
    FreeDsu(&dsu);
    free(edges);
    return 0;
}
