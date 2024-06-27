vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
{
    sort(nums.begin(), nums.end());
    vector<long> prefixSum;
    prefixSum.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        prefixSum.push_back(prefixSum.back() + nums[i]);
    }

    vector<int> ans;
    for (int i = 0; i < queries.size(); i++) {
        int location;
        bool found = binarySearch(prefixSum, queries[i], location);
        if (found) {
            ans.push_back(location + 1);
        } else {
            ans.push_back(location);
        }
    }

    return ans;
}

bool binarySearch(vector<long> &nums, long target, int &location) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            location = mid;
            return true;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    location = left;
    return false;
}