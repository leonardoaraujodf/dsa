var graph map[int][]int
var seen []bool

func findCircleNum(isConnected [][]int) int {
	N := len(isConnected)
	graph = make(map[int][]int)
	seen = make([]bool, N)
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			if isConnected[i][j] == 1 {
				graph[i] = append(graph[i], j)
				graph[j] = append(graph[j], i)
			}
		}
	}

	ans := 0
	for i := 0; i < N; i++ {
		if seen[i] == true {
			continue
		}
		seen[i] = true
		dfs(i)
		ans++
	}
	return ans
}

func dfs(node int) {
	for _, neighbor := range graph[node] {
		if seen[neighbor] == true {
			continue
		}
		seen[neighbor] = true
		dfs(neighbor)
	}
}