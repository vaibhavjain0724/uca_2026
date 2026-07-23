//smaller numbers after self

typedef struct{
    int value;
    int originalIndex;
} Element;

#include <stdio.h>
#include <stdlib.h>

int smaller[100001];

void divide(Element nums[], int start, int end);
void merge(Element nums[], int start, int mid, int end);
void countPairs(Element nums[], int start, int mid, int end);

void divide(Element nums[], int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2 + 1;

    divide(nums, start, mid - 1);
    divide(nums, mid, end);

    countPairs(nums, start, mid, end);
    merge(nums, start, mid, end);
}

void countPairs(Element nums[], int start, int mid, int end) {
    int firstInd = start;
    int secondInd = mid;

    while (firstInd < mid ) {
        while(secondInd <= end && nums[firstInd].value > nums[secondInd].value) secondInd++;
        
        smaller[nums[firstInd].originalIndex] += secondInd - mid;

        firstInd++;
    }
}

void merge(Element nums[], int start, int mid, int end) {
    int size = end - start + 1;
    Element *merged = malloc(size * sizeof(Element));

    if (merged == NULL) {
        exit(1);
    }

    int first = start;
    int second = mid;
    int k = 0;

    while (first < mid && second <= end) {
        if (nums[first].value <= nums[second].value) {
            merged[k].value = nums[first].value;
            merged[k].originalIndex = nums[first].originalIndex;
            k++;
            first++;
        } else {
            merged[k].value = nums[second].value;
            merged[k].originalIndex = nums[second].originalIndex;
            k++;
            second++;
        }
    }

    while (first < mid) {
        merged[k].value = nums[first].value;
        merged[k].originalIndex = nums[first].originalIndex;
        k++;
        first++;

    }

    while (second <= end) {
        merged[k].value = nums[second].value;
        merged[k].originalIndex = nums[second].originalIndex;
        k++;
        second++;
    }

    for (int i = 0; i < size; i++) {
        nums[start + i] = merged[i];
    }

    free(merged);
}

int main() {
    Element nums[100001];
    int n = 0;

    while (n < 100001 && scanf("%d", &nums[n].value) == 1) {
        nums[n].originalIndex = n;
        n++;
    }   

    if (n == 0) return 0;

    divide(nums, 0, n - 1);


    for(int i= 0 ; i < n ; i++){
       printf("%d ", smaller[i] );
    }
    printf("\n");



    return 0;
}

