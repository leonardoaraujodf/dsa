func countComponents(n int, edges [][]int) int {
    seen := make([]bool, n)
    graph := make(map[int][]int)
    for _, edge := range edges {
        to, from := edge[0], edge[1]
        graph[to] = append(graph[to], from)
        graph[from] = append(graph[from], to)
    }
    ans := 0
    for i := 0; i < n; i++ {
        if !seen[i] {
            seen[i] = true
            ans++
            dfs(i, seen, graph)
        }
    }
    return ans
}

func dfs(node int, seen []bool, graph map[int][]int) {
    for _, neighbor := range graph[node] {
        if !seen[neighbor] {
            seen[neighbor] = true
            dfs(neighbor, seen, graph)
        }
    }
}
