//
// Created by SeemS on 10.05.2026.
//

#ifndef LAB9_GRAPH_H
#define LAB9_GRAPH_H

typedef struct {
    int N;
    int *Matrix;
} TGraph;

TGraph *CreateGraph(int N);

void AddEdge(TGraph *graph, int minEdge, int to, int weight);

void FreeGraph(TGraph *graph);

void Dijkstra(const TGraph *graph, int startNode, long long *dist, int *parent, int *manyWays);

#endif //LAB9_GRAPH_H
