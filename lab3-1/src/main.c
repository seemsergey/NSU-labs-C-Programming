#include <stdio.h>
#include <stdlib.h>
#include "lib/sortingAlgorithms.h"
int main(void) {
    int massSize;
    FILE *file = fopen("in.txt", "r");
    if (fscanf(file,"%d", &massSize) != 1) {
        printf("Bad input");
        fclose(file);
        return EXIT_SUCCESS;
    }
    int *arr = (int*) malloc(massSize * sizeof(int));
    for (int i =0; i < massSize; i++) {
        if (fscanf(file,"%d", &arr[i]) != 1) {
            printf("Bad input");
            fclose(file);
            free(arr);
            return EXIT_SUCCESS;
        }
    }

    fclose(file);

    QSortHoare(arr, 0, massSize - 1);
    for (int i =0; i < massSize; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return EXIT_SUCCESS;
}
