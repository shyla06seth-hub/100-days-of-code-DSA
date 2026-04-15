//Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    
    // Input
    scanf("%999s", s);

    int freq[26] = {0};

    // Step 1: Count frequency
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: Find first non-repeating character
    for (int i = 0; i < len; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // If none found
    printf("$\n");

    return 0;
}