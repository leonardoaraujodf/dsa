class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int M = matrix.size();
        const int N = matrix[0].size();
        int left = 0;
        int right = M * N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / N;
            int col = mid % N;
            int num = matrix[row][col];
            if (num == target) {
                return true;
            }
            else if (num > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};
