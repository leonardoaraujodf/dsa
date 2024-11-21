var maxNumSubArrays int

func splitArray(nums []int, k int) int {
    maxNumSubArrays = k
    left := math.MaxInt
    right := 0
    for _, num := range nums {
        if (left > num) {
            left = num
        }
        right += num
    }
    
    for left <= right {
        mid := left + (right - left) / 2
        if check(mid, nums) {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    
    return left
}

func check(maxSum int, nums []int) bool {
    numSubArrays := 1
    curr := 0
    for _, num := range nums {
        curr += num
        if curr > maxSum {
            curr = num
            numSubArrays++
            if (numSubArrays > maxNumSubArrays) || (curr > maxSum) {
                return false
            }
        }
    }
    
    return true
}
