//
// Created by SeemS on 11.11.2025.
//

#ifndef LAB1_0_ALGORITHMS_H
#define LAB1_0_ALGORITHMS_H
// Выполняет алгоритм поиска Бойера-Мура со стоп-символами без префикс-функции
// @param textPossition - Указатель на текущую позицию в тексте
// @param patternPossition - Указатель на текущую позицию в шаблоне
// @param bufferContentLength - Длина текста, в котором происходит поиск, в буфере
// @param globalPosition - Глобальная позиция в исходном тексте
// @param buffer - Буфер, содержащий обрабатываемый текст
// @param lastChar - Указатель на последний обработанный символ
// @param pattern - Искомый шаблон
// @param lastOccurrence - Таблица последних вхождений символов в шаблоне
// @param patternLength - Длина искомого шаблона
void BoyeraMoore(int *textPossition, int *patternPossition, int bufferContentLength,
                 long long globalPosition, char *buffer,
                 char *pattern, int *lastOccurrence, int patternLength);
#endif //LAB1_0_ALGORITHMS_H
