class Solution {
    // Top down approach
    // Time complexity: O(n^2)
    // Space complexity: O(n)
    int lengthOfLIS(vector<int> &nums) {
        vector<int> memo(nums.size(), -1);

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, dp(i, nums, memo));
        }
        return ans;
    }

    int dp(int i, vector<int> &nums, vector<int> &memo) {
        if (memo[i] != -1) {
            return memo[i];
        }

        int ans = 1;// Base case
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                ans = max(ans, dp(j, nums, memo) + 1);
            }
        }

        memo[i] = ans;
        return memo[i];
    }

    // Bottom up approach
    // Time complexity: O(n^2)
    // Space complexity: O(n)
    int lengthOfLIS2(vector<int> &nums) {
        vector<int> dp(nums.size(), -1);
        int ans = 0;
        
        return ans;
    }
};