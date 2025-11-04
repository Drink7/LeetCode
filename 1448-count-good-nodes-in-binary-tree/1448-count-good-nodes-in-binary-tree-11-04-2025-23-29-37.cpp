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
    int goodNodes(TreeNode* root) {
        // root always good node
        // pass down the max val
        // if cur val > max val, good node
        // pass down max(cur val, max val)
        int cnt = 0;
        dfs(root, root->val, cnt);
        return cnt;
    }

    void dfs(TreeNode* root, int maxVal, int& cnt) {
        if (root == nullptr) {
            return;
        }

        if (root->val >= maxVal) {
            cnt++;
        }
        maxVal = max(maxVal, root->val);
        dfs(root->left, maxVal, cnt);
        dfs(root->right, maxVal, cnt);
    }
};