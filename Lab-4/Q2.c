#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the partitioning index
int partition(int arr[], int low, int high, long long int *comparisons) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high, long long int *comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int n, choice;
    long long int comparisons = 0;

    char inputFileName[50], outputFileName[50];
    
    while (1) {
        printf("MAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting...\n");
            break;
        }

        if (choice == 1) {
            strcpy(inputFileName, "ascending.txt");
            strcpy(outputFileName, "outQuickAsce.txt");
        } else if (choice == 2) {
            strcpy(inputFileName, "decending.txt");
            strcpy(outputFileName, "outQuickDesc.txt");
        } else if (choice == 3) {
            strcpy(inputFileName, "numbers.txt");
            strcpy(outputFileName, "outQuickRand.txt");
        } else {
            printf("Invalid option!\n");
            continue;
        }

        inputFile = fopen(inputFileName, "r");
        if (inputFile == NULL) {
            printf("Error opening input file.\n");
            continue;
        }

        fscanf(inputFile, "%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            fscanf(inputFile, "%d", &arr[i]);
        }
        fclose(inputFile);

        comparisons = 0;
        clock_t start_time, end_time;
        double cpu_time_used;

        start_time = clock();
        quickSort(arr, 0, n - 1, &comparisons);
        end_time = clock();
        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

        printf("Sorting completed.\n");
        printf("Before Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL) {
            printf("Error opening output file.\n");
            continue;
        }

        fprintf(outputFile, "Sorted Array:\n");
        for (int i = 0; i < n; i++) {
            fprintf(outputFile, "%d\n", arr[i]);
        }
        fprintf(outputFile, "Number of Comparisons: %lld\n", comparisons);
        
        // Determine the partitioning scenario
        if (comparisons == n - 1) {
            fprintf(outputFile, "Scenario: Worst-case\n");
        } else if (comparisons <= n / 2) {
            fprintf(outputFile, "Scenario: Best-case\n");
        } else {
            fprintf(outputFile, "Scenario: Average-case\n");
        }

        fprintf(outputFile, "Execution Time: %.6f seconds\n", cpu_time_used);
        fclose(outputFile);

        printf("Results written to %s\n", outputFileName);
    }

    return 0;
}
