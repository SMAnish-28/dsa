#include <stdio.h>
#include <time.h>

int comparisons = 0; // Global variable to count comparisons

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1), temp;

    for (int j = low; j < high; j++) {
        comparisons++; // Count each comparison
        if (arr[j] < pivot) { 
            i++;
            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i+1] with pivot
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1); // Sort left subarray
        quickSort(arr, pi + 1, high); // Sort right subarray
    }
}

int main() {
    int n;
    clock_t start, end;
    double time_taken;

    // Taking input from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Start measuring time
    start = clock();

    // Sorting using Quick Sort
    quickSort(arr, 0, n - 1);

    // Stop measuring time
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Display sorted array
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Display number of comparisons
    printf("\nNumber of comparisons: %d", comparisons);

    // Display time taken for sorting
    printf("\nTime taken for sorting: %f seconds\n", time_taken);

    return 0;
}
