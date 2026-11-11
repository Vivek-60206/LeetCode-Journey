#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen; // Key: number, Value: index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            // If complement is found in map, return indices
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }

            // Store current number with its index
            seen[nums[i]] = i;
        }

        return {}; // Fallback
    }
};
