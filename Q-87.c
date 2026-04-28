//Implement Binary Search Iterative - Implement the algorithm.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort array (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter element to search: ");
    int key;
    scanf("%d", &key);

    // Step 2: Binary Search (Iterative)
    int low = 0, high = n - 1;
    int found = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            found = mid;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    // Output result
    if (found != -1)
        printf("Element found at index %d\n", found);
    else
        printf("Element not found\n");

    return 0;
}