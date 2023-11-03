#include <stdio.h>
#include <stdlib.h>

struct SYMBOL {
    char alphabet;
    int frequency;
};

struct Node {
    struct SYMBOL symbol;
    struct Node* left;
    struct Node* right;
};

struct MinPriorityQueue {
    int size;
    struct Node** array;
};

struct SYMBOL inputSymbols[100];

// Function to create a new node
struct Node* createNode(struct SYMBOL symbol) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->symbol = symbol;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new MinPriorityQueue
struct MinPriorityQueue* createMinPriorityQueue(int capacity) {
    struct MinPriorityQueue* minHeap = (struct MinPriorityQueue*)malloc(sizeof(struct MinPriorityQueue));
    minHeap->size = 0;
    minHeap->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return minHeap;
}

// Function to swap two nodes
void swapNodes(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// Heapify the min heap
void minHeapify(struct MinPriorityQueue* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->symbol.frequency < minHeap->array[smallest]->symbol.frequency) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->symbol.frequency < minHeap->array[smallest]->symbol.frequency) {
        smallest = right;
    }

    if (smallest != idx) {
        swapNodes(&minHeap->array[idx], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

// Check if the min heap is empty
int isSizeOne(struct MinPriorityQueue* minHeap) {
    return (minHeap->size == 1);
}

// Extract the minimum node from the min heap
struct Node* extractMin(struct MinPriorityQueue* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node to the min heap
void insertMinHeap(struct MinPriorityQueue* minHeap, struct Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->symbol.frequency < minHeap->array[(i - 1) / 2]->symbol.frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Build the Huffman tree
struct Node* buildHuffmanTree(struct SYMBOL symbols[], int n) {
    struct Node *left, *right, *top;
    struct MinPriorityQueue* minHeap = createMinPriorityQueue(n);

    for (int i = 0; i < n; ++i) {
        minHeap->array[i] = createNode(symbols[i]);
    }
    minHeap->size = n;

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        struct SYMBOL combinedSymbol;
        combinedSymbol.frequency = left->symbol.frequency + right->symbol.frequency;
        top = createNode(combinedSymbol);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Function to perform in-order traversal of the Huffman tree
void inOrderTraversal(struct Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%c ", root->symbol.alphabet);
        inOrderTraversal(root->right);
    }
}

int main() {
    int numDistinctAlphabets;

    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &numDistinctAlphabets);

    printf("Enter the alphabets: ");
    for (int i = 0; i < numDistinctAlphabets; i++) {
        scanf(" %c", &inputSymbols[i].alphabet);
    }

    printf("Enter their frequencies: ");
    for (int i = 0; i < numDistinctAlphabets; i++) {
        scanf("%d", &inputSymbols[i].frequency);
    }

    struct Node* huffmanTree = buildHuffmanTree(inputSymbols, numDistinctAlphabets);

    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(huffmanTree);
    

    return 0;
}
