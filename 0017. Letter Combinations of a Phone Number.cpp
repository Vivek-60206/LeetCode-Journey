class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        // Mapping of digits 2-9 to their corresponding letters
        const vector<string> keypad = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> result;
        string current;
        backtrack(digits, 0, keypad, current, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, const vector<string>& keypad, 
                   string& current, vector<string>& result) {
        // Base case: built a combination matching the length of digits
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        // Get the letters corresponding to the current digit
        string letters = keypad[digits[index] - '0'];
        
        for (char letter : letters) {
            current.push_back(letter);                          // Choose
            backtrack(digits, index + 1, keypad, current, result); // Explore
            current.pop_back();                                 // Un-choose (Backtrack)
        }
    }
};
