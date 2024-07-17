class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
    int N;
    int findCircleNum(vector<vector<int>>& isConnected) {
        N = isConnected.size();
        seen = vector(N, false);
        // Create unidirect graph
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (isConnected[i][j]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (seen[i] == true) {
                continue;
            }
            seen[i] = true;
            dfs(i);
            ans++;
        }
        return ans;
    }

    void dfs(int node) {
        for (int neighbor : graph[node]) {
            if (seen[neighbor] == true) {
                continue;
            }
            seen[neighbor] = true;
            dfs(neighbor);
        }
    }
};