class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        // dp[i][j] = maximum score difference
        // the current player can achieve
        // using piles from i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: only one pile
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // Build answers for larger ranges
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                // Take the left pile
                int takeLeft = piles[i] - dp[i + 1][j];

                // Take the right pile
                int takeRight = piles[j] - dp[i][j - 1];

                // Choose the better option
                dp[i][j] = max(takeLeft, takeRight);
            }
        }

        // Positive difference means Alice wins
        return dp[0][n - 1] > 0;
    }
};