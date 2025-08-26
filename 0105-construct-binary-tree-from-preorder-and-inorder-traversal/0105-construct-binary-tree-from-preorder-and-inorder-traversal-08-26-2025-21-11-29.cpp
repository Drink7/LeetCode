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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // TC: O(n^2)
        // SC: O(n)
        return buildHelper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, int preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preIndex];
        TreeNode* root = new TreeNode(rootVal);


        int index = inStart;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                index = i;
                break;
            }
        }

        root->left = buildHelper(preorder, inorder, preIndex + 1, inStart, index - 1);
        root->right = buildHelper(preorder, inorder, preIndex + (index - 1 - inStart + 1) + 1, index + 1, inEnd);
        return root;
    }
};