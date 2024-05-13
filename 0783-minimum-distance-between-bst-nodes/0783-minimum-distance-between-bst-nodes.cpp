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
    int minDiffInBST(TreeNode* root) {
        // binary search tree -> inorder traversal
        // TC: O(n)
        // SC: O(n)
        diffHelper(root);
        return result;
    }

    int diffHelper(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        int leftValue = diffHelper(root->left);
        if (leftValue != -1) {
            result = min(result, abs(root->val - leftValue));
        }
        int rightValue = diffHelper(root->right);
        if (rightValue != -1) {
            result = min(result, abs(root->val - rightValue));
        }
        return rightValue;
    }
private:
    int result = INT_MAX;
};