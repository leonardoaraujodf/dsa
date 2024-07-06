func isSubsequence(s string, t string) bool {
	if len(s) == 0 {
		return true
	}

	if len(t) == 0 || len(s) > len(t) {
		return false
	}

	left := 0
	for right := 0; right < len(t); right++ {
		if s[left] == t[right] {
			left++
			if left == len(s) {
				return true
			}
		}
	}

	return false
}