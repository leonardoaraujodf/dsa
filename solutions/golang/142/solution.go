/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// Time complexity: O(n)
// Space complexity: O(1)
func detectCycle(head *ListNode) *ListNode {
	slow := head
	fast := head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if slow == fast {
			break
		}
	}

	if fast != nil && fast.Next != nil {
		fast = head
		for fast != slow {
			slow = slow.Next
			fast = fast.Next
		}
		return slow
	}

	return nil
}