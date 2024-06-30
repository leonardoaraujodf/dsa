// Time complexity: O(n^2)
// Space complexity: O(n)
func lengthOfLIS(nums []int) int {
	memo := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		memo[i] = -1
	}
	ans := 0
	for i := 0; i < len(nums); i++ {
		ans = max(ans, dp(i, nums, memo))
	}
	return ans
}

func dp(i int, nums []int, memo []int) int {
	if memo[i] != -1 {
		return memo[i]
	}
	ans := 1 // base case
	for j := 0; j < i; j++ {
		if nums[i] > nums[j] {
			ans = max(ans, dp(j, nums, memo)+1)
		}
	}
	memo[i] = ans
	return memo[i]
}

// Bottom up approach
// Time complexity: O(n^2)
// Space complexity: O(n)
func lengthOfLIS2(nums []int) {
	dp := make([]int, len(nums))
	for i := 0; i < len(dp); i++ {
		dp[i] = -1
	}

	ans := 0
	for i := 0; i < len(nums); i++ {
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				dp[i] = max(dp[i], dp[j]+1)
				ans = max(ans, dp[i])
			}
		}
	}
	return ans
}

// 3rd approach - Intelligently build a subsequence
// Time complexity: O(n^2)
// Space complexity: O(n)
func lengthOfLIS3(nums []int) int {
	sub := []int{nums[0]}
	for i := 0; i < len(nums); i++ {
		num := sub[len(sub)-1]
		if nums[i] > num {
			sub = append(sub, nums[i])
		} else {
			j := 0
			for nums[i] > sub[j] {
				j++
			}
			sub[j] = nums[i]
		}
	}

	return len(sub)
}

// 4th approach - Improve with Binary Search
// Time complexity: N log(N)
// Space complexity: O(N)
func lengthOfLIS3(nums []int) int {
	sub := []int{nums[0]}

	for i := 0; i < len(nums); i++ {
		num := sub[len(sub)-1]
		if nums[i] > num {
			sub = append(sub, nums[i])
		} else {
			j := binarySearch(sub, nums[i])
			sub[j] = nums[i]
		}
	}

	return len(sub)
}

func binarySearch(sub []int, target int) int {
	left := 0
	right := len(sub) - 1
	for left <= right {
		mid := left + (right-left)/2
		num := sub[mid]
		if num == target {
			return mid
		}

		if num < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return left
}