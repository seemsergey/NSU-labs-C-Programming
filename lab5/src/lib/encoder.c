//
// Created by SeemS on 22.02.2026.
//
#include "encoder.h"
#include "config.h"

static void writeByte(FILE *out, int bit, unsigned char *byte, int *count) {
    *byte = (*byte << 1) | bit;
    (*count)++;
    if (*count == 8) {
        fwrite(byte, 1, 1, out);
        *count = 0;
        *byte = 0;
    }
}

static void writeTreeIntoFile(const TNode *root, FILE *file, int *bitCount, unsigned char *outByte) {
    if (!root) return;
    if (!root->left && !root->right) {
        writeByte(file, 0, outByte, bitCount);
        for (int i = 7; i >= 0; i--) {
            writeByte(file, ((unsigned char) root->ch >> i) & 1, outByte, bitCount);
        }
        return;
    }
    writeByte(file, 1, outByte, bitCount);
    writeTreeIntoFile(root->left, file, bitCount, outByte);
    writeTreeIntoFile(root->right, file, bitCount, outByte);
}

void Encode(void) {
    FILE *in = stdin;
    FILE *out = stdout;

    size_t freq[ALPHABET_SIZE] = {0};
    uint32_t size = 0;
    int c;

    while ((c = fgetc(in)) != EOF) {
        freq[(unsigned char) c]++;
        size++;
    }

    if (size == 0) {
        fclose(in);
        return;
    }

    TNode *heap[ALPHABET_SIZE];
    size_t heapSize = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freq[i] > 0) {
            TNode *node = CreateNode((char) i, freq[i], NULL, NULL, 0);
            HeapInsert(heap, &heapSize, node);
        }
    }

    TNode *root = CreateHuffmanTree(heap, &heapSize);

    THuffmanCode codes[ALPHABET_SIZE];

    char curCode[ALPHABET_SIZE];
    GenerateCodes(root, codes, curCode, 0);

    fwrite(&size, sizeof(size), 1, out);

    unsigned char outByte = 0;
    int bitCount = 0;

    writeTreeIntoFile(root, out, &bitCount, &outByte);

    rewind(in); //вернёмся в начало
    c = fgetc(in); // скип режима
    while ((c = fgetc(in)) != EOF) {
        char *code = codes[(unsigned char) c].code;
        for (int j = 0; code[j]; j++) {
            writeByte(out, code[j] == '1', &outByte, &bitCount);
        }
    }

    if (bitCount != 0) {
        outByte <<= (8 - bitCount);
        fwrite(&outByte, 1, 1, out);
    }

    ClearTree(root);
    fclose(in);
}
