#include<stdio.h>

void insertion_sort(int *arr,int n){
    for(int i=0;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                //shift
                arr[j+1]=arr[j];
            }else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}

int main(){
    int n;
    printf("Enter size of Array:");
    scanf("%d",&n);
    int arr[20];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr,n);
  
    int ssmallest=arr[1],slargest=arr[n-2];
    
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[i+1]){
            ssmallest=arr[i+1];
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]!=arr[i-1]){
            slargest=arr[i-1];
            break;
        }
    }

    printf("Second Smalles : %d\n",ssmallest);
    printf("Second largest:%d",slargest);
}