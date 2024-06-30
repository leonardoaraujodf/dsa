func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for i, v := range nums {
		map[v] = i
	}

	var ans = []int{0, 0}
	for i, v := range(nums) {
		diff := target - v
		location, ok := m[diff]
		if ok && location != i {
			ans[0] = i
			ans[1] = location
			break
		}
	}

	return ans
}