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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // bfs + queue
        // TC: O(n)
        // SC: O(n)
        queue<TreeNode*> q;
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        q.push(root);
        while(!q.empty()) {
            int qSize = q.size();
            vector<int> level;
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            result.push_back(level);
        }
        return result;
    }
};