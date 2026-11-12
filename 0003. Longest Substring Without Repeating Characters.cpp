#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Stores the last seen index of each character (ASCII 0-255)
        std::vector<int> lastIndex(256, -1);
        
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < static_cast<int>(s.length()); ++right) {
            unsigned char currentChar = static_cast<unsigned char>(s[right]);

            // If the character was seen inside the current window, move 'left'
            if (lastIndex[currentChar] >= left) {
                left = lastIndex[currentChar] + 1;
            }

            // Update the last seen position of the current character
            lastIndex[currentChar] = right;

            // Update maximum window length
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
