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
    int sumRootToLeaf(TreeNode* root) {
        // use post-order traversal
        // calculate the sum
        // TC: O(n)
        // SC: O(n)
        string path = "";
        sumHelper(root, path);
        return result;
    }

    void sumHelper(TreeNode* root, string path) {
        if (root == nullptr) {
            return;
        }
        path += root->val + '0';
        sumHelper(root->left, path);
        sumHelper(root->right, path);
        if (root->left == nullptr && root->right == nullptr) {
            calculateSum(path);
        }
    }

    void calculateSum(string path) {
        reverse(path.begin(), path.end());
        int n = path.size();
        for (int i = 0; i < path.size(); i++) {
            result += pow(2, i) * (path[i] - '0');
        }
    }

private:
    int result = 0;
};