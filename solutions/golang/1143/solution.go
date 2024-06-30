// Top down
// Time complexity: O(n * m)
// Space complexity: O(n * m)
func longestCommonSubsequence2(text1 string, text2 string) int {
	memo := make([][]int, len(text1))
	for i := 0; i < len(text1); i++ {
		memo[i] = make([]int, len(text2))
		for j := 0; j < len(text2); j++ {
			memo[i][j] = -1
		}
	}

	return dp(0, 0, memo, text1, text2)
}

// Bottom up - Remember to start at the base cases
// Time complexity: O(n * m)
// Space complexity: O(n * m)
func dp(i int, j int, memo [][]int, text1 string, text2 string) int {
	if i == len(text1) || j == len(text2) {
		return 0
	}

	if memo[i][j] != -1 {
		return memo[i][j]
	}

	ans := 0
	if text1[i] == text2[j] {
		ans = 1 + dp(i+1, j+1, memo, text1, text2)
	} else {
		ans = max(dp(i+1, j, memo, text1, text2), dp(i, j+1, memo, text1, text2))
	}
	memo[i][j] = ans
	return ans
}

func longestCommonSubsequence(text1 string, text2 string) int {
	n := len(text1)
	m := len(text2)
	dp := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]int, m+1)
	}

	for i := n - 1; i >= 0; i-- {
		for j := m - 1; j >= 0; j-- {
			if text1[i] == text2[j] {
				dp[i][j] = 1 + dp[i+1][j+1]
			} else {
				dp[i][j] = max(dp[i+1][j], dp[i][j+1])
			}
		}
	}

	return dp[0][0]
}
