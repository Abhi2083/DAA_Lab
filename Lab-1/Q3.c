#include<stdio.h>
#include<time.h>

int main(){
    clock_t t1=clock();
    int n;
    printf("Enter size of Array:");
    scanf("%d",&n);
    int arr[20];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int duplicate=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                duplicate++;
                break;
            }
        }
    }
    printf("duplicate count:%d\n",duplicate);

    int maxrepeat=0;
    int reapeated;
    for(int i=0;i<n;i++){
        int dcount=0;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                dcount++;   
            }
        }
        if(dcount>maxrepeat){
            maxrepeat=dcount;
            reapeated=arr[i];
        }
    }
    printf("Most repeating Element=%d\n",reapeated);
    clock_t t2=clock();
    clock_t t3=t2-t1;
    double res=(double)(t3/CLOCKS_PER_SEC);

    printf("%lf",res);
}