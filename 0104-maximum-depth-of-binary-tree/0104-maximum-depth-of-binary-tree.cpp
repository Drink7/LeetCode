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
    int maxDepth(TreeNode* root) {
        // use BFS
        // TC: O(n)
        // SC: O(n)
        if (root == nullptr) {
            return 0;
        }
        int result = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result++;
        }
        return result;
    }
};