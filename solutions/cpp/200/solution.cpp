class Solution {
public:
    vector<vector<int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int M;
    int N;
    vector<vector<bool>> seen;
    int numIslands(vector<vector<char>>& grid) {
        this->M = grid.size();
        this->N = grid[0].size();
        seen = vector(M, vector(N, false));

        int ans = 0;
        for (int row = 0; row < M; row++) {
            for (int col = 0; col < N; col++) {
                if (seen[row][col] == true || grid[row][col] == '0') {
                    continue;
                }

                seen[row][col] = true;
                dfs(row, col, grid);
                ans++;
            }
        }
        return ans;
    }

    void dfs(int row, int col, vector<vector<char>>& grid) {
        for (vector<int> &dir : DIRECTIONS) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (valid(newRow, newCol, grid) && !seen[newRow][newCol]) {
                seen[newRow][newCol] = true;
                dfs(newRow, newCol, grid);
            }
        }
    }

    bool valid(int row, int col, vector<vector<char>>& grid) {
        return row >= 0 && row < M && col >= 0 && col < N && grid[row][col] == '1';
    }
};