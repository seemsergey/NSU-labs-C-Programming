#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/operatorStruct.h"
#include "lib/createPostfixForm.h"
#include "lib/calculatePostForm.h"

#define maxInput 1005

int main(void) {
    int N;
    if (scanf("%d", &N) != 1 || N < 0) {
        printf("syntax error");
        return 0;
    }

    TOperator *customOperators = malloc(sizeof(TOperator) * N);
    if (N > 0 && customOperators == NULL) {
        printf("syntax error");
        free(customOperators);
        return 0;
    }

    char opName[4];
    int priority;
    char symbol, temp;

    for (int i = 0; i < N; i++) {
        if (scanf(" %c", &temp) != 1) {
            printf("syntax error");
            free(customOperators);
            return 0;
        }
        if (temp == '\\') {
            if (scanf("%c", &symbol) != 1) {
                printf("syntax error");
                free(customOperators);
                return 0;
            }
        } else {
            symbol = temp;
        }

        if (scanf("%3s %d", opName, &priority) != 2) {
            printf("syntax error");
            free(customOperators);
            return 0;
        }
        customOperators[i].symbol = symbol;
        customOperators[i].priority = priority;
        strcpy(customOperators[i].name, opName);
    }
    getchar();
    char input[maxInput];
    size_t pos = 0;
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n' && ch != '%' && ch != '\0') {
        if (pos + 1 >= sizeof(input)) {
            printf("syntax error");
            free(customOperators);
            return 0;
        }
        input[pos++] = (char)ch;
    }
    input[pos] = '\0';

    if (strcmp(input, "") == 0) {
        printf("syntax error");
        free(customOperators);
        return 0;
    }
    if (strcmp(input, "(1)\0") == 0) {
        for (int i = 0; i < (int)strlen(input)+2; i++) {
            if (input[i] == '\n') {
                ;
            }
        }
    }
    char postString[2*maxInput] = {0}; // в 2 раза больше т.к. если строка без пробелов, то я её преобразую в строку с пробелами
    if (CreatePostString(postString, input, N, customOperators) != 0) {
        free(customOperators);
        printf("syntax error");
        return 0;
    }
//    if (strcmp(input, "(1)\0") == 0) printf("%s", input);
    int resType = CalculatePostfixForm(postString, N, customOperators);
    free(customOperators);

    if (resType == 1) {
        printf("syntax error");
        return 0;
    } else if (resType == 2) {
        printf("division by zero");
        return 0;
    }

    return EXIT_SUCCESS;
}
