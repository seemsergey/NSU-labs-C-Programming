//
// Created by SeemS on 18.09.2025.
//

void ConversionFromDecimal(double totalValue, int commaWas, int NumBase, char *result) {
    long long integerPart = (long long) totalValue;
    double floatPart = totalValue - integerPart;
    int i = 0;

    if (!(integerPart == 0)) {
        while (integerPart > 0) {
            int remainder;
            remainder = integerPart % NumBase;
            if (remainder < 10) {
                result[i] = remainder + '0';
            } else {
                result[i] = remainder - 10 + 'A';
            }
            integerPart = integerPart / NumBase;
            i++;
        }

        for (int j = 0; j < i / 2; j++) {
            char tmp = result[j];
            result[j] = result[i - j - 1];
            result[i - j - 1] = tmp;
        }
    } else {
        result[i] = '0';
        i++;
    }

    if (floatPart > 0.0 && commaWas) {
        result[i] = '.';
        i++;
        for (int k = 0; k < 12; k++) {
            if (floatPart > 0.0) {
                floatPart *= NumBase;
                int digit = (int) floatPart;
                floatPart -= digit;
                if (digit < 10) {
                    result[i] = digit + '0';
                } else {
                    result[i] = digit - 10 + 'A';
                }
                i++;
            } else {
                break;
            }
        }
        result[i] = '\0';
    }
}
