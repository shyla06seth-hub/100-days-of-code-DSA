//Given an array of integers, find two elements whose sum is closest to zero.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minSum = abs(arr[0] + arr[1]);
    int a = arr[0], b = arr[1];

    // Check all pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if (abs(sum) < minSum) {
                minSum = abs(sum);
                a = arr[i];
                b = arr[j];
            }
        }
    }

    // Print result
    printf("%d %d", a, b);

    return 0;
}
