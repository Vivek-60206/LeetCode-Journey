#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {

    int* count = (int*)calloc(numsSize + 1, sizeof(int));

    // Mark numbers that are present
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }

    // Array for answer
    int* ans = (int*)malloc(numsSize * sizeof(int));
    int k = 0;

    // Find missing numbers
    for (int i = 1; i <= numsSize; i++) {
        if (count[i] == 0) {
            ans[k++] = i;
        }
    }

    *returnSize = k;

    free(count);

    return ans;
}
