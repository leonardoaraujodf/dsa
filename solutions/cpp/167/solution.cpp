class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> ans;
        while (left < right) {
            int curr = numbers[left] + numbers[right];
            if (curr < target) {
                left++;
            } else if (curr > target) {
                right--;
            } else {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                return ans;
            }
        }
        return ans;
    }
}