//
// Created by SeemS on 24.11.2025.
//
#include <string.h>

int valid(char *s) {
    int repeats[10] = {0};
    if (strlen(s) <= 10) {
        for (int i = 0; i < (int) strlen(s); i++) {
            if ('0' <= s[i] && s[i] <= '9' && repeats[s[i] - '0'] == 0) {
                repeats[s[i] - '0'] = 1;
            } else {
                return 0;
            }
        }
    } else {
        return 0;
    }
    return 1;
}
