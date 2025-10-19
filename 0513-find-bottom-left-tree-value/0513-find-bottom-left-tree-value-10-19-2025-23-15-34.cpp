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
    int findBottomLeftValue(TreeNode* root) {
        // level order but find leftmost
        // insert right subtree, then insert left subtree
        // TC: O(n)
        // SC: O(n)
        queue<TreeNode*> q;
        q.push(root);
        while (q.size() > 0) {
            int qSize = q.size();
            TreeNode* node = q.front();
            q.pop();

            if (node->right) {
                q.push(node->right);
            }

            if (node->left) {
                q.push(node->left);
            }

            if (q.size() == 0) {
                // bottum level, left mode is node
                return node->val;
            }
        }
        return -1; // impossible
    }
};