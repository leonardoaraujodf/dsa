var limit int
func minEatingSpeed(piles []int, h int) int {
    limit = h
    left := 1
    right := 0
    for _, bananas := range piles {
        right = max(right, bananas)
    }

    for left <= right {
        mid := left + (right - left) / 2
        if check(mid, piles) {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }

    return left
}

func check(k int, piles []int) bool {
    hours := 0
    fk := float64(k)
    for _, bananas := range piles {
        fbananas := float64(bananas)
        hours += int(math.Ceil(fbananas / fk))
    }

    return hours <= limit
}
