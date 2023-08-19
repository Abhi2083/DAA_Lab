#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to merge two subarrays of arr[]
void merge(int arr[], int left, int middle, int right, long long int *comparisons) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(int arr[], int left, int right, long long int *comparisons) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle, comparisons);
        mergeSort(arr, middle + 1, right, comparisons);
        merge(arr, left, middle, right, comparisons);
    }
}

int main() {
    int option;
    long long int comparisons = 0;
    clock_t start, end; // Changed to clock_t
    
    while (1) {
        printf("MAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        if (option == 4) {
            printf("Exiting...\n");
            break;
        }

        char filename[20];
        if (option == 1)
            strcpy(filename, "decending.txt");
        else if (option == 2)
            strcpy(filename, "decending.txt");
        else if (option == 3)
            strcpy(filename, "numbers.txt");
        else {
            printf("Invalid option!\n");
            continue;
        }

        FILE *inputFile = fopen(filename, "r");
        if (inputFile == NULL) {
            printf("Failed to open the input file.\n");
            continue;
        }

        int n;
        fscanf(inputFile, "%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            fscanf(inputFile, "%d", &arr[i]);
        }
        fclose(inputFile);

        comparisons = 0;
        start = clock(); // Use clock() to start the timer
        mergeSort(arr, 0, n - 1, &comparisons);
        end = clock(); // Use clock() to end the timer
        
        double executionTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1e9;
        
        char outputFilename[20];
        if (option == 1)
            strcpy(outputFilename, "outMergeAsce.txt");
        else if (option == 2)
            strcpy(outputFilename, "outMergeDesc.txt");
        else if (option == 3)
            strcpy(outputFilename, "outMergeRand.txt");

        FILE *outputFile = fopen(outputFilename, "w");
        if (outputFile == NULL) {
            printf("Failed to open the output file.\n");
            continue;
        }

        fprintf(outputFile, "Sorted Array:\n");
        for (int i = 0; i < n; i++) {
            fprintf(outputFile, "%d ", arr[i]);
        }
        fprintf(outputFile, "\nNumber of Comparisons: %lld\n", comparisons);
        fprintf(outputFile, "Execution Time (ns): %.2lf\n", executionTime);

        fclose(outputFile);

        printf("Sorting completed. Results written to %s\n", outputFilename);
    }

    return 0;
}