#include <stdlib.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int count[10001] = {0};
    int duplicate = 0;
    int missing = 0;

    // Count each number
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }

    // Find duplicate and missing
    for (int i = 1; i <= numsSize; i++) {
        if (count[i] == 2)
            duplicate = i;

        if (count[i] == 0)
            missing = i;
    }

    int* ans = (int*)malloc(2 * sizeof(int));

    ans[0] = duplicate;
    ans[1] = missing;

    *returnSize = 2;

    return ans;
}
