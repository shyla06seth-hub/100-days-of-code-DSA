//Given integers a and b, compute a^b using recursion without using pow() function.

#include <stdio.h>

// Recursive function to calculate a^b
int power(int a, int b) {
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}

int main() {
    int a, b;

    // Read input values
    scanf("%d %d", &a, &b);

    // Print result
    printf("%d\n", power(a, b));

    return 0;
}
