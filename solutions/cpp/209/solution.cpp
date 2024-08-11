class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, curr = 0, ans = INT_MAX;
        for (int right = 0; right < nums.size(); right++) {
            curr += nums[right];
            while (curr >= target) {
                ans = min(ans, right - left + 1);
                curr -= nums[left];
                left++;
            }
        }

        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};