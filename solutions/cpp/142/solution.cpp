/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    ListNode *detectCycle1(ListNode *head) {
        unordered_set<ListNode*> seen;
        while (head != nullptr) {
            if (seen.find(head) == seen.end()) {
                seen.insert(head);
            } else {
                return head;
            }
            head = head->next;
        }

        return nullptr;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Found a cycle
                break;
            }
        }

        if (fast != nullptr && fast->next != nullptr) {
            // Restart fast
            fast = head;
            // Now move fast at the same speed as slow.
            // They will meet at the entrance node.
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }

        return nullptr;
    }
};