// Top down approach
// Time complexity: O(m + n)
// Space complexity: O(m + n)
var memo [][]int

func uniquePaths1(m int, n int) int {
	memo = make([][]int, m)
	for i := 0; i < m; i++ {
		memo[i] = make([]int, n)
		for j := 0; j < n; j++ {
			memo[i][j] = -1
		}
	}

	return dp(m-1, n-1)
}

func dp(row int, col int) int {
	if row == 0 && col == 0 {
		return 1
	}

	if memo[row][col] != -1 {
		return memo[row][col]
	}

	ans := 0
	if row > 0 {
		ans += dp(row-1, col)
	}

	if col > 0 {
		ans += dp(row, col-1)
	}

	memo[row][col] = ans
	return ans
}

// Bottom up approach
// Time complexity: O(m + n)
// Space complexity: O(m + n)
func uniquePaths2(m int, n int) int {
	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
	}
	// Base case
	dp[0][0] = 1
	for row := 0; row < m; row++ {
		for col := 0; col < n; col++ {
			if row > 0 {
				dp[row][col] += dp[row-1][col]
			}

			if col > 0 {
				dp[row][col] += dp[row][col-1]
			}
		}
	}

	return dp[m-1][n-1]
}

// Bottom up improved
// Time complexity: O(m + n)
// Space complexity: O(n)
func uniquePaths(m int, n int) int {
	dp := make([]int, n)
	// Base case
	dp[0] = 1
	for row := 0; row < m; row++ {
		nextRow := make([]int, n)
		for col := 0; col < n; col++ {
			nextRow[col] += dp[col]
			if col > 0 {
				nextRow[col] += nextRow[col-1]
			}
		}
		copy(dp, nextRow)
	}

	return dp[n-1]
}