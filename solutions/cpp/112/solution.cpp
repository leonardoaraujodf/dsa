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
    bool hasPathSum2(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val) {
                return true;
            }
        }

        bool left = hasPathSum(root->left, targetSum - root->val);
        bool right = hasPathSum(root->right, targetSum - root->val);
        return left || right;
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        stack<pair<TreeNode*, int>> stack;
        stack.push(pair(root, targetSum));
        while (!stack.empty()) {
            auto [node, curr] = stack.top();
            stack.pop();

            if (node->left == nullptr && node->right == nullptr) {
                if (node->val + curr == targetSum) {
                    return true;
                }
            }

            curr += node->val;
            if (node->left != nullptr) {
                stack.push(pair(node->left, curr));
            }
            if (node->right != nullptr) {
                stack.push(pair(node->right, curr));
            }
        }

        return false;
    }
};
