#include <stdlib.h>
#include <string.h>

char** buildArray(int* target, int targetSize, int n, int* returnSize) {

    char** ans = (char**)malloc(2 * n * sizeof(char*));
    int k = 0;
    int j = 0;

    for (int i = 1; i <= n && j < targetSize; i++) {

        ans[k++] = "Push";

        if (i == target[j]) {
            j++;
        }
        else {
            ans[k++] = "Pop";
        }
    }

    *returnSize = k;

    return ans;
}
