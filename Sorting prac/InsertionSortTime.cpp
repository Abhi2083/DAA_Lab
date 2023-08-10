#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void insertionSort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = array[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (array[j] > temp)
            {
                array[j + 1] = array[j];
            }
            else
            {
                break;
            }
        }
        array[j + 1] = temp;
    }
}

int main()
{
    const int MAX_SIZE = 10000;
    int arr[MAX_SIZE];
    int n = 0;

    string inputFileName;
    cout << "Enter the input file name: ";
    cin >> inputFileName;

    ifstream inputFile(inputFileName);

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
    insertionSort(arr, n);
    clock_t t2 = clock();

    ofstream outputFile("output_file1.txt");
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

    double result = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
    printf("Sorting time: %lf seconds\n", result);

    return 0;
}
