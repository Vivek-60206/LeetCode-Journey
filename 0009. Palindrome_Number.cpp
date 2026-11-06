class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases:
        // 1. Negative numbers are never palindromes (e.g., -121 -> 121-).
        // 2. Numbers ending in 0 (except 0 itself) cannot be palindromes
        //    because numbers do not start with a leading zero.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        // Revert digits until we reach the middle of the number
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit
        // by revertedNumber / 10. For example, for 12321 :
        // at the end of the loop, x = 12, revertedNumber = 123.
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
