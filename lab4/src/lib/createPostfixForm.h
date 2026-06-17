//
// Created by SeemS on 06.12.2025.
//

#ifndef LAB4_CREATEPOSTFIXFORM_H
#define LAB4_CREATEPOSTFIXFORM_H

#include "operatorStruct.h"

// Преобразует инфиксную строку в постфиксную форму.
// @param postString - буфер для результата
// @param input - исходная инфиксная строка
// @param N - количесвто операторов
// @param ops - массив структур операторов
// @returns 0 при успехе, 1 при синтаксической ошибке
int CreatePostString(char *postString, char *input, int N, TOperator *ops);

#endif // LAB4_CREATEPOSTFIXFORM_H
