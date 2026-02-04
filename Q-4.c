//Given an array of n integers, reverse the array in-place using two-pointer approach.

#include <stdio.h>

int main() {
    int n, i;
    
    // Read number of elements
    scanf("%d", &n);
    
    int arr[n];
    
    // Read array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Two-pointer approach
    int start = 0;
    int end = n - 1;
    int temp;
    
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
    
    // Print reversed array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
