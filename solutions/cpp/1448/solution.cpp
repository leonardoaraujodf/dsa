/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes2(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

    int dfs(TreeNode* root, int maxVal) {
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        int left = dfs(root->left, max(root->val, maxVal));
        int right = dfs(root->right, max(root->val, maxVal));
        sum = left + right;
        if (root->val >= maxVal) {
            sum++;
        }

        return sum;
    }

    int goodNodes(TreeNode* root) {
        int sum = 0;
        stack<pair<TreeNode*, int>> stack;
        stack.push(pair(root, root->val));
        while (!stack.empty()) {
            auto [node, maxVal] = stack.top();
            stack.pop();

            if (node->val >= maxVal) {
                sum++;
            }

            if (node->left != nullptr) {
                stack.push(pair(node->left, max(node->val, maxVal)));
            }
            if (node->right != nullptr) {
                stack.push(pair(node->right, max(node->val, maxVal)));
            }
        }
        return sum;
    }

};
