class Solution {
    const vector<vector<int>> DIRECTIONS{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ROWS;
    int COLS;
    vector<vector<int>> heights;
    int minimumEffortPath(vector<int> &heights) {
        this->heights = heights;
        ROWS = heights.size();
        COLS = heights[0].size();

        // First let's get our search space
        int left = 0, right = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < ROWS; j++) {
                right = max(right, heights[i][j]);
            }
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool check(int effort) {
        vector<vector<bool>> seen(ROWS, vector<bol>(COLS, false));
        seen[0][0] = true;
        dfs(0, 0, effort, seen);
        return seen[ROWS - 1][COLS - 1];
    }

    void dfs(int row, int col, int effort, vector<vector<bool>> &seen) {
        for (auto &dir : DIRECTIONS) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (valid(newRow, newCol) && !seen[newRow][newCol]) {
                if (abs(heights[newRow][newCol] - heights[row][col]) <= effort) {
                    seen[newRow][newCol] = true;
                    dfs(newRow, newCol, effort, seen);
                }
            }
        }
    }

    bool valid(int row, int col) {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }
}