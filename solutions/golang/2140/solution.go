func mostPoints(questions [][]int) int64 {
	n := len(questions)
	dp := make([]int64, n+1)

	for i := n - 1; i >= 0; i-- {
		j := i + questions[i][1] + 1
		dp[i] = max(int64(questions[i][0])+dp[min(j, n)], dp[i+1])
	}

	return dp[0]
}

func mostPoints2(questions [][]int) int64 {
	memo := make([]int64, len(questions))
	for i := range memo {
		memo[i] = 0
	}

	return dp(questions, 0, memo)
}

func dp(questions [][]int, i int, memo []int64) int64 {
	if i >= len(questions) {
		return 0
	}

	if memo[i] != 0 {
		return memo[i]
	}

	j := i + questions[i][1] + 1
	memo[i] = max(int64(questions[i][0])+dp(questions, j, memo), dp(questions, i+1, memo))
	return memo[i]
}