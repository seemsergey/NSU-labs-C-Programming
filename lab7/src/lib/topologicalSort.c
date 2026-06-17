//
// Created by SeemS on 17.03.2026.
//
#include "topologicalSort.h"

static void Dfs(int vertexCount, char *matrix, int v, int *state, int *resMas, int *resIndx, int *hasCycle) {
    if (*hasCycle) {
        return;
    }

    state[v] = INPROCESS;

    for (int u = 1; u <= vertexCount; u++) {
        if (matrix[v * (vertexCount + 1) + u] == 1) {
            if (state[u] == NOTVISITED) {
                Dfs(vertexCount, matrix, u, state, resMas, resIndx, hasCycle);
                if (*hasCycle) {
                    return;
                }
            } else if (state[u] == INPROCESS) {
                *hasCycle = 1;
                return;
            }
        }
    }

    state[v] = VISITED;
    resMas[(*resIndx)++] = v;
}

void TopoSort(int vertexCount, char *matrix) {
    int *state = calloc(vertexCount + 1, sizeof(int));
    int resMas[vertexCount];
    int resIndex = 0;
    int hasCycle = 0;

    for (int v = 1; v <= vertexCount; v++) {
        if (state[v] == NOTVISITED) {
            Dfs(vertexCount, matrix, v, state, resMas, &resIndex, &hasCycle);
        }
    }

    if (hasCycle) {
        printf("impossible to sort");
    } else {
        for (int i = vertexCount - 1; i >= 0; i--) {
            printf("%d ", resMas[i]);
        }
    }

    free(state);
}
