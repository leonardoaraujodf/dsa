func sortedSquares(nums []int) []int {
	ans := make([]int, len(nums))
	left := 0
	right, pos := len(nums)-1, len(nums)-1
	for left <= right {
		numLeft := int(math.Pow(float64(nums[left]), 2))
		numRight := int(math.Pow(float64(nums[right]), 2))
		if numLeft > numRight {
			ans[pos] = numLeft
			left++
		} else {
			ans[pos] = numRight
			right--
		}
		pos--
	}
	return ans
}