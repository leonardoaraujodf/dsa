var memo []int

// Top down approach
// Time complexity: O(n*k), n = amount and k is the number of coins
// Space complexity: O(n), where n is amount
func coinChange1(coins []int, amount int) int {
	memo = make([]int, amount+1)
	return dp(coins, amount)
}

func dp(coins []int, amount int) int {
	if amount == 0 {
		return 0
	}

	if memo[amount] != 0 {
		return memo[amount]
	}

	ans := math.MaxInt
	for _, coin := range coins {
		if coin <= amount {
			tmp := dp(coins, amount-coin)
			if tmp != -1 {
				ans = min(ans, tmp+1)
			}
		}
	}

	if ans == math.MaxInt {
		ans = -1
	}

	memo[amount] = ans
	return ans
}

// Bottom up approach
// Time complexity: O(n * k), n = amount and k is the number of coins
// Space complexity: O(n), where n is amount
func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)
	for i := 1; i <= amount; i++ {
		ans := math.MaxInt
		for _, coin := range coins {
			if coin <= i {
				tmp := dp[i-coin]
				if tmp != -1 {
					ans = min(ans, dp[i-coin]+1)
				}
			}
		}
		if ans == math.MaxInt {
			ans = -1
		}
		dp[i] = ans
	}
	return dp[amount]
}