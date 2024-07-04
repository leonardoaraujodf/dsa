// First dimension - Number of days, which has size of len(prices)
// Second dimension - Holding/not holding, 2 values
var memo [][]int

// Top down approach
// Time complexity: O(n), n = len(prices)
// Space complexity: O(n), n = len(prices)
func maxProfit1(prices []int) int {
	memo = make([][]int, len(prices))
	for i := 0; i < len(prices); i++ {
		memo[i] = make([]int, 2)
		for j := 0; j < 2; j++ {
			memo[i][j] = -1
		}
	}

	return dp(0, 0, prices)
}

func dp(i int, holding int, prices []int) int {
	if i >= len(prices) {
		return 0
	}

	if memo[i][holding] != -1 {
		return memo[i][holding]
	}

	// Option 1: Skip current day
	ans := dp(i+1, holding, prices)
	if holding == 1 {
		// Option 2: Sell stock. Skip 2 days (cooldown)
		ans = max(ans, prices[i]+dp(i+2, 0, prices))
	} else {
		// Option 3: Buy stock
		ans = max(ans, -prices[i]+dp(i+1, 1, prices))
	}
	memo[i][holding] = ans
	return ans
}

// Bottom up approach
// Time complexity: O(n), n = len(prices)
// Space complexity: O(n), n = len(prices)
func maxProfit(prices []int) int {
	n := len(prices)
	dp := make([][]int, n+2)
	for i := 0; i < n+2; i++ {
		dp[i] = make([]int, 2)
	}
	for i := n - 1; i >= 0; i-- {
		for holding := 0; holding < 2; holding++ {
			// Skip
			ans := dp[i+1][holding]
			if holding == 1 {
				// Sell
				ans = max(ans, prices[i]+dp[i+2][0])
			} else {
				// Buy
				ans = max(ans, -prices[i]+dp[i+1][1])
			}
			dp[i][holding] = ans
		}
	}

	return dp[0][0]
}