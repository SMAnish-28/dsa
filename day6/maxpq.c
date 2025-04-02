#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char process[10];
    int priority;
} Process;

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Process heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && heap[left].priority > heap[largest].priority)
        largest = left;
    
    if (right < n && heap[right].priority > heap[largest].priority)
        largest = right;
    
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

void insert(Process heap[], int *size, char process[], int priority) {
    if (*size >= MAX_SIZE) {
        printf("Heap overflow!\n");
        return;
    }
    int i = (*size)++;
    strcpy(heap[i].process, process);
    heap[i].priority = priority;
    
    while (i != 0 && heap[(i - 1) / 2].priority < heap[i].priority) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Process deleteRoot(Process heap[], int *size) {
    if (*size <= 0) {
        printf("Heap underflow!\n");
        Process empty = {"", -1};
        return empty;
    }
    Process root = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return root;
}

void displayHeap(Process heap[], int size) {
    for (int i = 0; i < size; i++)
        printf("%s(%d) ", heap[i].process, heap[i].priority);
    printf("\n");
}

int main() {
    Process heap[MAX_SIZE];
    int size = 0;
    
    char *processes[] = {"P1", "P2", "P3", "P4", "P5", "P6", "P7"};
    int priorities[] = {4, 5, 2, 5, 1, 2, 4};
    int n = sizeof(priorities) / sizeof(priorities[0]);
    
    for (int i = 0; i < n; i++)
        insert(heap, &size, processes[i], priorities[i]);
    
    printf("Initial Max-Priority Queue: ");
    displayHeap(heap, size);
    
    printf("\nExtracting processes based on priority:\n");
    while (size > 0) {
        Process removed = deleteRoot(heap, &size);
        printf("Removed: %s(%d)\n", removed.process, removed.priority);
        printf("Queue after removal: ");
        displayHeap(heap, size);
    }
    
    return 0;
}