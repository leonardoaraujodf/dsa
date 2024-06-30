class Solution {
public:
    vector<vector<int> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> nums;
        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                twoSum(nums, ans, i, -nums[i]);
            }
        }
    }

    void twoSum(vector<int> &nums, vector<vector<int>> &ans, int idx, int target) {
        int left = idx + 1, right = nums.size() - 1;
        while (left < right) {
            int curr = nums[left] + nums[right];
            if (curr == target) {
                ans.push_back({nums[left], nums[right], -target});
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
            } else if (curr < target) {
                left++;
            } else {
                right--;
            }
        }
    }
}