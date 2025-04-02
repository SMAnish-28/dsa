#include <stdio.h>
#include <time.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n, int *comparisons) {
    int i, j, temp;
    *comparisons = 0; // Initialize comparison counter

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*comparisons)++; // Count each comparison
            if (arr[j] > arr[j + 1]) {
                // Swap if the current element is greater than the next
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i, comparisons;
    clock_t start, end;
    double time_taken;

    // User input
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Start measuring time
    start = clock();

    // Sorting
    bubbleSort(arr, n, &comparisons);

    // Stop measuring time
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Display sorted array
    printf("Sorted array in ascending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Display number of comparisons
    printf("\nNumber of comparisons: %d", comparisons);

    // Display time taken for sorting
    printf("\nTime taken for sorting: %f seconds\n", time_taken);

    return 0;
}
