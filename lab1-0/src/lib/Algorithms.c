//
// Created by SeemS on 11.11.2025.
//
#include<stdio.h>

void BoyeraMoore(int *textPossition, int *patternPossition, int bufferContentLength,
                 long long globalPosition, char *buffer,
                 char *pattern, int *lastOccurrence, int patternLength) {
    unsigned char lastChar = (unsigned char) buffer[patternLength - 1];
    while (*patternPossition + *textPossition < bufferContentLength) {
        printf("%lld ", globalPosition + *patternPossition + *textPossition + 1);

        if (buffer[*patternPossition + *textPossition] != pattern[*patternPossition] || *patternPossition == 0) {
            int shiftIndex = -1;
            for (int k = 0; k < patternLength; k++) {
                if (lastChar == pattern[k]) {
                    shiftIndex = k;
                    break;
                }
            }

            if (shiftIndex == -1) {
                *textPossition += patternLength;
            } else {
                *textPossition += lastOccurrence[shiftIndex];
            }
            *patternPossition = patternLength - 1;

            if (*patternPossition + *textPossition < bufferContentLength) {
                lastChar = (unsigned char) buffer[*patternPossition + *textPossition];
            }
        } else {
            (*patternPossition)--;
        }
    }
}
