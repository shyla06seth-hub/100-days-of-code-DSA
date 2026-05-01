//Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

#include <stdio.h>

#define MAX 100

// Check if it's possible to paint within maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (currTime + arr[i] <= maxTime) {
            currTime += arr[i];
        } else {
            painters++;
            currTime = arr[i];
        }

        if (painters > k)
            return 0;
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[MAX];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int low = maxVal;
    int high = sum;
    int ans = sum;

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;        // possible
            high = mid - 1;   // try smaller
        } else {
            low = mid + 1;    // increase time
        }
    }

    printf("%d\n", ans);

    return 0;
}