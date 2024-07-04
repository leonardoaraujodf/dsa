class Solution {
public:
    // Top down approach
    // 1. The function dp will return the minimum falling path sum starting in a col as required by the problem.
    // 2. Our states are related to row and col.
    // 3. The base case will be when row == 0. Just return matrix[0][col]
    // 4. The recurrence relation is as follows: ans = min of (dp[row - 1][col], dp[row - 1][col - 1], dp[row - 1][col + 1]). Beware of the column limits!
    // Time complexity: O(n^2)
    // Space complexity: O(n^2)
    vector<vector<int>> memo;
    int n;
    vector<vector<int>> matrix;
    int minFallingPathSum1(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        n = matrix[0].size();
        memo = vector(n, vector(n, INT_MAX));
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp(n - 1, i));
        }
        return ans;
    }
    int dp(int row, int col) {
        // Base case
        if (row == 0) {
            return matrix[row][col];
        }
        if (memo[row][col] != INT_MAX) {
            return memo[row][col];
        }
        int ans = dp(row - 1, col);
        if (col > 0) {
            ans = min(ans, dp(row - 1, col - 1));
        }
        if (col < n - 1) {
            ans = min(ans, dp(row - 1, col + 1));
        }
        memo[row][col] = ans + matrix[row][col];
        return memo[row][col];
    }
    // Bottom up approach optimized
    // Time complexity: O(n^2)
    // Space complexity: O(n)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix[0].size();
        // Base case
        vector<int> dp(n, 0);
        for (int row = 0; row < n; row++) {
            vector<int> nextRow(n, 0);
            for (int col = 0; col < n; col++) {
                nextRow[col] = dp[col];
                if (col > 0) {
                    nextRow[col] = min(nextRow[col], dp[col - 1]);
                }
                if (col < n - 1) {
                    nextRow[col] = min(nextRow[col], dp[col + 1]);
                }
                nextRow[col] += matrix[row][col];
            }
            dp = nextRow;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};