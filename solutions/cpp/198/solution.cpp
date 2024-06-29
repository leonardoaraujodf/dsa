class Solution {
public:
    // Top-down approach
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        vector<int> memo = vector(nums.size(), -1);
        return dp(nums.size() - 1, nums, memo);
    }
    
    int dp(int i, vector<int> &nums, vector<int> &memo) {
        if (i == 0) {
            return nums[0];
        }
        
        if (i == 1) {
            return max(nums[0], nums[1]);
        }
        
        if (memo[i] != -1) {
            return memo[i];
        }
        
        memo[i] = max(dp(i - 1, nums, memo), dp(i - 2, nums, memo) + nums[i]);
        return memo[i];
    }

    // Bottom-up approach with space complexity optimization
    // Time complexity: O(n)
    // Space complexity: O(1)
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int n = nums.size();
        int backTwo = nums[0];
        int backOne = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int temp = backOne;
            backOne = max(backOne, backTwo + nums[i]);
            backTwo = backOne;
        }

        return backOne;
    }
};