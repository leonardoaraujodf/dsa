class Solution {
public:
    int k;
    int splitArray(vector<int>& nums, int k) {
        this->k = k;
        int left = *min_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, nums)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool check(int maxSum, vector<int> &nums) {
        int numSubArrays = 1;
        int curr = 0;
        for (int num : nums) {
            curr += num;
            if (curr > maxSum) {
                numSubArrays++;
                curr = num;
                if ((numSubArrays > k) || (curr > maxSum)) {
                    return false;
                }
            }
        }

        return true;
    }
};
