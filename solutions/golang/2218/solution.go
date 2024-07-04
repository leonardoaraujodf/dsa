// First dimension: number of coins up to far
// Second dimension: remaining
var memo [][]int

// Top-down approach
// Average number of coins per pile piles[i].length = x
// n - number of piles
// k - number of remaining coins we can take
// Time complexity: O(x * n * k)
// Space complexity: O(n * k)
func maxValueOfCoins(piles [][]int, k int) int {
	memo = make([][]int, len(piles))
	for i := 0; i < len(piles); i++ {
		memo[i] = make([]int, k+1)
		for j := 0; j <= k; j++ {
			memo[i][j] = -1
		}
	}

	return dp(0, k, piles)
}

func dp(i int, remain int, piles [][]int) int {
	if i == len(piles) || remain == 0 {
		return 0
	}

	if memo[i][remain] != -1 {
		return memo[i][remain]
	}

	// Skip pile
	ans := dp(i+1, remain, piles)
	curr := 0
	for j := 0; j < min(remain, len(piles[i])); j++ {
		curr += piles[i][j]
		ans = max(ans, curr+dp(i+1, remain-j-1, piles))
	}

	memo[i][remain] = ans
	return ans
}