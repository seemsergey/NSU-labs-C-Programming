//
// Created by SeemS on 28.04.2026.
//

#ifndef LAB8_0_KRUSKAL_H
#define LAB8_0_KRUSKAL_H

#include <stddef.h>

// Компактная структура ребра (8 байт), чтобы уложиться в лимит 104Мб при M ~ 12.5 млн.
typedef struct TEdge {
    unsigned short from;
    unsigned short to;
    int weight;
} TEdge;

typedef struct TDsu {
    int *parent;
    int *rnk;
    int n;
} TDsu;

// Инициализация DSU
void MakeDsu(TDsu *dsu, int n);

// Освобождение памяти DSU
void FreeDsu(TDsu *dsu);

// Поиск представителя множества с оптимизацией пути
int FindSet(int v, int *parent);

// Объединение множеств по рангу
void UnionSets(int a, int b, int *parent, int *rnk);

// Компаратор для сортировки ребер
int CompareEdges(const void *a, const void *b);

#endif //LAB8_0_KRUSKAL_H
