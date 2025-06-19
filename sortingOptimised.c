#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Optimized bubble sort with early termination
void bubble_sort(int *arr, int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break; // Array is sorted
    }
}

// Optimized selection sort
void selection_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) { // Only swap if necessary
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

// Optimized insertion sort with binary search
int binary_search(int *arr, int key, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid + 1;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int pos = binary_search(arr, key, 0, i - 1);
        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = key;
    }
}

// Optimized merge sort with single temporary array
void merge(int *arr, int *temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void merge_sort_helper(int *arr, int *temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_helper(arr, temp, left, mid);
        merge_sort_helper(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

void merge_sort(int *arr, int left, int right) {
    int *temp = (int *)malloc((right - left + 1) * sizeof(int));
    if (temp == NULL) return;
    merge_sort_helper(arr, temp, left, right);
    free(temp);
}

// Optimized quick sort with median-of-three pivot
int median_of_three(int *arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) {
        int temp = arr[low];
        arr[low] = arr[mid];
        arr[mid] = temp;
    }
    if (arr[low] > arr[high]) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
    if (arr[mid] > arr[high]) {
        int temp = arr[mid];
        arr[mid] = arr[high];
        arr[high] = temp;
    }
    return mid;
}

int partition(int *arr, int low, int high) {
    int pivot_index = median_of_three(arr, low, high);
    int pivot = arr[pivot_index];
    
    // Move pivot to end
    int temp = arr[pivot_index];
    arr[pivot_index] = arr[high];
    arr[high] = temp;
    
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Optimized heap sort
void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, int n) {
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// ... existing code ...

int main() {
    clock_t start, end;
    double time_spent;
    int n;
    
    printf("Enter the number of elements to be stored in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int filename;
    FILE *file = NULL;
    
    printf("Select input file:\n");
    printf("1. Best case (a_best.txt)\n");
    printf("2. Average case (a_average.txt)\n");
    printf("3. Worst case (a_worst.txt)\n");
    printf("\nEnter your choice (1-3): ");
    
    if (scanf("%d", &filename) != 1 || filename < 1 || filename > 3) {
        printf("Invalid input! Please enter a number between 1 and 3.\n");
        free(arr);
        return 1;
    }

    const char *filenames[] = {"a_best.txt", "a_average.txt", "a_worst.txt"};
    file = fopen(filenames[filename - 1], "r");
    
    if (file == NULL) {
        printf("Error opening input file!\n");
        free(arr);
        return 1;
    }

    // Read file in chunks for better performance
    const int CHUNK_SIZE = 1024;
    int *buffer = (int *)malloc(CHUNK_SIZE * sizeof(int));
    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        fclose(file);
        free(arr);
        return 1;
    }

    int count = 0;
    while (count < n && fscanf(file, "%d", &arr[count]) == 1) {
        count++;
    }
    
    free(buffer);
    fclose(file);

    if (count != n) {
        printf("Error: Could not read %d elements from file.\n", n);
        free(arr);
        return 1;
    }

    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Heap Sort\n");
    printf("\nEnter your choice: ");
    
    int choice;
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 6) {
        printf("Invalid choice!\n");
        free(arr);
        return 1;
    }

    start = clock();
    switch (choice) {
        case 1:
            printf("\n=== Bubble Sort Results ===\n");
            bubble_sort(arr, n);
            break;
        case 2:
            printf("\n=== Selection Sort Results ===\n");
            selection_sort(arr, n);
            break;
        case 3:
            printf("\n=== Insertion Sort Results ===\n");
            insertion_sort(arr, n);
            break;
        case 4:
            printf("\n=== Merge Sort Results ===\n");
            merge_sort(arr, 0, n - 1);
            break;
        case 5:
            printf("\n=== Quick Sort Results ===\n");
            quick_sort(arr, 0, n - 1);
            break;
        case 6:
            printf("\n=== Heap Sort Results ===\n");
            heap_sort(arr, n);
            break;
    }
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %.6f seconds\n", time_spent);

    free(arr);
    return 0;
}