//Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

#include <stdio.h>

#define MAX 100

// Check if allocation is possible with maxPages limit
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book exceeds maxPages → impossible
        if (arr[i] > maxPages)
            return 0;

        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            students++;
            pagesSum = arr[i];
        }

        if (students > m)
            return 0;
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

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

        if (isPossible(arr, n, m, mid)) {
            ans = mid;        // possible
            high = mid - 1;   // try smaller max
        } else {
            low = mid + 1;    // increase limit
        }
    }

    printf("%d\n", ans);

    return 0;
}