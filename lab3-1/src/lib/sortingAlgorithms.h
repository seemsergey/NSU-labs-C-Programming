//
// Created by SeemS on 24.11.2025.
//

#ifndef LAB3_1_SORTINGALGORITHMS_H
#define LAB3_1_SORTINGALGORITHMS_H

// Сортирует массив с использованием алгоритма быстрой сортировки Хоара.
// @param arr - входной массив целых чисел
// @param left - левая граница сортируемого диапазона (включительно)
// @param right - правая граница сортируемого диапазона (включительно)
void QSortHoare(int *arr, int left, int right);

// Сортирует массив с использованием алгоритма быстрой сортировки Ломуто.
// @param arr - входной массив целых чисел
// @param left - левая граница сортируемого диапазона (включительно)
// @param right - правая граница сортируемого диапазона (включительно)
void qSortLomuto(int *arr, int left, int right);

#endif //LAB3_1_SORTINGALGORITHMS_H
