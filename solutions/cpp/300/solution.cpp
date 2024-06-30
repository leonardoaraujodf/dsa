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
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }

    // 3rd approach - Intelligently Build a Subsequence
    // Time complexity: O(n^2)
    // Space complexity: O(n)
    int lengthOfLIS3(vector<int> &nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            } else {
                int j = 0;
                while (nums[i] > sub[j]) {
                    j++;
                }
                sub[j] = nums[i];
            }
        }

        return sub.size();
    }

    // 4th approach - Improve With Binary Search
    // Time complexity: N log(N)
    // Space complexity: O(N)
    int lengthOfLIS3(vector<int> &nums) {
        vector<int> sub;
        sub.push_back(nums[i]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            } else {
                int j = binarySearch(sub, nums[i]);
                sub[j] = nums[i];
            }
        }

        return sub.size();
    }

    int binarySearch(vector<int> &sub, int target) {
        int left = 0;
        int right = sub.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int num = sub[mid];
            if (num == target) {
                return mid;
            }

            if (num < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            return left;
        }
    }
};