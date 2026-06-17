#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lib/permutation.h"
#include "lib/validity.h"

int main(void) {
    char P[32];
    long long N;

    if (!fgets(P, sizeof(P), stdin)) return 0;

    int len = strlen(P);
    while (P[len - 1] == '\n') {
        P[len - 1] = '\0';
        len--;
    }

    if (scanf("%lld", &N) != 1) {
        printf("bad input");
        return 0;
    }

    if (!valid(P)) {
        printf("bad input");
        return 0;
    }

    for (long long i = 0; i < N; i++) {
        if (!NextPermutation(P))
            break;
        printf("%s\n", P);
    }

    return EXIT_SUCCESS;
}
