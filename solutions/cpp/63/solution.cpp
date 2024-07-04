class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> obstacleGrid;
    int m;
    int n;
    // Top down approach
    // Time complexity: O(m * n)
    // Space complexity: O(m * n)
    int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
        this->obstacleGrid = obstacleGrid;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        memo = vector(m, vector(n, -1));
        return dp(m - 1, n - 1);
    }
    int dp(int row, int col) {
        // Base case
        if (row == 0 && col == 0 && obstacleGrid[row][col] == 0) {
            return 1;
        }
        // Base case: obstacle
        if (obstacleGrid[row][col] == 1) {
            return 0;
        }
        if (memo[row][col] != -1) {
            return memo[row][col];
        }
        int ans = 0;
        if (row > 0) {
            ans += dp(row - 1, col);
        }
        if (col > 0) {
            ans += dp(row, col - 1);
        }
        memo[row][col] = ans;
        return ans;
    }
    // Bottom up approach
    // Time complexity: O(m * n)
    // Space complexity: O(m * n)
    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>> dp = vector(m, vector(n, 0));
        if (!obstacleGrid[0][0]) {
            // Base case
            dp[0][0] = 1;
        }
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (obstacleGrid[row][col] == 1) {
                    continue;
                }
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
    // Bottom up approach improved
    // Time complexity: O(m * n)
    // Space complexity: O(n)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        if (!obstacleGrid[0][0]) {
            // Base case
            dp[0] = 1;
        }
        for (int row = 0; row < m; row++) {
            vector<int> nextRow(n, 0);
            for (int col = 0; col < n; col++) {
                if (obstacleGrid[row][col] == 1) {
                    continue;
                }
                nextRow[col] = dp[col];
                if (col > 0) {
                    nextRow[col] += nextRow[col - 1];
                }
            }
            dp = nextRow;
        }
        return dp[n - 1];
    }
};