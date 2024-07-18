/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var parents map[*TreeNode]*TreeNode
var seen map[*TreeNode]bool

func distanceK(root *TreeNode, target *TreeNode, k int) []int {
	parents = make(map[*TreeNode]*TreeNode)
	seen = make(map[*TreeNode]bool)
	dfs(root, nil)

	queue := []*TreeNode{target}
	seen[target] = true
	steps := 0
	for len(queue) > 0 && steps < k {
		currLen := len(queue)
		for i := 0; i < currLen; i++ {
			node := queue[0]
			queue = queue[1:]
			neighbors := []*TreeNode{parents[node], node.Left, node.Right}
			for _, neighbor := range neighbors {
				_, ok := seen[neighbor]
				if neighbor != nil && !ok {
					seen[neighbor] = true
					queue = append(queue, neighbor)
				}
			}
		}
		steps++
	}

	var ans = []int{}
	for len(queue) > 0 {
		ans = append(ans, queue[0].Val)
		queue = queue[1:]
	}
	return ans
}

func dfs(root *TreeNode, parent *TreeNode) {
	if root == nil {
		return
	}

	parents[root] = parent
	dfs(root.Left, root)
	dfs(root.Right, root)
}