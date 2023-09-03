#include <stdio.h>
int partition(int *arr, int lb, int ub)
{
    int start = lb, end = ub;
    int pivot = arr[lb], temp;

    while (start < end)
    {
        while (arr[start] <= pivot && start <= ub)
            start++;

        while (arr[end] > pivot && end >= lb)
            end--;

        if (start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    temp = arr[end];
    arr[end] = arr[lb];
    arr[lb] = temp;

    return end;
}

void quick_sort(int *arr, int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = partition(arr, lb, ub);
        quick_sort(arr, lb, loc - 1);
        quick_sort(arr, loc + 1, ub);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements in the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
