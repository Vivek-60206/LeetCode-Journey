#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);

    // Check same repeating pattern
    for (int i = 0; i < n1 + n2; i++) {
        if (str1[i % n1] != str2[i % n2]) {
            return "";
        }
    }

    // Find GCD of lengths
    int len = findGCD(n1, n2);

    // Create answer
    char* ans = (char*)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        ans[i] = str1[i];
    }

    ans[len] = '\0';

    return ans;
}
