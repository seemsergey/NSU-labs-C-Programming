//
// Created by SeemS on 18.09.2025.
//

#ifndef LAB0_TODECIMAL_H
#define LAB0_TODECIMAL_H

/// Преобразует поулченное число из системы счисления до 16 включительно в десятичную систему счисления
/// @param inputNumber массив содержащий введёное число
/// @param numsBeforeComa количество числел до запятой
/// @param NumBase основание числа из которой надо переводить
/// @param howManySigns общее количество знаков в числе ( включая точку )
/// @return Переведённое полученное число в десятичное вещественное число
double ConversionToDecimal(char *inputNumber, int numsBeforeComa, int NumBase, int howManySigns);
#endif //LAB0_TODECIMAL_H
