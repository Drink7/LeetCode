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
        cnt = k;
        kHelper(root);
        return result;
    }

    void kHelper(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
    
        kHelper(root->left);
        cnt--;
        if(cnt == 0) {
            result = root->val;
            return;
        }
        kHelper(root->right);
    }
private:
    int cnt = 0;
    int result = -1;
};