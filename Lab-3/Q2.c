// Write a menu driven program to sort a list of elements in ascending
// order using InsertionSort technique. The nature of the input data is choice based anda distinct file
// is considered for each choice.The sorted elements can be stored in a separate output file. After
// sorting display the content of the output file along with number of comparisons. Based on the
// number of comparisons, conclude the input scenario is either best or worst case.

#include <stdio.h>
#include <string.h>
void insertionSort(int arr[], int n, int *comparisons)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            (*comparisons)++;
        }
        arr[j + 1] = key;
    }
}

void readFromFile(const char *filename, int arr[], int n)
{
    FILE *file = fopen(filename, "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}

void writeToFile(const char *filename, int arr[], int n)
{
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

int main()
{
    int option;
    int data[50000]; // Assuming maximum size
    int n = 10;

    while (1)
    {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter option: ");
        scanf("%d", &option);

        if (option == 4)
        {
            break;
        }

        char inputFile[20], outputFile[20];

        if (option == 1)
        {
            strcpy(inputFile, "ascending.txt");
            strcpy(outputFile, "output1.txt");
        }
        else if (option == 2)
        {
            strcpy(inputFile, "decending.txt");
            strcpy(outputFile, "output2.txt");
        }
        else if (option == 3)
        {
            strcpy(inputFile, "numbers.txt");
            strcpy(outputFile, "output3.txt");
        }
        else
        {
            printf("Invalid option. Please choose a valid option.\n");
            continue;
        }

        FILE *input = fopen(inputFile, "r");
        // fscanf(input, "%d", &n);
        for (int i = 0; i < n; i++)
        {
            fscanf(input, "%d", &data[i]);
        }
        fclose(input);

        int comparisons = 0;
        insertionSort(data, n, &comparisons);

        printf("Before Sorting: Content of the input file\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", data[i]);
        }
        printf("\n");

        writeToFile(outputFile, data, n);

        printf("After Sorting: Content of the output file\n");
        FILE *output = fopen(outputFile, "r");
        for (int i = n - 1; i >= 0; i--)
        {
            fscanf(output, "%d", &data[i]);
            printf("%d ", data[i]);
        }
        fclose(output);
        printf("\n");

        printf("Number of Comparisons: %d\n", comparisons);

        if (comparisons == n - 1)
        {
            printf("Scenario: Best-case\n");
        }
        else if (comparisons == (n * (n - 1)) / 2)
        {
            printf("Scenario: Worst-case\n");
        }
        else
        {
            printf("Scenario: Average-case\n");
        }
    }

    return 0;
}
