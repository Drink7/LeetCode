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
    bool isCousins(TreeNode* root, int x, int y) {
        // use BFS (Queue) to check same level
        // check their parents are not the same
        // TC: O(n)
        // SC: O(n)
        queue<TreeNode*> treeQ;
        treeQ.push(root);
        while (!treeQ.empty()) {
            int qSize = treeQ.size();
            bool isXFound = false;
            bool isYFound = false;
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = treeQ.front();
                treeQ.pop();

                // check if same parent
                if (node->left && node->right) {
                    if (node->left->val == x && node->right->val == y ||
                        node->left->val == y && node->right->val == x) {
                        return false;
                    }
                }

                if (node->left) {
                    treeQ.push(node->left);
                    if (node->left->val == x) {
                        isXFound = true;
                    }

                    if (node->left->val == y) {
                        isYFound = true;
                    }
                }

                if (node->right) {
                    treeQ.push(node->right);
                    if (node->right->val == x) {
                        isXFound = true;
                    }

                    if (node->right->val == y) {
                        isYFound = true;
                    }
                }
            }

            if (isXFound && isYFound) {
                return true;
            }
        }
        return false;
    }
};