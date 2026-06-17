#include <stdlib.h>
//
// Created by SeemS on 24.11.2025.
//
static void InsertionSort(int *arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

static void Swap(int *s, int i, int j) {
    int tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

static int PartitionForHoare(int *arr, int left, int right) {
    int pivotValue = arr[rand() % (right - left) + left];
    int i = left;
    int j = right;
    while (i <= j) {
        while (arr[i] < pivotValue) {
            i++;
        }
        while (arr[j] > pivotValue) {
            j--;
        }
        if (i <= j) {
            Swap(arr, i, j);
            i++;
            j--;
        }
    }
    return j;
}

void QSortHoare(int *arr, int left, int right) {
    if (left < right) {
        if (right - left < 10) {
            InsertionSort(arr, left, right);
            return;
        }
        int pivot = PartitionForHoare(arr, left, right);
        QSortHoare(arr, left, pivot - 1);
        QSortHoare(arr, pivot + 1, right);
    }
}

static int partitionForLomuto(int *arr, int left, int right) {
    int pivotValue = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivotValue) {
            Swap(arr, i, j);
            i++;
        }
    }
    Swap(arr, i, right);
    return i + 1;
}

void qSortLomuto(int *arr, int left, int right) {
    if (left < right) {
        if (right - left < 10) {
            InsertionSort(arr, left, right);
            return;
        }
        int pivot = partitionForLomuto(arr, left, right);
        qSortLomuto(arr, left, pivot);
        qSortLomuto(arr, pivot + 1, right);
    }
}
