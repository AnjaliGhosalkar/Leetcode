class Solution {
public:

    void generate(string current, int open, int close, int n,
                  vector<string>& ans) {

        // If we have used all brackets
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // We can add '(' if we still have opening brackets
        if (open < n) {
            generate(current + "(", open + 1, close, n, ans);
        }

        // We can add ')' only if there is an unmatched '('
        if (close < open) {
            generate(current + ")", open, close + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        generate("", 0, 0, n, ans);

        return ans;
    }
};