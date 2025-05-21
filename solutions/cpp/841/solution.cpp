class Solution {
public:
    vector<bool> visited;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        visited = vector<bool>(N);
        visited[0] = true;
        dfs(0, rooms);
        return std::all_of(visited.begin(), visited.end(), [](bool v) { return v; });
    }

    void dfs(int room, vector<vector<int>>& rooms) {
        for (const auto& key : rooms[room]) {
            if (!visited[key]) {
                visited[key] = true;
                dfs(key, rooms);
            }
        }
    }
};
