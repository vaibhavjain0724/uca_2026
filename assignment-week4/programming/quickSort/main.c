
#include "quickSelect.h"
#include <stdio.h>

void printArr(int arr[], int n){
      for(int i= 0 ; i< n ; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");

}

int main(){

    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i =0 ; i < n ; i++){
        scanf("%d", &arr[i]);
    }
    
    int k;
    scanf("%d" ,&k);

    if (k <= 0 || k > n) {
        printf("Invalid k\n");
        return 1;
    }

    if(k == n) {

        printArr(arr, n);
        return 1; 
    }
    kthSmallest(arr, k,  0 , n);

   printArr(arr, k);

}