// QueueItem represents an item in the queue
type QueueItem []int

// Queue represents a simple queue
type Queue struct {
	items []QueueItem
}

// Enqueue adds an item to the end of the queue
func (q *Queue) Enqueue(item QueueItem) {
	q.items = append(q.items, item)
}

// Dequeue removes and returns the front item from the queue
func (q *Queue) Dequeue() (QueueItem, error) {
	if len(q.items) == 0 {
		return nil, fmt.Errorf("queue is empty")
	}
	item := q.items[0]
	q.items = q.items[1:]
	return item, nil
}

// IsEmpty returns true if the queue is empty
func (q *Queue) IsEmpty() bool {
	return len(q.items) == 0
}

// Size returns the number of items in the queue
func (q *Queue) Size() int {
	return len(q.items)
}

var directions = [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0},
	{1, 1}, {-1, 1}, {1, -1}, {-1, -1}}
var N int
var seen [][]bool

func shortestPathBinaryMatrix(grid [][]int) int {
	N = len(grid)
	seen = make([][]bool, N)
	for i := 0; i < N; i++ {
		seen[i] = make([]bool, N)
	}

	var myQueue = Queue{}
	if grid[0][0] == 0 {
		myQueue.Enqueue(QueueItem{0, 0, 1})
		seen[0][0] = true
	}

	for !myQueue.IsEmpty() {
		curr, _ := myQueue.Dequeue()
		row := curr[0]
		col := curr[1]
		steps := curr[2]
		if row == N-1 && col == N-1 {
			return steps
		}

		for _, dir := range directions {
			newRow := row + dir[0]
			newCol := col + dir[1]
			if valid(newRow, newCol, grid) && !seen[newRow][newCol] {
				seen[newRow][newCol] = true
				myQueue.Enqueue(QueueItem{newRow, newCol, steps + 1})
			}
		}
	}

	return -1
}

func valid(row int, col int, grid [][]int) bool {
	return row >= 0 && row < N && col >= 0 && col < N && grid[row][col] == 0
}