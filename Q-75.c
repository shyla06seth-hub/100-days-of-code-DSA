//Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    int maxLen = 0;

    // Hashing using arrays (simple approach)
    int prefixSum[MAX * 2];
    int index[MAX * 2];

    // Initialize
    for (int i = 0; i < MAX * 2; i++) {
        prefixSum[i] = 1000000000; // mark unused
        index[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum = 0 from start
        if (sum == 0) {
            maxLen = i + 1;
        }

        // Check if sum seen before
        int found = 0;
        for (int j = 0; j < MAX * 2; j++) {
            if (prefixSum[j] == sum) {
                int len = i - index[j];
                if (len > maxLen)
                    maxLen = len;
                found = 1;
                break;
            }
        }

        // Store first occurrence
        if (!found) {
            for (int j = 0; j < MAX * 2; j++) {
                if (prefixSum[j] == 1000000000) {
                    prefixSum[j] = sum;
                    index[j] = i;
                    break;
                }
            }
        }
    }

    printf("%d\n", maxLen);

    return 0;
}