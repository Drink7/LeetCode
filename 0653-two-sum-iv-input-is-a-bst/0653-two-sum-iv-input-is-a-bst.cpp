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
    bool findTarget(TreeNode* root, int k) {
        // Brute force -> inorder
        // TC: O(n)
        // SC: O(n)
        vector<int> seq;
        treeHelper(root, seq);
        int left = 0;
        int right = seq.size() - 1;
        while (left < right) {
            int sum = seq[left] + seq[right];
            if (sum == k) {
                return true;
            } else if (sum > k) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }

    void treeHelper(TreeNode* root, vector<int>& seq) {
        if (root == nullptr) {
            return;
        }
        treeHelper(root->left, seq);
        seq.push_back(root->val);
        treeHelper(root->right, seq);
    }
};