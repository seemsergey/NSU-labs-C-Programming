//
// Created by SeemS on 08.12.2025.
//

#include <ctype.h>
#include <stdio.h>

#include "stack.h"
#include "operatorStruct.h"

typedef enum {
    OK = 0,
    StackUnderflow = 1,
    DivisionByZero = 2
} ECalcResult;

static char WhichOperator(char symbol, int N, TOperator *customOperators) {
    for (int i = 0; i < N; ++i) {
        if (customOperators[i].symbol == symbol) {
            return customOperators[i].name[0];
        }
    }
    return 'A';
}

static int CalculateIt(int num1, int num2, char symbol) {
    if (symbol == 'A') {
        return num1 + num2;
    } else if (symbol == 'S') {
        return num1 - num2;
    } else if (symbol == 'D') {
        return num1 / num2;
    } else if (symbol == 'M') {
        return num1 * num2;
    }
    return 0;
}
int CalculatePostfixForm(char *postString, int N, TOperator *customOperators) {
    TStack TIntStack;
    StackInit(&TIntStack);

    ECalcResult ret = OK;
    int i = 0;

    while (postString[i] != '\0' && ret == OK) {
        if (postString[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit((unsigned char)postString[i])) {
            size_t num = 0;
            while (isdigit((unsigned char)postString[i])) {
                num = num * 10 + (postString[i++] - '0');
            }
            (void)Push(&TIntStack, num);
        } else {
            size_t b_s;
            if (Pop(&TIntStack, &b_s) != 0) {
                ret = StackUnderflow;
                break;
            }

            size_t a_s;
            if (Pop(&TIntStack, &a_s) != 0) {
                ret = StackUnderflow;
                break;
            }

            int a = (int)a_s;
            int b = (int)b_s;

            char op = WhichOperator(postString[i], N, customOperators);
            if (op == 'D' && b == 0) {
                ret = DivisionByZero;
                break;
            }

            int result = CalculateIt(a, b, op);

            (void)Push(&TIntStack, (size_t)result);
            i++;
        }
    }

    if (ret == OK) {
        size_t finalResult_s;
        if (Pop(&TIntStack, &finalResult_s) == 0) {
            int finalResult = (int)finalResult_s;
            printf("%d\n", finalResult);
        }
    }

    ClearStack(&TIntStack);
    return (int)ret;
}
