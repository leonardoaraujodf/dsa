func successfulPairs(spells []int, potions []int, success int64) []int {
    slices.Sort(potions)
    m := len(potions)
    ans := make([]int, 0)
    for _, spell := range spells {
        i := binarySearch(potions, float64(success)/float64(spell))
        ans = append(ans, m - i)
    }

    return ans
}

func binarySearch(arr []int, target float64) int {
    left := 0
    right := len(arr) - 1
    for (left <= right) {
        mid := left + (right - left) / 2
        if float64(arr[mid]) < target {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }

    return left
}
