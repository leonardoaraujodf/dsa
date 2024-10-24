var thre int
func smallestDivisor(nums []int, threshold int) int {
    thre = threshold
    left := 1
    right := 0
    for _, num := range nums {
        right = max(right, num)
    }

    for left <= right {
        mid := left + (right - left) / 2
        if (check(float64(mid), nums)) {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }

    return left
}

func check(divisor float64, nums []int) bool {
    sum := float64(0)
    for _, num := range nums {
        fnum := float64(num)
        sum += math.Ceil(fnum / divisor)
    }

    return int(sum) <= thre
}
