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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // height-balanced 
        // make the middle nums as root, left part as left subtree, right part as right subtree
        // recusive convertion
        // TC: O(n)
        // SC: O(n)
        return convert(nums, 0, nums.size() - 1);
    }

    TreeNode* convert(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = convert(nums, left, mid - 1);
        root->right = convert(nums, mid + 1, right);
        return root;
    }    
};