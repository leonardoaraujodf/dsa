class Solution {
public:
    int m;
    int n;
    vector<vector<int>> memo;
    // Top down approach
    // Time complexity: O(m * n)
    // Space complexity: O(m * n)
    int uniquePaths2(int m, int n) {
        this->m = m;
        this->n = n;
        memo = vector(m, vector(n, -1));
        return dp(m - 1, n - 1);
    }
    int dp(int row, int col) {
        if (row == 0 && col == 0) {
            return 1;
        }
        if (memo[row][col] != -1) {
            return memo[row][col];
        }
        int ways = 0;
        if (row > 0) {
            ways += dp(row - 1, col);
        }
        if (col > 0) {
            ways += dp(row, col - 1);
        }
        memo[row][col] = ways;
        return ways;
    }
    // Bottom-up approach
    // Time complexity: O(m * n)
    // Space complexity: O(m * n)
    int uniquePaths1(int m, int n) {
        vector<vector<int>> dp(m, vector(n, 0));
        dp[0][0] = 1;
        // Start at the base cases
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row > 0) {
                    dp[row][col] += dp[row - 1][col];
                }
                if (col > 0) {
                    dp[row][col] += dp[row][col - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    // Bottom-up approach improved
    // Time complexity: O(m * n)
    // Space complexity: O(n)
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            vector<int> nextRow(n, 0);
            for (int col = 0; col < n; col++) {
                nextRow[col] += dp[col];
                if (col > 0) {
                    nextRow[col] += nextRow[col - 1];
                }
            }
            dp = nextRow;
        }
        return dp[n - 1];
    }
};