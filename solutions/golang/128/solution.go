func longestConsecutive(nums []int) int {
	count := make(map[int]bool)
	for _, num := range nums {
		count[num] = true
	}

	longest := 0
	for len(count) > 0 {
		var start int
		for num := range count {
			_, ok := count[num-1]
			if !ok {
				start = num
				break
			}
		}
		delete(count, start)
		lenSoFar := 1
		_, ok := count[start+1]
		for ; ok == true; _, ok = count[start+1] {
			delete(count, start+1)
			lenSoFar++
			start++
		}
		longest = max(longest, lenSoFar)
	}

	return longest
}