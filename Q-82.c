//Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

#include <stdio.h>

#define MAX 100

// Lower Bound: first index where arr[i] >= x
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;  // default if not found

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1; // go left
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

// Upper Bound: first index where arr[i] > x
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1; // go left
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];

    // Input array (sorted)
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}