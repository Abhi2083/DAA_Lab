// Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i].
#include <stdio.h>

int main(){
    int n;
    printf("Enter the size of array(>5):-");
    scanf("%d",&n);
    int arr[5];
    printf("Enter the elements:-");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum=0,prifixSum[n];
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
        prifixSum[i]=sum;
    }
    
    printf("\n");    
    for(int i=0;i<n;i++){
        printf("%d ",prifixSum[i]);
    }
    
    return 0;
}