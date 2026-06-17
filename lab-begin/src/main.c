#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include"lib/calc.h"

int main() {
    int N;
    long long temp;

    if (scanf("%d", &N) != 1) {
        printf("bad input");
        return 0;
    }

    if (!(1 <= N && N <= 10)) {
        printf("bad input");
        return 0;
    }
    long long nums[10], summ = 0;

    for (int i = 0; i < N; i++) {
        int validInput = scanf("%lld", &temp);
        if ((validInput != 1 && i != N) || (validInput == 1 && i == N)) {
            printf("bad input");
            return 0;
        }

        if (temp < INT_MIN || temp > INT_MAX) {
            printf("bad input");
            return 0;
        }
        nums[i] = temp;
    }

    summ = LineSummarization(N, nums);
    if (summ < INT_MIN || summ > INT_MAX) {
        printf("overflow");
    } else {
        printf("%lld", summ);
    }
    return EXIT_SUCCESS;
}
