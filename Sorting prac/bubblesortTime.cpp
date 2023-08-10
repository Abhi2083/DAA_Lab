#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void BubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            // already sorted, no need to continue
            break;
        }
    }
}

int main()
{
    const int MAX_SIZE = 10000; 
    int arr[MAX_SIZE];
    int n = 0; 

    ifstream inputFile("numbers.txt");

    if (!inputFile)
    {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    while (n < MAX_SIZE && inputFile >> arr[n])
    {
        n++;
    }

    inputFile.close();

    clock_t t1 = clock();
    BubbleSort(arr, n);
    clock_t t2 = clock();

    ofstream outputFile("output_file.txt");
    if (!outputFile)
    {
        cerr << "Error creating output file." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        outputFile << arr[i] << " ";
    }

    outputFile.close();

    clock_t t3 = t2 - t1;
    double result = (double)(t3) / CLOCKS_PER_SEC;
    printf("Sorting time: %lf seconds\n", result);

    return 0;
}
