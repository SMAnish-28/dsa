#include <stdio.h>

#define MAX_SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && heap[left] > heap[largest])
        largest = left;
    
    if (right < n && heap[right] > heap[largest])
        largest = right;
    
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

void insert(int heap[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Heap overflow!\n");
        return;
    }
    int i = (*size)++;
    heap[i] = value;
    
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int deleteRoot(int heap[], int *size) {
    if (*size <= 0) {
        printf("Heap underflow!\n");
        return -1;
    }
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return root;
}

void displayHeap(int heap[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int heap[MAX_SIZE];
    int size = 0;
    int choice;
    int values[] = {5, 7, 3, 10, 14, 12, 2, 13, 20, 9};
    int n = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < n; i++)
        insert(heap, &size, values[i]);
    
    printf("Initial Heap: ");
    displayHeap(heap, size);
    
    for (int i = 0; i < 3; i++) {
        int removed = deleteRoot(heap, &size);
        printf("Removed root: %d\n", removed);
        printf("Heap after deletion: ");
        displayHeap(heap, size);
    }
    
    return 0;
}
