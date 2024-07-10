func reverseOnlyLetters(s string) string {
	r := []rune(s)
	left := 0
	right := len(r) - 1
	for left < right {
		for !(r[left] >= 'A' && r[left] <= 'Z' ||
			r[left] >= 'a' && r[left] <= 'z') {
			left++
			if left >= right {
				break
			}
		}
		for !(r[right] >= 'A' && r[right] <= 'Z' ||
			r[right] >= 'a' && r[right] <= 'z') {
			right--
			if left >= right {
				break
			}
		}
		if left < right {
			r[left], r[right] = r[right], r[left]
			left++
			right--
		}
	}

	return string(r)
}