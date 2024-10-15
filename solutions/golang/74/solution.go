func searchMatrix(matrix [][]int, target int) bool {
    M := len(matrix)
    N := len(matrix[0])
    left := 0
    right := N * M - 1
    for (left <= right) {
        mid := left + (right - left) / 2
        row := mid / N
        col := mid % N
        num := matrix[row][col]
        if num == target {
            return true
        } else if num > target {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    return false
}
