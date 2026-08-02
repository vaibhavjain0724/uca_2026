#include <stdio.h>
#include <stdlib.h>
#include "quickSelect.h"
void swap(int arr[] , int a , int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void kthSmallest(int arr[], int k, int st, int e){
  
    if(st >= e) return;

    int pivot = st + rand() % (e - st);
    swap(arr, st, pivot);
    pivot = st;

    int newPivotInd = st;
    int i = st + 1;

    while(i < e){
        if(arr[i] < arr[pivot]){
            newPivotInd++;
            swap(arr, newPivotInd, i );
        }
        i++;
    }
    swap(arr, pivot , newPivotInd);

    if(newPivotInd == k-1) return; 


    if(newPivotInd <k-1 ){
        kthSmallest(arr, k , newPivotInd+1, e);
    }
    else{
        kthSmallest(arr, k, st, newPivotInd);
    }
    
}
