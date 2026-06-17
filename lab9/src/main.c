#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "lib/graph.h"

int main(void) {
    long long N, S, F, M;

    if (scanf("%lld", &N) != 1) return 0;
    if (N < 0 || N > 5000) {
        printf("bad number of vertices\n");
        return 0;
    }

    if (scanf("%lld %lld", &S, &F) != 2) {
    }
    if (N == 0 || S < 1 || S > N || F < 1 || F > N) {
        printf("bad vertex\n");
        return 0;
    }

    if (scanf("%lld", &M) != 1) {
        printf("bad number of lines\n");
        return 0;
    }
    if (M < 0 || M > N * (N - 1) / 2) {
        printf("bad number of edges\n");
        return 0;
    }

    TGraph *graph = CreateGraph((int) N);
    if (!graph && N > 0) return 0;

    for (int i = 0; i < (int) M; i++) {
        long long from, to, weight;
        if (scanf("%lld %lld %lld", &from, &to, &weight) < 3) {
            printf("bad number of lines\n");
            FreeGraph(graph);
            return 0;
        }
        if (from < 1 || from > N || to < 1 || to > N) {
            printf("bad vertex\n");
            FreeGraph(graph);
            return 0;
        }
        if (weight < 0 || weight > INT_MAX) {
            printf("bad length\n");
            FreeGraph(graph);
            return 0;
        }
        AddEdge(graph, (int) from - 1, (int) to - 1, (int) weight);
    }

    long long *dist = (long long *) malloc(N * sizeof(long long));
    int *parent = (int *) malloc(N * sizeof(int));
    int *manyWays = (int *) malloc(N * sizeof(int));

    Dijkstra(graph, (int) S - 1, dist, parent, manyWays);

    for (int i = 0; i < N; i++) {
        if (dist[i] == -1) {
            printf("oo");
        } else if (dist[i] > INT_MAX) {
            printf("INT_MAX+");
        } else {
            printf("%lld", dist[i]);
        }
        printf("%s", (i == N - 1) ? "" : " ");
    }
    printf("\n");

    int startIdx = (int) S - 1;
    int endIdx = (int) F - 1;

    if (dist[endIdx] == -1) {
        printf("no path\n");
    } else if (dist[endIdx] > INT_MAX && manyWays[endIdx] == 1) {
        printf("overflow\n");
    } else {
        int current = endIdx;
        while (current != -1) {
            printf("%d", current + 1);
            if (current == startIdx) {
                break;
            }
            printf(" ");
            current = parent[current];
        }
        printf("\n");
    }


    free(dist);
    free(parent);
    free(manyWays);
    FreeGraph(graph);

    return 0;
}
