class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0},
                                      {0, -1}, {-1, 0},
                                      {1, 1}, {-1, 1},
                                      {1, -1}, {-1,-1}};
    int N;
    vector<vector<bool>> seen;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        N = grid.size();
        seen = vector(N, vector(N, false));
        // First item: row
        // Second item: col
        // Third item: nums steps to row
        queue<vector<int>> queue;
        if (grid[0][0] == 0) {
            queue.push({0, 0, 1});
            seen[0][0] = true;
        }

        while (queue.size() > 0) {
            vector<int> curr = queue.front();
            queue.pop();
            int row = curr[0], col = curr[1], steps = curr[2];
            if (row == N - 1 && col == N - 1) {
                return steps;
            }

            for (vector<int> &dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                if (valid(newRow, newCol, grid) && !seen[newRow][newCol]) {
                    seen[newRow][newCol] = true;
                    queue.push({newRow, newCol, steps + 1});
                }
            }
        }

        return -1;
    }

    bool valid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && row < N && col >= 0 && col < N && grid[row][col] == 0;
    }
};