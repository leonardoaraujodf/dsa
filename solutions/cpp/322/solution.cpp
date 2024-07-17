class Solution {
public:
    // Top down approach
    // Time complexity: O(n * k), n = amount and k is the number of coins
    // Space complexity: O(n), where n is amount
    vector<int> memo;
    vector<int> coins;
    int coinChange1(vector<int>& coins, int amount) {
        memo = vector(amount + 1, 0);
        this->coins = coins;
        return dp(coins, amount);
    }

    int dp(vector<int> &coins, int amount) {
        // Base case
        if (amount == 0) {
            return 0;
        }

        if (memo[amount] != 0) {
            return memo[amount];
        }

        int ans = INT_MAX;
        for (int coin : coins) {
            if (coin <= amount) {
                int tmp = dp(coins, amount - coin);
                if (tmp != -1) {
                    ans = min(ans, tmp + 1);
                }
            }
        }

        if (ans == INT_MAX) {
            ans = -1;
        }

        memo[amount] = ans;
        return ans;
    }

    // Bottom up approach
    // Time complexity: O(n * k), n = amount and k is the number of coins
    // Space complexity: O(n), where n is amount
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        for (int i = 1; i <= amount; i++) {
            int ans = INT_MAX;
            for (int coin : coins) {
                if (coin <= i) {
                    int tmp = dp[i - coin];
                    if (tmp != -1) {
                        ans = min(ans, tmp + 1);
                    }
                }
            }
            if (ans == INT_MAX) {
                ans = -1;
            }
            dp[i] = ans;
        }
        return dp[amount];
    }
};