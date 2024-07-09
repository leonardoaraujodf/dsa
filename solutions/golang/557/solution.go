func reverseWords(s string) string {
	r := []rune(s)
	left := 0
	for right := 0; right < len(r); right++ {
		if s[right] == ' ' || right == len(r)-1 {
			// Swap characters within the word
			for i, j := left, right-1; i < j; i, j = i+1, j-1 {
				r[i], r[j] = r[j], r[i]
			}
			left = right + 1
		}
	}
	return string(r)
}