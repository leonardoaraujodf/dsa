func minSubArrayLen(target int, nums []int) int {
	left := 0
	ans := math.MaxInt
	curr := 0
	for right := 0; right < len(nums); right++ {
		curr += nums[right]
		for curr >= target {
			ans = min(ans, right-left+1)
			curr -= nums[left]
			left++
		}
	}

	if ans == math.MaxInt {
		return 0
	}

	return ans
}