#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void kthSmallest(int arr[], int k, int st, int e);

int main() {
    srand(time(NULL));

    int sizes[] = {1000, 5000, 10000, 20000, 50000, 100000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    const int TRIALS = 100;

    printf("n,time\n");

    for (int s = 0; s < numSizes; s++) {

        int n = sizes[s];
        double totalTime = 0.0;

        for (int t = 0; t < TRIALS; t++) {

            int *arr = malloc(n * sizeof(int));

            for (int i = 0; i < n; i++)
                arr[i] = rand();

            int k = n / 2;

            clock_t start = clock();

            kthSmallest(arr, k, 0, n);

            clock_t end = clock();

            totalTime += (double)(end - start) / CLOCKS_PER_SEC;

            free(arr);
        }

        printf("%d,%lf\n", n, totalTime / TRIALS);
    }

    return 0;
}