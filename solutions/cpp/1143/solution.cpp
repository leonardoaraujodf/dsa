class Solution {
public:
    string text1;
    string text2;
    // Top down
    // Time complexity: O(n * m)
    // Space complexity: O(n * m)
    int longestCommonSubsequence2(string text1, string text2) {
        this->text1 = text1;
        this->text2 = text2;
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        return dp(0, 0, memo);
    }
    int dp(int i, int j, vector<vector<int>> &memo) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans;
        if (text1[i] == text2[j]) {
            ans = 1 + dp(i + 1, j + 1, memo);
        } else {
            ans = max(dp(i + 1, j, memo), dp(i, j + 1, memo));
        }
        memo[i][j] = ans;
        return ans;
    }
    // Bottom up
    // Time complexity: O(n * m)
    // Space complexity: O(n * m)
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = text1.size() - 1; i >= 0; i--) {
            for (int j = text2.size() - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};