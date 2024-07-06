class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans(nums.size());
        int pos = nums.size() - 1;
        while (left <= right) {
            int leftSquared = pow(nums[left], 2);
            int rightSquared = pow(nums[right], 2);
            if (leftSquared > rightSquared) {
                ans[pos] = leftSquared;
                left++;
            } else {
                ans[pos] = rightSquared;
                right--;
            }
            pos--;
        }

        return ans;
    }
};