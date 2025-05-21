class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> routes;
    unordered_map<int, bool> seen;
    unordered_map<int, vector<int>> graph;
    int minReorder(int n, vector<vector<int>>& connections) {
        for (const auto& con : connections) {
            routes[con[0]][con[1]] = true;
            graph[con[0]].push_back(con[1]);
            graph[con[1]].push_back(con[0]);
        }

        seen[0] = true;
        return dfs(0);
    }

    int dfs(int node) {
        int ans = 0;
        for (const auto &newNode : graph[node]) {
            if (seen.find(newNode) == seen.end()) {
                seen[newNode] = true;
                if (routes.find(node) != routes.end() && routes[node].find(newNode) != routes[node].end()) {
                    ans++;
                }
                ans += dfs(newNode);
            }
        }
        return ans;
    }
};
