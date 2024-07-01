// First dimension: prices
// Second dimension: holding/not holding
// Thid dimension: remaining transactions
// Top-down approach
// Time complexity: O(n * k), n relates to prices, k relates to remaining
var memo [][][]int
var myPrices []int

func maxProfit2(k int, prices []int) int {
	memo = make([][][]int, len(prices))
	for i := 0; i < len(prices); i++ {
		memo[i] = make([][]int, 2)
		for j := 0; j < 2; j++ {
			memo[i][j] = make([]int, k+1)
			for x := 0; x < k+1; x++ {
				memo[i][j][x] = -1
			}
		}
	}

	myPrices = make([]int, len(prices))
	copy(myPrices, prices)

	return dp(0, 0, k)
}

func dp(i int, holding int, k int) int {
	if i == len(myPrices) || k == 0 {
		return 0
	}

	if memo[i][holding][k] != -1 {
		return memo[i][holding][k]
	}

	// Skip
	ans := dp(i+1, holding, k)
	if holding == 0 {
		// Buy
		ans = max(ans, -myPrices[i]+dp(i+1, 1, k))
	} else {
		// Sell
		ans = max(ans, myPrices[i]+dp(i+1, 0, k-1))
	}

	memo[i][holding][k] = ans
	return ans
}

// Bottom-up approach
// Time complexity: O(n * k), n relates to prices, k relates to remaining
func maxProfit(k int, prices []int) int {
	n := len(prices) + 1
	dp := make([][][]int, n+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = make([][]int, 2)
		for j := 0; j < 2; j++ {
			dp[i][j] = make([]int, k+1)
		}
	}

	// Start iterating from the base case
	for i := len(prices) - 1; i >= 0; i-- {
		for holding := 0; holding < 2; holding++ {
			for remaining := 1; remaining <= k; remaining++ {
				ans := dp[i+1][holding][remaining]
				if holding == 0 {
					ans = max(ans, -prices[i]+dp[i+1][1][remaining])
				} else {
					ans = max(ans, prices[i]+dp[i+1][0][remaining-1])
				}
				dp[i][holding][remaining] = ans
			}
		}
	}

	return dp[0][0][k]
}