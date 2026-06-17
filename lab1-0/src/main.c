#include <setjmp.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/Algorithms.h"
#include "lib/CreateShiftTable.h"
#define BUFFER_SIZE 8192


int main(void) {
    char pattern[18] = {'\0'};
    char buffer[BUFFER_SIZE] = {'\0'};

    // Чтение шаблона
    if (fgets(pattern, sizeof(pattern), stdin) == NULL) {
        return 0;
    }

    int patternLen = strlen(pattern);
    if (patternLen > 0 && pattern[patternLen - 1] == '\n') {
        pattern[patternLen - 1] = '\0';
        patternLen--;
    }

    int lastOccurrence[18] = {0};

    ShiftTable(patternLen, lastOccurrence, pattern);

    long long globalPosition = 0;
    int bytesRead;
    int bufferContentLength = 0;

    while ((bytesRead = fread(buffer + bufferContentLength, 1, BUFFER_SIZE - bufferContentLength, stdin)) > 0) {
        bufferContentLength += bytesRead;

        int textPossition = 0;
        int patternPossition = patternLen - 1;

        if (bufferContentLength < patternLen) { // В буфере меньше символов чем длина шаблона
            break;
        }

        BoyeraMoore(&textPossition, &patternPossition, bufferContentLength, globalPosition, buffer, pattern,
                    lastOccurrence, patternLen);

        // Сохраняем хвост буфера для следующей итерации
        int remaining = bufferContentLength - textPossition;
        if (remaining > 0 && remaining <= patternLen) {
            memmove(buffer, buffer + textPossition, remaining);
            bufferContentLength = remaining;
        } else {
            bufferContentLength = 0;
        }

        globalPosition += textPossition;
    }

    return 0;
}
