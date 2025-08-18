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
        // find the subRoot root node in root
        // not found, false
        // found, check
        // TC: O(m * n)
        // SC: O(m * n)
        if (root == nullptr && subRoot == nullptr) {
            // impossible
            return true;
        }
        subTreeHelper(root, subRoot);
        return isSub;
    }

    void subTreeHelper(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return;
        }
        if (root->val == subRoot->val) {
            isSub = isSub || sameTreeHelper(root, subRoot);
        }
        subTreeHelper(root->left, subRoot);
        subTreeHelper(root->right, subRoot);
    }

    bool sameTreeHelper(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        if (root->val == subRoot->val) {
            return sameTreeHelper(root->left, subRoot->left) &&
                sameTreeHelper(root->right, subRoot->right);
        } else {
            return false;
        }
    }
private:
    bool isSub = false;
};