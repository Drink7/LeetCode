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
    int countNodes(TreeNode* root) {
        // check left part and check right part
        // TC: O(logn * logn)
        // SC: O(logn)
        int right = rightDepth(root);
        int left = leftDepth(root);
        if (right == left) {
            // complete tree
            return pow(2, left) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }

    int rightDepth(TreeNode* root) {
        int depth = 0;
        while (root) {
            root = root->right;
            depth++;
        }
        return depth;
    }

    int leftDepth(TreeNode* root) {
        int depth = 0;
        while (root) {
            root = root->left;
            depth++;
        }
        return depth;
    }
};