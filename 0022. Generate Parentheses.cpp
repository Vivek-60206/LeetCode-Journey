class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, int open, int close, int n) {
        // Base case: all n pairs are placed
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Choice 1: Add '(' if we haven't used all n
        if (open < n) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, n);
            current.pop_back(); // backtrack
        }

        // Choice 2: Add ')' if it can close an existing '('
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, n);
            current.pop_back(); // backtrack
        }
    }
};
