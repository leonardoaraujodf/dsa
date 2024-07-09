func longestOnes(nums []int, k int) int {
	// The maximum number of ones translates to the longest array
	// with at most k zeros.
	left := 0
	curr := 0
	ans := 0
	for right := 0; right < len(nums); right++ {
		if nums[right] == 0 {
			curr++
			for curr > k {
				if nums[left] == 0 {
					curr--
				}
				left++
			}
		}
		ans = max(ans, right-left+1)
	}
	return ans
}