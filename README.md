# DSA - Data Structures and Algorithms Exercices

## Arrays
### Two Pointers
### Sliding Window
**Example 1**: Given an array of positive integers nums and an integer k, find the length of the longest subarray whose sum is less than or equal to k.

```c
int findLength(vector<int> &nums, int k) {
    int left = 0, curr = 0, ans = 0;
    for (int right = 0; right < nums.size(); right++) {
        curr += nums[right];
        while (curr > k) {
            curr -= nums[left];
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}
```

**Example 2**: You are given a binary string s (a string containing only "0" and "1"). You may choose up to one "0" and flip it to a "1". What is the length of the longest substring achievable that contains only "1"?

For example, given s = "1101100111", the answer is 5. If you perform the flip at index 2, the string becomes 1111100111.

```c
// This is the same as find maximum substring with at most one '0'.
int findLength(string s) {
    int left = 0, curr = 0, ans = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (s[right] == '0') {
            curr++;
        }
    }
}
```

**Example 3**: 713: Subarray Product Less Than K.
Given an array of positive integers `nums` and an integer k, return the number of subarrays where the product of all the elements in the subarray is strictly less than k.

For example, given the input `nums = [10, 5, 2, 6]`, `k = 100`, the answer is `8`. The subarrays with products less than `k` are:

`[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]`

### Prefix Sum
Example 1: Given an integer array `nums`, an array `queries` where `queries[i] = [x, y]` and an integer `limit`, return a boolean array that represents the answer to each query. A query is `true` if the sum of the subarray from `x` to `y` is less than `limit`. or `false` otherwise.

For example, given `nums = [1, 6, 3, 2, 7, 2]`, `queries = [[0, 3], [2, 5], [2, 4]]`, and `limit = 13`, the answer is `[true, false, true]`. For each query, the subarray sums are `[12, 14, 12]`.

```c
vector<bool> answerQueries(vector<int> &nums, vector<vector<int>> &queries, int limit) {
    vector<int> prefix = {nums[0]};
    for (int i = 1; i < nums.size(); i++) {
        prefix.push_back(prefix.back() + nums[i]);
    }

    vector<bool> ans;
    for (vector<int> &query : queries) {
        int x = query[0], y = query[1];
        int curr = prefix[y] - prefix[x] + nums[x];
        ans.push_back(curr < limit);
    }

    return ans;
}
```

Example 2: 2270: Number of Ways to Split Array

Given an integer array `nums`, find the number of ways to split the array into two parts so that the first section has a sum greater than or equal to the sum of the second section. The second section should have at least one number.

Solution 1:
```c
int waysToSplitArray(vector<int> &nums) {
    int n = nums.size();

    vector<long> prefix = {nums[0]};
    for (int i = 1; i < nums.size(); i++) {
        prefix.push_back(prefix.back() + nums[i]);
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        long leftSection = prefix[i];
        long rightSection = prefix.back() - leftSection;
        if (leftSection >= rightSection) {
            ans++;
        }
    }

    return ans;
}
```

Solution 2:
```c
int waysToSplitArray(vector<int> &nums) {
    long sum = 0;
    long leftSection = 0;
    for (const auto &n : nums) {
        sum += n;
    }

    int ans = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        leftSection += nums[i];
        long rightSection = sum - leftSection;
        if (leftSection >= rightSection) {
            ans++;
        }
    }
    return ans;
}
```
