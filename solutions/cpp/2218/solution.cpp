class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> piles;
    // Top-down approach
    // Average number of coins per pile piles[i].length = x
    // n - number of piles
    // k - number of remaining coins we can take
    // Time complexity: O(x * n * k)
    // Space complexity: O(n * k)
    int maxValueOfCoins2(vector<vector<int>>& piles, int k) {
        this->piles = piles;
        memo = vector(piles.size(), vector(k + 1, -1));
        return dp(0, k);
    }
    int dp(int i, int k) {
        if (i == piles.size() || k == 0) {
            return 0;
        }
        if (memo[i][k] != -1) {
            return memo[i][k];
        }
        // Skip current pile
        int ans = dp(i + 1, k);
        int curr = 0;
        for (int j = 0; j < min((int)piles[i].size(), k); j++) {
            // Add up to j coins to the wallet
            curr += piles[i][j];
            // Remove up to j + 1 from remaining
            ans = max(ans, curr + dp(i + 1, k - j - 1));
        }
        memo[i][k] = ans;
        return ans;
    }
    // Bottom-up approach
    // Average number of coins per pile piles[i].length = x
    // n - number of piles
    // k - number of remaining coins we can take
    // Time complexity: O(x * n * k)
    // Space complexity: O(n * k)
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(vector(n+1, vector(k+1, 0)));
        // Start from the base cases
        for (int i = piles.size() - 1; i >= 0; i--) {
            for (int remain = 1; remain <= k; remain++) {
                // Skip pile
                int ans = dp[i + 1][remain];
                int pileSize = piles[i].size();
                int curr = 0;
                for (int j = 0; j < min(pileSize, remain); j++) {
                    curr += piles[i][j];
                    ans = max(ans, curr + dp[i + 1][remain - j - 1]);
                }
                dp[i][remain] = ans;
            }
        }
        return dp[0][k];
    }
};