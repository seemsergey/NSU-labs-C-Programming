#include <stdio.h>
#include <stdlib.h>

#include "lib/ToDecimal.h"
#include "lib/FromDecimal.h"

int main(void) {
    int d1, d2;
    char variableNumber[13];
    int commaWas = 0, numsBeforeComa = 0;

    if (scanf("%d %d", &d1, &d2) != 2) {
        printf("bad input");
        return EXIT_SUCCESS;
    }
    if (!(d1 >= 2 && d1 <= 16 && d2 >= 2 && d2 <= 16)) {
        printf("bad input");
        return 0;
    }
    getchar();
    int i = 0;
    for (; i < 13; i++) {
        int ch = getchar();
        if (ch == EOF || ch == '\n') {
            variableNumber[i] = '\0';
            break;
        }

        if (ch == '.') {
            if (commaWas == 1 || i == 0) {
                printf("bad input");
                return 0;
            }
            commaWas = 1;
        } else {
            if (!commaWas) {
                numsBeforeComa += 1;
            }
        }

        int value = -1;
        if (ch >= '0' && ch <= '9') {
            value = ch - '0';
        } else if (ch >= 'A' && ch <= 'F') {
            value = ch - 'A' + 10;
        } else if (ch >= 'a' && ch <= 'f') {
            value = ch - 'a' + 10;
        } else if (ch == '.') {
            value = 1;
        }
        if (value >= d1 || value == -1) {
            printf("bad input");
            return EXIT_SUCCESS;
        }

        variableNumber[i] = ch;
    }
    if (variableNumber[i - 1] == '.') {
        printf("bad input");
        return EXIT_SUCCESS;
    }
    if (d1 != d2) {
        char answerNumber[52];
        double totalValue = ConversionToDecimal(variableNumber, numsBeforeComa, d1, i);
        ConversionFromDecimal(totalValue, commaWas, d2, answerNumber);

        printf("%s", answerNumber);
    } else {
        printf("%s", variableNumber);
    }

    return EXIT_SUCCESS;
}
