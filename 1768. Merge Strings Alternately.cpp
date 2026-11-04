#include <stdlib.h>
#include <string.h>

char* mergeAlternately(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    // Allocate enough memory for both strings + '\0'
    char* result = (char*)malloc(len1 + len2 + 1);

    int i = 0;  // index for word1
    int j = 0;  // index for word2
    int k = 0;  // index for result

    // Add characters alternately
    while (i < len1 && j < len2) {
        result[k++] = word1[i++];
        result[k++] = word2[j++];
    }

    // Add remaining characters of word1
    while (i < len1) {
        result[k++] = word1[i++];
    }

    // Add remaining characters of word2
    while (j < len2) {
        result[k++] = word2[j++];
    }

    // End the C string
    result[k] = '\0';

    return result;
}
