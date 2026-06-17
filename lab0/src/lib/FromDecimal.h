//
// Created by SeemS on 18.09.2025.
//

#ifndef LAB0_FROMDECIMAL_H
#define LAB0_FROMDECIMAL_H

/// Преобразует число из десятичной системы счисления в число в иной системе с основанием до 16 включительно
/// @param totalValue начальное число в десятичной системе счисления
/// @param commaWas метка наличия точки в числе
/// @param NumBase система счисления, в которую требуется перевести число
/// @param result массив, в котором записывается числа в конечной системе счисления
void ConversionFromDecimal(double totalValue, int commaWas, int NumBase, char *result);
#endif //LAB0_FROMDECIMAL_H
