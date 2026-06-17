#include <stdio.h>
#include<limits.h>
#include <stdlib.h>
#include"calc.h"

long long int LineSummarization(int n, const long long int nums[]) {
    long long int summ = 0;
    for (int i = 0; i < n; i++) {
        summ += nums[i];
    }

    return summ;
}
