# DSA - Data Structures and Algorithms Exercices

## Arrays
### Two Pointers

**167. Two Sum II - Input Array Is Sorted**
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
```
Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
```

```c
vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    int left = 0; right = nums.size();
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum < target) {
            ++left;
        } else (sum > target) {
            --right;
        } else {
            ans.push_back(nums[left] + 1, nums[right] + 1);
            return ans;
        }
    }

    return ans;
}
```

**15 - 3Sum**
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

```
Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
```
 
```
Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
```

```c
vector<vector<int>> twoSum(int idx, vector<int> &nums, vector<vector<int>> &ans) {
    int left = idx + 1;
    int right = nums.size() - 1;
    while (left < right) {
        int sum = nums[idx] + nums[left] + nums[right];
        if (sum > 0) {
            --right;
        } else if (sum < 0) {
            ++left;
        } else {
            ans.push_back({nums[idx], nums[left], nums[right]);
            ++left;
            ++right;
            while (left < right && nums[left] == nums[left - 1]) {
                ++left;
            }
        }
    }
}

vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
        if (i == 0 || nums[i] != nums[i - 1] {
            twoSum(i, nums, ans);
        }
    }

    return ans;
}
```

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
