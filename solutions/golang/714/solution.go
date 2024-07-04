// First dimension: number of days. Same size as prices
// Second dimension: 2 - holding/not holding the stock
var memo [][]int

// Top down approach
// Time complexity: O(n), n = len(prices)
// Space complexity: O(n), n = len(prices)
// Holding/not holding does not affect time/space complexity as it is a constant.
func maxProfit1(prices []int, fee int) int {
	memo = make([][]int, len(prices))
	for i := 0; i < len(prices); i++ {
		memo[i] = make([]int, 2)
		for j := 0; j < 2; j++ {
			memo[i][j] = -1
		}
	}

	return dp(0, 0, prices, fee)
}

func dp(i int, holding int, prices []int, fee int) int {
	// Base case
	if i == len(prices) {
		return 0
	}

	if memo[i][holding] != -1 {
		return memo[i][holding]
	}

	// Option 1: Skip operation on current day
	ans := dp(i+1, holding, prices, fee)
	if holding == 1 {
		// Option 2: Sell stock. Charge fee.
		ans = max(ans, prices[i]+dp(i+1, 0, prices, fee)-fee)
	} else {
		// Option 3: Buy stock
		ans = max(ans, -prices[i]+dp(i+1, 1, prices, fee))
	}

	memo[i][holding] = ans
	return ans
}

// Bottom up approach
// Time complexity: O(n), n = len(prices)
// Space complexity: O(n), n = len(prices)
// Holding/not holding does not affect time/space complexity as it is a constant.
func maxProfit(prices []int, fee int) int {
	n := len(prices)
	dp := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]int, 2)
	}

	// Start at the base cases
	for i := n - 1; i >= 0; i-- {
		for holding := 0; holding < 2; holding++ {
			// Skip current day
			ans := dp[i+1][holding]
			if holding == 1 {
				// Sell stock
				ans = max(ans, prices[i]+dp[i+1][0]-fee)
			} else {
				// Buy stock
				ans = max(ans, -prices[i]+dp[i+1][1])
			}
			dp[i][holding] = ans
		}
	}

	return dp[0][0]
}