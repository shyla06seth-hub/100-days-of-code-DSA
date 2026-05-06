//Given n real numbers in [0,1), sort using bucket sort algorithm.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Insertion sort for a bucket
void insertionSort(float bucket[], int size) {
    for (int i = 1; i < size; i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[MAX];

    // Input
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Create buckets
    float buckets[MAX][MAX];
    int bucketSize[MAX] = {0};

    // Step 1: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];  // bucket index
        buckets[index][bucketSize[index]++] = arr[i];
    }

    // Step 2: Sort each bucket
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketSize[i]);
    }

    // Step 3: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    // Output
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}