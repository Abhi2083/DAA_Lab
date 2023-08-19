// Write a program to implement Binary Search to give the position of leftmost appearance of the element in the array being searched. Display the number of
// comparisons made while searching.
// Input:
// Enter size of array: 10
// Enter elements of the array: 2 3 7 7 7 11 12 12 20 50
// Enter the key to be searched: 7
// Output:
// 7 found at index position 2
// Number of comparisons: 3

#include <stdio.h>

int binary_search_leftmost(int arr[], int size, int key, int *comparisons) {
    int left = 0;
    int right = size - 1;
    int index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;

        if (arr[mid] == key) {
            index = mid;
            break;
            //right = mid - 1;  
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return index;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int comparisons = 0;
    int position = binary_search_leftmost(arr, size, key, &comparisons);

    if (position != -1) {
        printf("%d found at index position %d\n", key, position);
    } else {
        printf("%d not found in the array\n", key);
    }
    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
