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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // preorder
        // TC: O(m * n)
        // SC: O(m * n)
        subTreeHelper(root, subRoot);
        return isSubTree;
    }

    void subTreeHelper(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return;
        }
        
        if (root && subRoot) {
            if (root->val == subRoot->val) {
                isSubTree = isSubTree || isSameTree(root, subRoot);
            }
        }

        subTreeHelper(root->left, subRoot);
        subTreeHelper(root->right, subRoot);
    }

    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }

        if (root && subRoot) {
            if (root->val == subRoot->val) {
                return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
private:
    bool isSubTree = false;
};