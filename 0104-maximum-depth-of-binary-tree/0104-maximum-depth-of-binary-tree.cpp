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
        // BFS + queue
        // TC: O(n)
        // SC: O(n)
        queue<TreeNode*> treeQ;
        int depth = 0;

        if (root) {
            treeQ.push(root);
        }

        while(!treeQ.empty()) {
            int qSize = treeQ.size();
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = treeQ.front();
                treeQ.pop();
                if (node->left) {
                    treeQ.push(node->left);
                }

                if (node->right) {
                    treeQ.push(node->right);
                }
            }
            depth++;
        }
        return depth;
    }
};