//
// Created by SeemS on 06.12.2025.
//

#ifndef LAB4_OPERATORSTRUCT_H
#define LAB4_OPERATORSTRUCT_H


// Структура, описывающая оператор выражения.
// @field symbol Символ оператора (+ -// / ( ))
// @field priority Приоритет оператора
// @field name Имя оператора

typedef struct TOperator {
    char symbol;
    int priority;
    char name[4];
} TOperator;

#endif // LAB4_OPERATORSTRUCT_H
