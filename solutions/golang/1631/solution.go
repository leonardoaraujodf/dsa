var directions = [][]int{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}
var M int
var N int
func minimumEffortPath(heights [][]int) int {
    left := 0
    right := 0
    M = len(heights)
    N = len(heights[0])
    for row := 0; row < M; row++ {
        for col := 0; col < N; col++ {
            right = max(right, heights[row][col])
        }
    }

    for left <= right {
        mid := left + (right - left) / 2
        if check(mid, heights) {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }

    return left
}

func check(effort int, heights [][]int) bool {
    seen := make([][]bool, M)
    for i := 0; i < M; i++ {
        seen[i] = make([]bool, N)
    }

    seen[0][0] = true
    dfs(0, 0, effort, heights, seen)

    return seen[M-1][N-1]
}

func dfs(row int, col int, effort int, heights [][]int, seen [][]bool) {
    for _, dir := range directions {
        newRow := row + dir[0]
        newCol := col + dir[1]
        if valid(newRow, newCol) && !seen[newRow][newCol] {
            newEffort := heights[newRow][newCol] - heights[row][col]
            if newEffort < 0 {
                newEffort = -newEffort
            }
            if newEffort <= effort {
                seen[newRow][newCol] = true
                dfs(newRow, newCol, effort, heights, seen)
            }
        }
    }
}

func valid(row int, col int) bool {
    return row >= 0 && row < M && col >= 0 && col < N
}
