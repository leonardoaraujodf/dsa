// Time complexity: O(n^2)
// Space complexity: O(n)
func lengthOfLIS(nums []int) int {
    memo := make([]int, len(nums))
    for i := 0; i < len(nums); i++ {
        memo[i] = -1
    }
    
    ans := 0
    for i := 0; i < len(nums); i++ {
        ans = max(ans, dp(i, nums, memo));
    }
    
    return ans
}

func dp(i int, nums []int, memo []int) int {
    if (memo[i] != -1) {
        return memo[i]
    }
    
    ans := 1 // base case
    for j := 0; j < i; j++ {
        if (nums[i] > nums[j]) {
            ans = max(ans, dp(j, nums, memo) + 1)
        }
    }
    
    memo[i] = ans
    return memo[i]
}