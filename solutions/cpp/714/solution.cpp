class Solution {
public:
    // First dimension: days (has length of prices.size())
    // Second dimension: holding/not holding the stock
    vector<vector<int>> memo;
    vector<int> prices;
    int fee;
    // Top down approach
    // Time complexity: O(n), where n is the prices size. Holding/not holding is constant.
    // Space complexity: O(n), where n is the prices size. Holding/not holding is constant.
    int maxProfit2(vector<int>& prices, int fee) {
        this->prices = prices;
        this->fee = fee;
        memo = vector(prices.size(), vector(2, -1));
        return dp(0, 0);
    }
    int dp(int i, int holding) {
        // Base case
        if (i == prices.size()) {
            return 0;
        }
        if (memo[i][holding] != -1) {
            return memo[i][holding];
        }
        // Option 1: Skip
        int ans = dp(i + 1, holding);
        if (holding == 1) {
            // Option 2: Sell stock
            ans = max(ans, prices[i] + dp(i + 1, 0) - fee);
        } else {
            // Option 3: Buy stock
            ans = max(ans, -prices[i] + dp(i + 1, 1));
        }
        memo[i][holding] = ans;
        return ans;
    }
    // Bottom-up approach
    // Time and space complexity are the same from the top down approach.
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(vector(n + 1, vector(2, 0)));
        // Start from the base cases
        for (int i = n - 1; i >= 0; i--) {
            for (int holding = 0; holding < 2; holding++) {
                // Skip
                int ans = dp[i + 1][holding];
                if (holding == 1) {
                    // Sell
                    ans = max(ans, prices[i] + dp[i + 1][0] - fee);
                } else {
                    // Buy
                    ans = max(ans, -prices[i] + dp[i + 1][1]);
                }
                dp[i][holding] = ans;
            }
        }
        return dp[0][0];
    }
};