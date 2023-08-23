#include <stdio.h>

int binarySearch(int arr[], int start, int end, int key) {
    int mid;
    
    if (end >= start) {
        mid = start + (end - start) / 2;
        
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] > key) {
            return binarySearch(arr, start, mid - 1, key);
        }
        return binarySearch(arr, mid + 1, end, key);
    }
    
    return -1; 
}

int main() {
    int n, k;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements in the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }
    
    printf("Enter the element to be searched: ");
    scanf("%d", &k);

    int search = binarySearch(arr, 0, n - 1, k);
    
    if (search != -1) {
        printf("Element found at index %d\n", search);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
