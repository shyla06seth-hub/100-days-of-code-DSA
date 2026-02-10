//Read a string and check if it is a palindrome using two-pointer comparison.

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int start, end;

    // Read the string
    scanf("%s", s);

    start = 0;
    end = strlen(s) - 1;

    // Two-pointer comparison
    while (start < end) {
        if (s[start] != s[end]) {
            printf("NO\n");
            return 0;
        }
        start++;
        end--;
    }

    printf("YES\n");
    return 0;
}
