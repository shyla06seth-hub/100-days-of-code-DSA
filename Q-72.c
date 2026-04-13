//Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    
    scanf("%999s", s);

    int freq[26] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int index = s[i] - 'a';

        if (freq[index] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }

        freq[index]++;
    }

    printf("-1\n");

    return 0;
}