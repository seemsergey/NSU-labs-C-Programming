//
// Created by SeemS on 08.12.2025.
//

#ifndef LAB4_CALCULATEPOSTFORM_H
#define LAB4_CALCULATEPOSTFORM_H
#include "operatorStruct.h" // type operator


// Вычисляет значение выражения в постфиксной форме.
// @param postString Cтрока с постфиксным выражением.
// @param N Количество определённых операторов.
// @param ops Массив структур операторов.
int CalculatePostfixForm(char *postString, int N, TOperator *ops);

#endif //LAB4_CALCULATEPOSTFORM_H
