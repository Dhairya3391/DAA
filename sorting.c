#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // swap arr[i] and arr[min_index]
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                // swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // swap arr[i + 1] and arr[high]
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        // swap arr[i] and arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        // swap arr[0] and arr[i]
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void free_array(int *arr) {
    free(arr);
}

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

    switch (filename) {
        case 1:
            file = fopen("a_best.txt", "r");
            break;
        case 2:
            file = fopen("a_average.txt", "r");
            break;
        case 3:
            file = fopen("a_worst.txt", "r");
            break;
    }
    
    if (file == NULL) {
        printf("Error opening input file!\n");
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error reading from file!\n");
            fclose(file);
            free(arr);
            return 1;
        }
    }
    fclose(file);

    // printf("Original array: ");
    // print_array(arr, n);

    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Heap Sort\n");
    printf("\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            start = clock();
            printf("\n=== Bubble Sort Results ===\n");
            // printf("Original array: ");
            // print_array(arr, n);
            // printf("Sorting...\n");
            bubble_sort(arr, n);
            // printf("Sorted array: ");
            // print_array(arr, n);
            end = clock();
            time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("\nTime taken: %.6f seconds\n", time_spent);
            break;
        case 2:
            start = clock();
            printf("\n=== Selection Sort Results ===\n");
            // printf("Original array: ");
            // print_array(arr, n);
            // printf("Sorting...\n");
            selection_sort(arr, n);
            // printf("Sorted array: ");
            // print_array(arr, n);
            end = clock();
            time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("\nTime taken: %.6f seconds\n", time_spent);
            break;
        case 3:
            start = clock();
            printf("\n=== Insertion Sort Results ===\n");
            // printf("Original array: ");
            // print_array(arr, n);
            // printf("Sorting...\n");
            insertion_sort(arr, n);
            // printf("Sorted array: ");
            // print_array(arr, n);
            end = clock();
            time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("\nTime taken: %.6f seconds\n", time_spent);
            break;
        case 4:
            start = clock();
            printf("\n=== Merge Sort Results ===\n");
            // printf("Original array: ");
            // print_array(arr, n);
            // printf("Sorting...\n");
            merge_sort(arr, 0, n - 1);
            // printf("Sorted array: ");
            // print_array(arr, n);
            end = clock();
            time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("\nTime taken: %.6f seconds\n", time_spent);
            break;
        case 5:
            start = clock();
            printf("\n=== Quick Sort Results ===\n");
            // printf("Original array: ");
            // print_array(arr, n);
            // printf("Sorting...\n");
            quick_sort(arr, 0, n - 1);
            // printf("Sorted array: ");
            // print_array(arr, n);
            end = clock();
            time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("\nTime taken: %.6f seconds\n", time_spent);
            break;
        case 6:
            start = clock();
            printf("\n=== Heap Sort Results ===\n");
            // printf("Original array: ");
            // print_array(arr, n);
            // printf("Sorting...\n");
            heap_sort(arr, n);
            // printf("Sorted array: ");
            // print_array(arr, n);
            end = clock();
            time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("\nTime taken: %.6f seconds\n", time_spent);
            break;
        default:
            printf("Invalid choice!\n");
            free_array(arr);
            return 1;
    }
    // printf("\n=== Final Results ===\n");
    // printf("Sorted array: ");
    // print_array(arr, n);
    // printf("\n");

    free_array(arr);
}