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
    bool isValidBST(TreeNode* root) {
        // keep tracking prev node
        // compare the prev node with root node
        // TC: O(n)
        // SC: O(n)
        //dfs(root);
        //return isValid;
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode* root, long left, long right) {
        if (root == nullptr) {
            return true;
        }

        int val = root->val;
        
        if (val > left && val < right) {

            // left subtree & right subtree
            return helper(root->left, left, val) && helper(root->right, val, right);
        } else {
            return false;
        }
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        dfs(root->left);

        if (prev != nullptr && prev->val >= root->val) {
            isValid = false;
            return;
        }

        prev = root;
        dfs(root->right);
    }
private:
    TreeNode* prev = nullptr;
    bool isValid = true;
};