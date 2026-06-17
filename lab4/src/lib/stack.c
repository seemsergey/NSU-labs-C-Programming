//
// Created by SeemS on 05.12.2025.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

TListNode *CreateNode(size_t data) {
    TListNode *node = malloc(sizeof(TListNode));
    if (!node) return NULL;

    node->ValueSize = sizeof(size_t);
    node->Value = malloc(node->ValueSize);
    if (!node->Value) {
        free(node);
        return NULL;
    }

    *(size_t *) node->Value = data;
    node->Next = NULL;

    return node;
}

int IsStackEmpty(TStack *stack) {
    return stack->Head == NULL;
}

void Push(TStack *stack, size_t data) {
    TListNode *newNode = CreateNode(data);
    if (!newNode) {
        printf("Stack overflow (int)!\n");
        return;
    }

    newNode->Next = stack->Head;
    stack->Head = newNode;
    stack->Size++;
}

int Peek(TStack *stack, size_t *out) {
    if (IsStackEmpty(stack)) {
        return -1;
    }

    if (out) *out = *(size_t *) stack->Head->Value;
    return 0;
}

int Pop(TStack *stack, size_t *out) {
    if (IsStackEmpty(stack)) {
        return -1;
    }

    TListNode *temp = stack->Head;
    size_t data = *(size_t *) temp->Value;

    stack->Head = temp->Next;
    stack->Size--;

    free(temp->Value);
    free(temp);

    if (out) {
        *out = data;
    }
    return 0;
}

void ClearStack(TStack *stack) {
    size_t tmp;
    while (Pop(stack, &tmp) == 0) {
    }
}

void StackInit(TStack *stack) {
    if (!stack) return; // защита от NULL
    stack->Head = NULL;
    stack->Size = 0;
}
