class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                if (map.find(target - nums[i]) != i) {
                    ans.push_back(i);
                    ans.push_back(map[target - nums[i]]);
                    break;
                }
            }
        }
        return ans;
    }
}