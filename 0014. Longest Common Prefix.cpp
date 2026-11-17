#include <vector>
#include <string>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (int col = 0; col < strs[0].size(); ++col) {
            char ch = strs[0][col];
            for (int row = 1; row < strs.size(); ++row) {
                // Check bounds and character equality
                if (col >= strs[row].size() || strs[row][col] != ch) {
                    return strs[0].substr(0, col);
                }
            }
        }

        return strs[0];
    }
};
