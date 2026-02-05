//A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>

int main() {
    int p, q, i;

    // Read size of first log
    scanf("%d", &p);
    int a[p];

    // Read first sorted log
    for (i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Read size of second log
    scanf("%d", &q);
    int b[q];

    // Read second sorted log
    for (i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i1 = 0, i2 = 0;

    // Merge both logs
    while (i1 < p && i2 < q) {
        if (a[i1] <= b[i2]) {
            printf("%d ", a[i1]);
            i1++;
        } else {
            printf("%d ", b[i2]);
            i2++;
        }
    }

    // Print remaining elements of first log
    while (i1 < p) {
        printf("%d ", a[i1]);
        i1++;
    }

    // Print remaining elements of second log
    while (i2 < q) {
        printf("%d ", b[i2]);
        i2++;
    }

    return 0;
}
