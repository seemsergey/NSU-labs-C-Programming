//
// Created by SeemS on 24.11.2025.
//
#include <string.h>


static void reverse(char *arr, int l, int r) {
    while (l < r) {
        char tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
}

static void swap(char *s, int i, int j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

int NextPermutation(char *s) {
    int n = strlen(s);
    int i = n - 2;

    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }
    if (i < 0) {
        return 0; // больше нет перестановок
    }
    int j = n - 1;
    while (s[j] <= s[i]) {
        j--;
    }
    swap(s, i, j);
    reverse(s, i + 1, n - 1);

    return 1;
}
