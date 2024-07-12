func compress(chars []byte) int {
	ans := 0
	for i := 0; i < len(chars); {
		curr := chars[i]
		count := 0
		for i < len(chars) && curr == chars[i] {
			i++
			count++
		}
		chars[ans] = curr
		ans++
		if count > 1 {
			t := strconv.Itoa(count)
			for j := 0; j < len(t); j++ {
				chars[ans] = t[j]
				ans++
			}
		}
	}
	return ans
}