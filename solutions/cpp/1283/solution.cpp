class Solution {
public:
    int threshold;
    int smallestDivisor(vector<int>& nums, int threshold) {
        this->threshold = threshold;
        int left = 1;
        int right = 0;
        for (const auto &num : nums) {
            right = max(right, num);
        }

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, nums)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool check(double divisor, vector<int> &nums) {
        long sum = 0;
        for (double num : nums) {
            sum += ceil(num / divisor);
        }

        return sum <= threshold;
    }
};
