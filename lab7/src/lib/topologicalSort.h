//
// Created by SeemS on 17.03.2026.
//

#ifndef LAB7_TOPOLOGICALSORT_H
#define LAB7_TOPOLOGICALSORT_H

#include <stdio.h>
#include <stdlib.h>

enum EColors {
    NOTVISITED = 0,
    INPROCESS = 1,
    VISITED = 2,
};

void TopoSort(int vertexCount, char *matrix);


#endif //LAB7_TOPOLOGICALSORT_H
