class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
    int countComponents(int n, vector<vector<int>>& edges) {
        seen = vector<bool>(n);
        // convert array of edges to list of adjacency
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                seen[i] = true;
                ans++;
                dfs(i);
            }
        }
        return ans;
    }

    void dfs(int node) {
        for (const auto& neighbor : graph[node]) {
            if (!seen[neighbor]) {
                seen[neighbor] = true;
                dfs(neighbor);
            }
        }
    }
};
