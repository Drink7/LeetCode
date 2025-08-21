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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // preorder with a vector as params
        // TC: O(n)
        // SC: O(n)
        vector<vector<int>> result;
        vector<int> cur;
        pathHelper(root, targetSum, cur, result);
        return result;
    }

    void pathHelper(TreeNode* root, int targetSum, vector<int> cur, vector<vector<int>>& result) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) {
                cur.push_back(root->val);
                result.push_back(cur);
            }
            return;
        }

        cur.push_back(root->val);
        pathHelper(root->left, targetSum - root->val, cur, result);
        pathHelper(root->right, targetSum - root->val, cur, result);
    }
};