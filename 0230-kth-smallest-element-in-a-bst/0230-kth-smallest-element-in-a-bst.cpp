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
        // TC: O(k)
        // SC: O(k)
        kthHelper(root, k);
        return result->val;
    }

    void kthHelper(TreeNode* root, int k) {
        if (root == nullptr) {
            return;
        }

        kthHelper(root->left, k);
        cnt++;
        if (cnt == k) {
            result = root;
            return;
        }
        kthHelper(root->right, k);
    }
private:
    TreeNode* result;
    int cnt = 0;
};