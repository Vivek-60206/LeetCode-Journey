#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Always binary search on the smaller array for O(log(min(m, n)))
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            // Boundaries for nums1
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            // Boundaries for nums2
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Correct partition found
                if ((m + n) % 2 == 1) {
                    return std::max(maxLeft1, maxLeft2);
                } else {
                    return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
                }
            } else if (maxLeft1 > minRight2) {
                // We took too many elements from nums1, move left
                high = partition1 - 1;
            } else {
                // We need more elements from nums1, move right
                low = partition1 + 1;
            }
        }

        return 0.0;
    }
};
