//
// Created by SeemS on 22.02.2026.
//

/* --- ДЕКОДЕР --- */
#include "decoder.h"


static int readBit(FILE *in, int *bit, unsigned char *currentByte, int *bitsLeft) {
    if (*bitsLeft == 0) {
        if (fread(currentByte, 1, 1, in) != 1)
            return 0;
        *bitsLeft = 8;
    }
    *bit = (*currentByte >> 7) & 1;
    *currentByte <<= 1;
    (*bitsLeft)--;
    return 1;
}

static unsigned char readChar(FILE *in, unsigned char *currentByte, int *bitsLeft) {
    unsigned char ch = 0;
    int bit;

    for (int i = 0; i < 8; i++) {
        if (!readBit(in, &bit, currentByte, bitsLeft)) {
            return 0;
        }
        ch = (ch << 1) | bit;
    }
    return ch;
}

static TNode *decodeTreeFromFile(FILE *file, unsigned char *currentByte, int *bitsLeft) {
    int bit;

    if (!readBit(file, &bit, currentByte, bitsLeft))
        return NULL;

    // Лист
    if (bit == 0) {
        unsigned char ch = readChar(file, currentByte, bitsLeft);
        return CreateNode(ch, 0, NULL, NULL, 0);
    }

    // Внутренний узел
    TNode *left = decodeTreeFromFile(file, currentByte, bitsLeft);
    TNode *right = decodeTreeFromFile(file, currentByte, bitsLeft);
    return CreateNode(0, 0, left, right, 0);
}

void Decode(void) {
    FILE *inFile = stdin;
    if (!inFile) {
        perror("Cannot open input file");
        return;
    }

    FILE *outFile = stdout;
    if (!outFile) {
        perror("Cannot open output file");
        fclose(inFile);
        return;
    }

    uint32_t originalSize = 0;
    if (fread(&originalSize, sizeof(uint32_t), 1, inFile) == 0) {
        fclose(inFile);
        fclose(outFile);
        perror("Cannot read original size");
        return;
    }
    unsigned char currentByte = 0;
    int bitsLeft = 0;

    TNode *root = decodeTreeFromFile(inFile, &currentByte, &bitsLeft);

    size_t symbCount = 0;
    int count = 0;
    while (symbCount < originalSize) {
        TNode *node = root;

        while (node->left || node->right) {
            int bit;
            if (!readBit(inFile, &bit, &currentByte, &bitsLeft)) {
                break;
            }
            node = bit ? node->right : node->left;
        }
        count++;
        if (fputc(node->ch, outFile) == EOF) {
            fclose(inFile);
            fclose(outFile);
            ClearTree(root);
            perror("Error writing to output file");
            return;
        }

        symbCount++;
    }
    fprintf(stderr, "%d\n", count);

    ClearTree(root);

    fclose(inFile);
    fclose(outFile);
}
