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
