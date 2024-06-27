func twoSum(numbers []int, target int) []int {
	left := 0
	right := len(numbers) - 1
	ans := make([]int, 2)
	for left < right {
		curr := numbers[left] + numbers[right]
		if curr == target {
			ans[0] = left + 1
			ans[1] = right + 1
			return ans
		} else if curr < target {
			left++
		} else {
			right--
		}
	}
	return ans
}