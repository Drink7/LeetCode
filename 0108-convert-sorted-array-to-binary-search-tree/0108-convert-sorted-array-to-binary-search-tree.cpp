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
        // find the middle element as our root
        // divide and conquer
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        return constructBST(nums, 0, n - 1);
    }

    TreeNode* constructBST(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int middle = start + ((end - start) / 2);
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = constructBST(nums, start, middle - 1);
        root->right = constructBST(nums, middle + 1, end);
        return root;
    }
};