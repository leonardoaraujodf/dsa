class Solution {
    unordered_map<int, vector<int>> graph;
    vector<bool> visited;
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited = vector<bool>(n);
        // Do a pre-processing operation. Transform the array of edges into an adjacency list.
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        visited[source] = true;
        dfs(source, destination);
        return visited[destination];
    }

    void dfs(int v, int destination) {
        for (const auto& neighbor : graph[v]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                if (neighbor == destination) {
                    return;
                }
                dfs(neighbor, destination);
            }
        }
    }
};
