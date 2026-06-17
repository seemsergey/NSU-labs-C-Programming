//
// huffman.c - реализация дерева Хаффмана и кучи
//
#include "huffman.h"


TNode *CreateNode(unsigned char symbol, size_t freq, TNode *left, TNode *right, size_t height) {
    TNode *node = malloc(sizeof(TNode));
    if (!node) return NULL;
    node->ch = symbol;
    node->freq = freq;
    node->left = left;
    node->right = right;
    node->height = height;
    return node;
}

void ClearTree(TNode *root) {
    if (root != NULL) {
        ClearTree(root->left);
        ClearTree(root->right);
        free(root);
    }
}

static void delHeapNode(int minIndex, TNode **heap, size_t *heapSize) {
    heap[minIndex] = heap[*heapSize - 1];
    (*heapSize)--;
}

void HeapInsert(TNode **heap, size_t *heapSize, TNode *node) {
    heap[(*heapSize)++] = node;
}

TNode *MinSearch(TNode **heap, size_t *heapSize) {
    if (*heapSize == 0) return NULL;
    int minIndex = 0;
    for (size_t i = 1; i < *heapSize; i++) {
        if (heap[i]->freq < heap[minIndex]->freq) {
            minIndex = (int) i;
        } else if (heap[i]->freq == heap[minIndex]->freq) {
            if (heap[i]->height < heap[minIndex]->height) {
                minIndex = (int) i;
            } else if (heap[i]->height == heap[minIndex]->height) {
                int isLeafI = (heap[i]->left == NULL && heap[i]->right == NULL);
                int isLeafMin = (heap[minIndex]->left == NULL && heap[minIndex]->right == NULL);
                if (!isLeafI && isLeafMin) {
                    minIndex = (int) i;
                } else if (isLeafI && isLeafMin) {
                    if (heap[i]->ch < heap[minIndex]->ch) {
                        minIndex = (int) i;
                    }
                }
            }
        }
    }
    TNode *minElem = heap[minIndex];
    delHeapNode(minIndex, heap, heapSize);
    return minElem;
}

// Построение внутреннего узла с гарантированным порядком left/right
void BuildCodeTree(TNode **heap, size_t *heapSize) {
    TNode *a = MinSearch(heap, heapSize);
    TNode *b = MinSearch(heap, heapSize);

    TNode *left = a;
    TNode *right = b;

    // Если одинаковая частота, устанавливаем порядок: левый = меньший символ или лист
    if (a->freq == b->freq) {
        int aLeaf = (a->left == NULL && a->right == NULL);
        int bLeaf = (b->left == NULL && b->right == NULL);

        if (aLeaf && bLeaf && a->ch > b->ch) {
            left = b;
            right = a;
        } else if (!aLeaf && bLeaf) {
            left = b;
            right = a;
        } else if (aLeaf && !bLeaf) {
            left = a;
            right = b;
        }
    }

    size_t height = ((left->height > right->height) ? left->height : right->height) + 1;
    TNode *parent = CreateNode(0, left->freq + right->freq, left, right, height);
    heap[(*heapSize)++] = parent;
}

TNode *CreateHuffmanTree(TNode **heap, size_t *heapSize) {
    if (*heapSize == 0) return NULL;
    if (*heapSize == 1) return heap[0];

    while (*heapSize > 1) {
        BuildCodeTree(heap, heapSize);
    }
    return heap[0];
}

void GenerateCodes(const TNode *root, THuffmanCode *codes, char *curCode, int lenCode) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->ch].ch = root->ch;
        curCode[lenCode] = '\0';
        strcpy(codes[root->ch].code, curCode);
        return;
    }
    curCode[lenCode] = '0';
    GenerateCodes(root->left, codes, curCode, lenCode + 1);
    curCode[lenCode] = '1';
    GenerateCodes(root->right, codes, curCode, lenCode + 1);
}
