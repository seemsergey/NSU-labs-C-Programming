//
// Created by SeemS on 06.12.2025.
//

#include <ctype.h>
#include <stdio.h>

#include "stack.h"
#include "operatorStruct.h"

typedef enum {
    None = 0,
    Number = 1,
    OpenBracket = 2,
    CloseBracket = 3,
    Operator = 4
} ETokenType;

int CreatePostString(char *postString, char *input, int N, TOperator *customOperators) {
    TStack operatorStack;
    StackInit(&operatorStack);

    int poss = 0;
    int outPos = 0;

    int bracketWas = 0;
    int wasNumInBracket = 0;

    int prevType = 0;
    while (input[poss] != '\n' && input[poss] != '\0') {
        size_t ch = (char)input[poss];

        // --- С И Н Т А К С И Ч Е С К И Е   О Ш И Б К И ---

        if ((char)ch == '(' && prevType == Number) {
            // 123(
            ClearStack(&operatorStack);
            return 1;
        }

        if ((isdigit((char)ch) && prevType == CloseBracket) || // )123
            (isdigit((char)ch) && prevType == Number)) {
            // 1234 (слипание)
            ClearStack(&operatorStack);
            return 1;
        }

        if ((char)ch == '(' && prevType == CloseBracket) {
            // )(
            ClearStack(&operatorStack);
            return 1;
        }

        if ((char)ch == ')' && prevType == Operator) {
            // (+)
            ClearStack(&operatorStack);
            return 1;
        }

        if ((char)ch != ' ' && prevType == OpenBracket) {
            // (+
            if ((char)ch != '(' && (char)ch != ')' && !isdigit((char)ch)) {
                ClearStack(&operatorStack);
                return 1;
            }
        }

        if (prevType == Operator && // ++
            (char)ch != ' ' && !isdigit((char)ch) &&
            (char)ch != '(' && (char)ch != ')') {
            ClearStack(&operatorStack);
            return 1;
        }

        //  обработка числа
        if (isdigit((char)ch)) {
            prevType = Number;

            while (isdigit(input[poss])) {
                postString[outPos++] = input[poss++];
                if (bracketWas)
                    wasNumInBracket = 1;
            }
            postString[outPos++] = ' ';
            continue;
        }

        //  обработка пробела
        if ((char)ch == ' ') {
            poss++;
            continue;
        }

        //  обработка '('
        if ((char)ch == '(') {
            prevType = OpenBracket;
            bracketWas++;
            Push(&operatorStack, (char)ch);
            poss++;
            continue;
        }

        //  обработка ')'
        if ((char)ch == ')') {
            prevType = CloseBracket;

            bracketWas--;
            if (!wasNumInBracket) {
                ClearStack(&operatorStack);
                return 1; // пустые ()
            }
            if (!bracketWas) {
                wasNumInBracket = 0;
            }

            while (!IsStackEmpty(&operatorStack)) {
                size_t top_s;
                if (Peek(&operatorStack, &top_s) != 0) break; /* на всякий случай */
                char top = (char)top_s;
                if (top == '(') break;

                size_t popped_s;
                (void)Pop(&operatorStack, &popped_s);
                postString[outPos++] = (char)popped_s;
                postString[outPos++] = ' ';
            }

            /* проверяем наличие открывающей скобки */
            if (IsStackEmpty(&operatorStack)) {
                ClearStack(&operatorStack);
                return 1; // нет открывающей скобки
            }

            /* убрать '(' */
            {
                size_t discard;
                (void)Pop(&operatorStack, &discard);
            }

            poss++;
            continue;
        }
        //  обработка операторов
        int found = 0;
        int curPriority = 0;

        for (int i = 0; i < N; ++i) {
            if ((char)ch == customOperators[i].symbol) {
                found = 1;
                curPriority = customOperators[i].priority;
                break;
            }
        }

        if (!found) {
            // нашли необозначееный в условии символ
            ClearStack(&operatorStack);
            return 1;
        }

        prevType = Operator;

        while (!IsStackEmpty(&operatorStack)) {
            size_t top;
            Peek(&operatorStack, &top);
            if (top == '(') break;

            int topPriority = 0;
            for (int i = 0; i < N; ++i) {
                if ((char)top == customOperators[i].symbol) {
                    topPriority = customOperators[i].priority;
                    break;
                }
            }

            if (topPriority >= curPriority) {
                size_t outChar;
                Pop(&operatorStack, &outChar);
                postString[outPos++] = (char)outChar;
                postString[outPos++] = ' ';
            } else break;
        }

        Push(&operatorStack, (char)ch);
        poss++;
    }

    size_t peekChar;
    peekChar = '\0';
    Peek(&operatorStack, &peekChar);
    if (bracketWas || (char)peekChar == '(') {
        ClearStack(&operatorStack);
        return 1;
    }

    //  добавление последних операторов в выходную строку
    while (!IsStackEmpty(&operatorStack)) {
        Pop(&operatorStack, &peekChar);
        postString[outPos++] = (char)peekChar;
        postString[outPos++] = ' ';
    }

    postString[outPos] = '\0';
    if (outPos > 0 && postString[outPos - 1] == ' ')
        postString[outPos - 1] = '\0';

    ClearStack(&operatorStack);
    return 0;
}
