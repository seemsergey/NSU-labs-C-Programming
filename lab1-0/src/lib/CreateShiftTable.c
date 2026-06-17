//
// Created by SeemS on 11.11.2025.
//

void ShiftTable(int patternLen, int *lastOccurrence, char *pattern) {
    for (int i = patternLen - 2; i > -1; i--) {
        lastOccurrence[i] = patternLen - i - 1;
        for (int j = patternLen - 2; j > i; j--) {
            if (pattern[i] == pattern[j]) {
                lastOccurrence[i] = lastOccurrence[j];
                break;
            }
        }
    }
    lastOccurrence[patternLen - 1] = patternLen;
    for (int i = patternLen - 1; i > -1; i--) {
        if (pattern[patternLen - 1] == pattern[i]) {
            lastOccurrence[patternLen - 1] = lastOccurrence[i];
            break;
        }
    }
}
