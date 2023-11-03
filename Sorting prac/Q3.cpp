#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &(arr[j + 1]));
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(&arr[k], &arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    string filename, opfile;
    int number;
    int size;
    cin >> size;
    cin >> filename;
    int arr[size];
    int ct = 0;
    ifstream input_file(filename);
    while (input_file >> number && ct < size)
    {
        arr[ct++] = number;
    }

    clock_t start, end;

    cout << "Select sorting methond: " << endl
         << "1. Bubble Sort" << endl
         << "2. Selection Sort" << endl;
    int choice;
    cin >> choice;
    start = clock();
    switch (choice)
    {
    case 1:
        bubbleSort(arr, size);
    case 2:
        selectionSort(arr, size);
    }

    end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
return 0;
}