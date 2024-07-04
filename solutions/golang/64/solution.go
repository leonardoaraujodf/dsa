const MaxUint = ^uint(0)
const MinUint = 0
const MaxInt = int(MaxUint >> 1)
const MinInt = -MaxInt - 1

var memo [][]int

// Top down approach
// Time complexity: O(m * n)
// Spae complexity: O(m * n)
func minPathSum1(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])
	memo = make([][]int, m)
	for i := 0; i < m; i++ {
		memo[i] = make([]int, n)
		for j := 0; j < n; j++ {
			memo[i][j] = -1
		}
	}

	return dp(m-1, n-1, grid)
}

func dp(row int, col int, grid [][]int) int {
	// Base case
	if row == 0 && col == 0 {
		return grid[row][col]
	}

	if memo[row][col] != -1 {
		return memo[row][col]
	}

	ans := MaxInt
	if row > 0 {
		ans = min(ans, grid[row][col]+dp(row-1, col, grid))
	}
	if col > 0 {
		ans = min(ans, grid[row][col]+dp(row, col-1, grid))
	}

	memo[row][col] = ans
	return ans
}

// Bottom up approach
// Time complexity: O(m * n)
// Space complexity: O(m * n)
func minPathSum2(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])
	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
		for j := 0; j < n; j++ {
			dp[i][j] = MaxInt
		}
	}
	// Base case
	dp[0][0] = grid[0][0]
	for row := 0; row < m; row++ {
		for col := 0; col < n; col++ {
			if row > 0 {
				dp[row][col] = min(dp[row][col], grid[row][col]+dp[row-1][col])
			}
			if col > 0 {
				dp[row][col] = min(dp[row][col], grid[row][col]+dp[row][col-1])
			}
		}
	}

	return dp[m-1][n-1]
}

// Bottom up approach improved
// Time complexity: O(m * n)
// Space complexity: O(n)
func minPathSum(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])
	dp := make([]int, n)
	for i := 0; i < n; i++ {
		dp[i] = MaxInt
	}
	// Base case
	dp[0] = 0
	for row := 0; row < m; row++ {
		nextRow := make([]int, n)
		for col := 0; col < n; col++ {
			nextRow[col] = dp[col]
			if col > 0 {
				nextRow[col] = min(nextRow[col], nextRow[col-1])
			}
			nextRow[col] += grid[row][col]
		}
		copy(dp, nextRow)
	}

	return dp[n-1]
}