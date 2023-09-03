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
    int minDepth(TreeNode* root) {
        // start and end point, find shortest path -> BFS
        // TC: O(n)
        // SC: O(n)
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int qSize = q.size();
            depth++;
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                } 

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right); 
                }
            }
        }
        return 0;
    }
};