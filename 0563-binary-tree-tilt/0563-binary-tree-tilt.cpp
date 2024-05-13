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
    int findTilt(TreeNode* root) {
        // TC: O(n)
        // SC: O(n)
        // return the sum of left subtree and right subtree
        // post-order
        tiltHelper(root);
        return result;
    }

    int tiltHelper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftSubsum = tiltHelper(root->left);
        int rightSubsum = tiltHelper(root->right);
        result += abs(leftSubsum - rightSubsum);
        return leftSubsum + rightSubsum + root->val;
    }
private:
    int result = 0;
};