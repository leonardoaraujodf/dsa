func validPath(n int, edges [][]int, source int, destination int) bool {
    graph := make(map[int][]int)
    seen := make([]bool, n)
    for _, edge := range edges {
        to, from := edge[0], edge[1]
        graph[to] = append(graph[to], from)
        graph[from] = append(graph[from], to)
    }

    seen[source] = true;
    dfs(source, destination, graph, seen);
    return seen[destination]
}

func dfs(vertex int, destination int, graph map[int][]int, seen []bool) {
    for _, neighbor := range graph[vertex] {
        if !seen[neighbor] {
            seen[neighbor] = true
            if neighbor == destination {
                return
            }
            dfs(neighbor, destination, graph, seen)
        }
    }
}
