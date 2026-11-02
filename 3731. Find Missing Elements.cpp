#include <stdlib.h>

int* findMissingElements(int* nums, int numsSize, int* returnSize) {

    int min = nums[0];
    int max = nums[0];

    // Find minimum and maximum
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min)
            min = nums[i];

        if (nums[i] > max)
            max = nums[i];
    }

    int* ans = (int*)malloc(100 * sizeof(int));
    int k = 0;

    // Check every number from min to max
    for (int i = min; i <= max; i++) {

        int found = 0;

        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == i) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            ans[k++] = i;
        }
    }

    *returnSize = k;

    return ans;
}
