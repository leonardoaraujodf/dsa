/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head;
        ListNode *curr = head->next;
        int location = 1;
        vector<int> ans{-1, -1};
        int firstPoint = -1;
        int lastPoint = -1;
        while(curr->next != nullptr) {
            bool found = false;
            if (curr->val < prev->val && curr->val < curr->next->val) {
                // Local minima
                found = true;
            } else if (curr->val > prev->val && curr->val > curr->next->val) {
                // Local maxima
                found = true;
            }
            if (found) {
                if (firstPoint == -1) {
                    firstPoint = location;
                } else {
                    if (lastPoint == -1) {
                        ans[0] = location - firstPoint;
                    } else {
                        ans[0] = min(ans[0], location - lastPoint);
                    }
                    lastPoint = location;
                }
            }
            prev = curr;
            curr = curr->next;
            location++;
        }
        if (firstPoint != -1 && lastPoint != -1) {
            ans[1] = lastPoint - firstPoint;
        } else {
            ans[1] = ans[0];
        }
        return ans;
    }
};