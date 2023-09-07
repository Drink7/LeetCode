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
        // use preorder with current path
        // TC: O(n)
        // SC: O(1)
        vector<string> result;
        pathHelper(root, result, "");
        return result;
    }

    void pathHelper(TreeNode* node, vector<string>& result, string path) {
        if (node == nullptr) {
            return;
        }

        path += to_string(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            // leaf node
            result.push_back(path);
            return;
        }

        pathHelper(node->left, result, path + "->");
        pathHelper(node->right, result, path + "->");
    }
};