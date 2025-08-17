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
    int kthSmallest(TreeNode* root, int k) {
        // Brute Force
        // TC: O(n)
        // SC: O(n)
        dfs(root, k);
        //return tree[k - 1];
        return kNode->val;
    }
    void dfs(TreeNode* root, int k) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, k);

        cnt++;
        if (cnt == k) {
            kNode = root;
        }
        dfs(root->right, k);
    }
private:
    //vector<int> tree;
    TreeNode* kNode = nullptr;
    int cnt = 0;
};