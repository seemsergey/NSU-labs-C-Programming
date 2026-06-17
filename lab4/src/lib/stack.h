//
// Created by SeemS on 05.12.2025.
//

#ifndef LAB4_NUMSTACK_H
#define LAB4_NUMSTACK_H

typedef struct TListNode {
    void *Value;
    size_t ValueSize;
    struct TListNode *Next;
} TListNode;

typedef struct {
    TListNode *Head;
    size_t Size;
} TStack;

void StackInit(TStack *stack);

// Создать узел со значением int.
// @returns указатель на новый узел или NULL при ошибке.
TListNode *CreateNode(size_t data);


// Проверка на пустоту стека.
// @returns 1 — пуст, 0 — не пуст
int IsStackEmpty(TStack *stack);


// Добавление int в стек.
// @param stack указатель на стек
// @param data значение добавляемое на стек
void Push(TStack *stack, size_t data);


// Чтение верхнего элемента без удаления.
// @param stack указатель на стек
// @param out указатель для записи значения
// @returns 0 — OK, -1 — стек пуст
int Peek(TStack *stack, size_t *out);


// Удаление верхнего элемента.
// @param stack указатель на стек
// @param out указатель для записи удалённого значения
// @returns 0 — OK, -1 — стек пуст
int Pop(TStack *stack, size_t *out);


// Очистка всего стека
void ClearStack(TStack *stack);

#endif // LAB4_NUMSTACK_H
