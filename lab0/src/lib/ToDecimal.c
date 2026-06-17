//
// Created by SeemS on 18.09.2025.
//
#include <math.h>

double ConversionToDecimal(char *inputNumber, int numsBeforeComa, int NumBase, int howManySigns) {
    double totalValue = 0.0;
    int power = numsBeforeComa - 1;
    for (int j = 0; j < howManySigns; j++) {
        if (inputNumber[j] == '.') {
            power = -1;
            continue;
        }
        int numberInt = 0;
        if (inputNumber[j] >= '0' && inputNumber[j] <= '9') {
            numberInt = inputNumber[j] - '0';
        } else if (inputNumber[j] >= 'A' && inputNumber[j] <= 'F') {
            numberInt = inputNumber[j] - 'A' + 10;
        } else if (inputNumber[j] >= 'a' && inputNumber[j] <= 'f') {
            numberInt = inputNumber[j] - 'a' + 10;
        }
        totalValue += numberInt * pow(NumBase, power);
        power--;
    }
    return totalValue;
}
