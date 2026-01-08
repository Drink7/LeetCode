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
        vector<string> result;
        string path = "";
        if (!root) {
            return result;
        }

        pathHelper(result, root, path);
        return result;
    }

    void pathHelper(vector<string>& result, TreeNode* root, string path) {
        path += to_string(root->val);

        if (!root->left && !root->right) {
            result.push_back(path);
            return;
        }
        
        path += "->";

        if (root->left) {
            pathHelper(result, root->left, path);
        }

        if (root->right) {
            pathHelper(result, root->right, path);
        }
    }
};