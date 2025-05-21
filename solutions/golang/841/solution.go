var visited []bool
func canVisitAllRooms(rooms [][]int) bool {
    N := len(rooms)
    visited = make([]bool, N)
    visited[0] = true
    dfs(0, rooms)
    for _, v := range visited {
        if !v {
            return false
        }
    }
    return true
}

func dfs(room int, rooms [][]int) {
    for _, key := range rooms[room] {
        if !visited[key] {
            visited[key] = true
            dfs(key, rooms)
        }
    }
}
