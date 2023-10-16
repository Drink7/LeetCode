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
    vector<string> binaryTreePaths(TreeNode* root) {
        // leaf node left and right would be nullptr
        // TC: O(n), n is all nodes
        // SC: O(n)
        // DFS
        vector<string> result;
        pathHelper(result, "", root);
        return result;
    }

    void pathHelper(vector<string>& result, string path, TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            // leaf node
            path += to_string(root->val);
            result.push_back(path);
            return;
        }
        path = path + to_string(root->val) + "->";

        if (root->left) {
            pathHelper(result, path, root->left);
        }

        if (root->right) {
            pathHelper(result, path, root->right);
        }

    }
};