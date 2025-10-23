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
    vector<int> inorderTraversal(TreeNode* root) {
        // // bst
        // // left, root, right
        // // TC: O(n)
        // // SC: O(n)
        // vector<int> result;
        // helper(root, result);
        // return result;
        // iterative
        // TC: O(n)
        // SC: O(1)
        vector<int> result;
        stack<TreeNode*> stk; // only push non nullptr node
        TreeNode* cur = root;
        while (cur || stk.size() > 0) {
            // keep traverse left node

            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            stk.pop();

            result.push_back(cur->val);
            
            cur = cur->right;
        }
        return result;
    }

    void helper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        helper(root->left, result);
        result.push_back(root->val);
        helper(root->right, result);
    }
};