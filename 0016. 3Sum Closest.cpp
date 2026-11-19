#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            // Optional optimization: skip duplicate fixed elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];

                if (std::abs(current_sum - target) < std::abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }

                if (current_sum < target) {
                    ++left;
                } else if (current_sum > target) {
                    --right;
                } else {
                    // Exact match found
                    return target;
                }
            }
        }

        return closest_sum;
    }
};
