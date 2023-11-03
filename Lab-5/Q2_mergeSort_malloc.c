#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int l, int u, int m)
{
    int i = l, j = m + 1, k = 0;
    int *out = (int *)malloc(sizeof(int) * (u - (l + 1)));
    while (i <= m && j <= u)
    {
        if (arr[i] < arr[j])
        {
            out[k++] = arr[i++];
        }
        else
        {
            out[k++] = arr[j++];
        }
    }
    while (i <= m)
    {
        out[k++] = arr[i++];
    }
    while (j <= u)
    {
        out[k++] = arr[j++];
    }
    for (int x = 0; x < k; x++)
    {
        arr[l + x] = out[x];
    }
}
void mergesort(int *arr, int l, int u)
{
    if (l < u)
    {
        int m = ((l + u) / 2);
        mergesort(arr, l, m);
        mergesort(arr, m + 1, u);
        merge(arr, l, u, m);
    }
}
void printarr(int arr[], int size)
{
    // printf("Array value are: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter NUmber Of elment In array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter Element of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //     int data[] = {9, 5, 1, 4, 3};
    //    int size = sizeof(data) / sizeof(data[0]);

    // insort(arr,n);
    // printarr(arr,n);
    printf("mergesort\n");
    mergesort(arr, 0, n);
    printarr(arr, n);

return 0;
}
