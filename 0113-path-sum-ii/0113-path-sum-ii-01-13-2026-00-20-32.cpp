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
        // preorder
        // only check if left == right == nullptr
        // TC: O(n)
        // SC: O(n)
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, 0, result, path);
        return result;
    }

    void dfs(TreeNode* root, int targetSum, int pathSum, vector<vector<int>>& result, vector<int>& path) {
        if (root == nullptr) {
            return;
        }

        pathSum += root->val;
        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr && pathSum == targetSum) {
            result.push_back(path);
        } else {
            dfs(root->left, targetSum, pathSum, result, path);
            dfs(root->right, targetSum, pathSum, result, path);
        }

        // backtracking
        path.pop_back();
    }
};