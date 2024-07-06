func findMaxAverage(nums []int, k int) float64 {
	sum := 0.0
	for i := 0; i < k; i++ {
		sum += float64(nums[i])
	}

	average := sum / float64(k)
	for i := k; i < len(nums); i++ {
		sum -= float64(nums[i-k])
		sum += float64(nums[i])
		average = max(average, sum/float64(k))
	}
	return average
}