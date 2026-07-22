
#include <stdio.h>
#include <stdlib.h>

long long totalPairs = 0;

void divide(int nums[], int start, int end);
void merge(int nums[], int start, int mid, int end);
void countPairs(int nums[], int start, int mid, int end);

void divide(int nums[], int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2 + 1;

    divide(nums, start, mid - 1);
    divide(nums, mid, end);

    countPairs(nums, start, mid, end);
    merge(nums, start, mid, end);
}

void countPairs(int nums[], int start, int mid, int end) {
    int firstInd = start;
    int secondInd = mid;

    while (firstInd < mid && secondInd <= end) {
        if ((long long)nums[firstInd] > 2LL * nums[secondInd]) {
            totalPairs += mid - firstInd;
            secondInd++;
        } else {
            firstInd++;
        }
    }
}

void merge(int nums[], int start, int mid, int end) {
    int size = end - start + 1;
    int *merged = malloc(size * sizeof(int));

    if (merged == NULL) {
        exit(1);
    }

    int first = start;
    int second = mid;
    int k = 0;

    while (first < mid && second <= end) {
        if (nums[first] <= nums[second]) {
            merged[k++] = nums[first++];
        } else {
            merged[k++] = nums[second++];
        }
    }

    while (first < mid) {
        merged[k++] = nums[first++];
    }

    while (second <= end) {
        merged[k++] = nums[second++];
    }

    for (int i = 0; i < size; i++) {
        nums[start + i] = merged[i];
    }

    free(merged);
}

int main(void) {
    int nums[100001];
    int n = 0;

    while (n < 100001 && scanf("%d", &nums[n]) == 1) {
        n++;
    }

    if (n == 0) return 0;

    divide(nums, 0, n - 1);

    printf("%lld\n", totalPairs);

    return 0;
}
