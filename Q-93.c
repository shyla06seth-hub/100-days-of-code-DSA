//Sort an array using insertion sort.

#include <stdio.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];

    // Input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort (stable)
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        // (using '>' keeps it stable)
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at correct position
        arr[j + 1] = key;
    }

    // Output
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}