//
// Created by SeemS on 15.02.2026.
//

#ifndef LAB5_HAFFMAN_H
#define LAB5_HAFFMAN_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct THuffmanCode {
    unsigned char ch; // символ как байт
    char code[256]; // строка вида "0101010" - кодировка символа
} THuffmanCode;

typedef struct TNode {
    unsigned char ch; // символ
    size_t freq; // частота
    struct TNode *left; // левый потомок
    struct TNode *right; // правый потомок
    size_t height; // высота поддерева (для однозначности декода)
} TNode;

// Создаёт новый узел дерева Хаффмана
// @param symbol - символ, хранящийся в узле.
// @param freq - частота символа или суммарная частота поддерева.
// @param left - указатель на левого потомка.
// @param right - указатель на правого потомка.
// @param height - высота поддерева, начинающегося с этого узла.
// @returns указатель на узел дерева.
TNode *CreateNode(unsigned char symbol, size_t freq, TNode *left, TNode *right, size_t height);

// Рекурсивно освобождает память, занятую под дерево Хаффмана.
// @param root - корень дерева для очистки.
void ClearTree(TNode *root);

// Вставляет узел в мин-кучу.
// @param heap - массив указателей на узлы (куча).
// @param heapSize - указатель на текущий размер кучи.
// @param node - указатель на вставляемый узел.
void HeapInsert(TNode **heap, size_t *heapSize, TNode *node);

// Извлекает узел с минимальной частотой из мин-кучи.
// @param heap - указатель на кучу (массив указателей на узлы).
// @param heapSize - указатель на текущий размер кучи.
// @returns указатель на узел с минимальной частотой или NULL, если куча пуста.
TNode *MinSearch(TNode **heap, size_t *heapSize);

// Строит дерево Хаффмана из кучи, используя алгоритм Хаффмана.
// @param heap - указатель на кучу
// @param heapSize - указатель на текущий размер кучи.
void BuildCodeTree(TNode **heap, size_t *heapSize);

// Создаёт корень дерева Хаффмана из кучи, объединяя узлы до тех пор, пока не останется один.
// @param heap - массив указателей на узлы (куча), содержащий начальные листья.
// @param heapSize - указатель на текущий размер кучи.
// @returns указатель на корень построенного дерева Хаффмана или NULL, если куча пуста.
TNode *CreateHuffmanTree(TNode **heap, size_t *heapSize);

// Строит префиксный код для каждого символа.
// @param root - вершина.
// @param codes - массив структур THuffmanCode для сохранения кодов.
// @param curCode - строка для формирования текущего кода во время обхода.
// @param lenCode - текущая длина строки curCode.
void GenerateCodes(const TNode *root, THuffmanCode *codes, char *curCode, int lenCode);

#endif //LAB5_HAFFMAN_H
