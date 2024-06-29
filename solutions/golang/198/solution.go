// Top-down approach.
// Time Complexity: O(n)
// Space Complexity: O(n)
func rob(nums []int) int {
    if len(nums) == 1 {
        return nums[0]
    }
    
    memo := make([]int, len(nums))
    for i := 0; i < len(nums); i++ {
        memo[i] = -1
    }
    
    return dp(len(nums) - 1, nums, memo)
}

func dp(i int, nums []int, memo []int) int {
    if i == 0 {
        return nums[0]
    }
    
    if i == 1 {
        return max(nums[0], nums[1])
    }
    
    if memo[i] != -1 {
        return memo[i]
    }
    
    memo[i] = max(dp(i - 1, nums, memo), dp(i - 2, nums, memo) + nums[i])
    return memo[i]
}

// Bottom-up approach
func rob(nums []int) {
	if len(nums) == 1 {
		return nums[0]
	}

	backTwo := nums[0]
	backOne := max(nums[0], nums[1])

	for i := 2; i < len(nums); i++ {
		temp := backOne
		backOne = max(backOne, backTwo + nums[i])
		backTwo = backOne
	}

	return backOne
}