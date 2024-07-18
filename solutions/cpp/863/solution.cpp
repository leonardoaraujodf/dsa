/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parents;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_set<TreeNode *> seen;
        // First run a DFS to build the parents map
        dfs(root, nullptr);

        // Now run a BFS starting at the target node
        int steps = 0;
        queue<TreeNode *> queue;
        queue.push(target);
        seen.insert(target);

        vector<int> ans;
        while (queue.size() && steps < k) {
            int currLenght = queue.size();
            for (int i = 0; i < currLenght; i++) {
                TreeNode *node = queue.front();
                queue.pop();
                for (TreeNode *neighbor : {parents[node], node->left, node->right}) {
                    if (neighbor != nullptr && seen.find(neighbor) == seen.end()) {
                        queue.push(neighbor);
                        seen.insert(neighbor);
                    }
                }
            }
            steps++;
        }

        while (queue.size()) {
            TreeNode* node = queue.front();
            queue.pop();
            ans.push_back(node->val);
        }

        return ans;
    }

    void dfs(TreeNode *root, TreeNode *parent) {
        if (!root) {
            return;
        }
        parents[root] = parent;
        dfs(root->left, root);
        dfs(root->right, root);
    }
};