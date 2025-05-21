var graph map[int][]int
var seen map[int]bool
var routes map[int]map[int]bool
func minReorder(n int, connections [][]int) int {
    graph = make(map[int][]int)
    seen = make(map[int]bool)
    routes = make(map[int]map[int]bool)
    for _, conn:= range connections {
        from, to := conn[0], conn[1]
        if routes[from] == nil {
            routes[from]] = make(map[int]bool)
        }
        routes[from][to] = true
        graph[from] = append(graph[from], to)
        graph[to] = append(graph[to], conn[from])
    }

    seen[0] = true
    return dfs(0)
}

func dfs(node int) int {
    ans := 0
    for _, newNode := range graph[node] {
        if (!seen[newNode]) {
            seen[newNode] = true
            if (routes[node][newNode] == true) {
                ans++
            }
            ans += dfs(newNode)
        }
    }
    return ans
}
