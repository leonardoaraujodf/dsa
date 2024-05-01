# DSA - Data Structures and Algorithms Exercices

## Arrays
### Two Pointers
### Sliding Window
**Example 1**: Given an array of positive integers nums and an integer k, find the length of the longest subarray whose sum is less than or equal to k. This is the problem we have been talking about above. We will now formally solve it.

**Example 2**: You are given a binary string s (a string containing only "0" and "1"). You may choose up to one "0" and flip it to a "1". What is the length of the longest substring achievable that contains only "1"?

For example, given s = "1101100111", the answer is 5. If you perform the flip at index 2, the string becomes 1111100111.

**Example 3**: 713: Subarray Product Less Than K.
Given an array of positive integers `nums` and an integer k, return the number of subarrays where the product of all the elements in the subarray is strictly less than k.

For example, given the input `nums = [10, 5, 2, 6]`, `k = 100`, the answer is `8`. The subarrays with products less than `k` are:

`[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]`
