//
// Created by SeemS on 10.05.2026.
//

#include "graph.h"
#include <stdlib.h>

TGraph *CreateGraph(int N) {
    TGraph *graph = (TGraph *) malloc(sizeof(TGraph));
    if (!graph) {
        return NULL;
    }
    graph->N = N;
    graph->Matrix = (int *) malloc((size_t) N * N * sizeof(int));
    if (!graph->Matrix) {
        free(graph);
        return NULL;
    }
    for (int i = 0; i < N * N; i++) {
        graph->Matrix[i] = -1;
    }
    return graph;
}

void AddEdge(TGraph *graph, int minEdge, int to, int weight) {
    graph->Matrix[minEdge * graph->N + to] = weight;
    graph->Matrix[to * graph->N + minEdge] = weight;
}

void FreeGraph(TGraph *graph) {
    if (graph) {
        free(graph->Matrix);
        free(graph);
    }
}

void Dijkstra(const TGraph *graph, int startNode, long long *dist, int *parent, int *manyWays) {
    int N = graph->N;
    int *visited = (int *) calloc(N, sizeof(int));

    for (int i = 0; i < N; i++) {
        dist[i] = -1;
        parent[i] = -1;
        manyWays[i] = 0;
    }

    dist[startNode] = 0;

    for (int i = 0; i < N; i++) {
        int minEdge = -1;

        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[j] != -1) {
                if (minEdge == -1 || dist[j] < dist[minEdge]) {
                    minEdge = j;
                }
            }
        }

        if (minEdge == -1) {
            break;
        }

        visited[minEdge] = 1;

        for (int to = 0; to < N; to++) {
            int weight = graph->Matrix[minEdge * N + to];
            if (weight != -1) {
                long long newDist = dist[minEdge] + weight;

                if (dist[to] == -1 || newDist < dist[to]) {
                    dist[to] = newDist;
                    parent[to] = minEdge;
                    manyWays[to] = manyWays[minEdge];
                } else if (newDist == dist[to]) {
                    manyWays[to] = 1;
                }
            }
        }
    }

    free(visited);
}
