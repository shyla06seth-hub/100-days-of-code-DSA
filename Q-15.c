//Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

#include <stdio.h>

int main() {
    int m, n;
    int sum = 0;

    // Read rows and columns
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Read matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);

            // Add only primary diagonal elements
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }

    // Print the sum
    printf("%d", sum);

    return 0;
}
