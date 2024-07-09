class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // The maximum number of ones translates to the longest array
        // with at most k zeros.
        int left = 0;
        int zeroes = 0;
        int ans = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zeroes++;
                while (zeroes > k) {
                    if (nums[left] == 0) {
                        zeroes--;
                    }
                    left++;
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};