var directions = [][]int{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}
var seen [][]bool
var M int
var N int

func numIslands(grid [][]byte) int {
	M = len(grid)
	N = len(grid[0])
	seen = make([][]bool, M)
	for i := 0; i < M; i++ {
		seen[i] = make([]bool, N)
	}

	ans := 0
	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if grid[i][j] == '1' && seen[i][j] == false {
				seen[i][j] = true
				ans++
				dfs(i, j, grid)
			}
		}
	}

	return ans
}

func dfs(row int, col int, grid [][]byte) {
	for _, dir := range directions {
		newRow := row + dir[0]
		newCol := col + dir[1]
		if valid(newRow, newCol, grid) && seen[newRow][newCol] == false {
			seen[newRow][newCol] = true
			dfs(newRow, newCol, grid)
		}
	}
}

func valid(row int, col int, grid [][]byte) bool {
	return row >= 0 && row < M && col >= 0 && col < N && grid[row][col] == '1'
}