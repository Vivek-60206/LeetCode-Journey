#include <climits>
#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits and handle clamp/overflow
        int result = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // Check for potential overflow before multiplying by 10
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
