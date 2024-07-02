class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> grid;
    int m;
    int n;
    // Top down approach
    // Time complexity: O(m * n)
    // Space complexity: O(m * n)
    int minPathSum2(vector<vector<int>>& grid) {
        this->grid = grid;
        this->m = grid.size();
        this->n = grid[0].size();
        memo = vector(grid.size(), vector(grid[0].size(), -1));
        return dp(m - 1, n - 1);
    }
    int dp(int row, int col) {
        if (row == 0 && col == 0) {
            memo[row][col] = grid[row][col];
            return grid[row][col];
        }
        if (memo[row][col] != -1) {
            return memo[row][col];
        }
        int ans = INT_MAX;
        if (row > 0) {
            ans = min(ans, dp(row - 1, col));
        }
        if (col > 0) {
            ans = min(ans, dp(row, col - 1));
        }
        memo[row][col] = ans + grid[row][col];
        return memo[row][col];
    }
    // Bottom up approach
    // Time complexity: O(m * n)
    // Space complexity: O(m * n)
    int minPathSum1(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp = vector(grid.size(), vector(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0) {
                    continue;
                }
                int ans = INT_MAX;
                if (row > 0) {
                    ans = dp[row - 1][col];
                }
                if (col > 0) {
                    ans = min(ans, dp[row][col - 1]);
                }
                dp[row][col] = ans + grid[row][col];
            }
        }
        return dp[m - 1][n - 1];
    }
    // Bottom up approach
    // Time complexity: O(m * n)
    // Space complexity: O(n)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int row = 0; row < m; row++) {
            vector<int> nextRow(n, 0);
            for (int col = 0; col < n; col++) {
                nextRow[col] = dp[col];
                if (col > 0) {
                    nextRow[col] = min(nextRow[col], nextRow[col - 1]);
                }
                nextRow[col] += grid[row][col];
            }
            dp = nextRow;
        }
        return dp[n - 1];
    }
};